/**
 * Problem: Palindromic Path Queries in a Tree (Hard)
 * Language: C++
 *
 * Description:
 * You are given an undirected tree with `n` nodes labeled 0 to `n - 1`. This is represented by a 2D array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates an undirected edge between nodes `ui` and `vi`.
 * 
 * You are also given a string `s` of length `n` consisting of lowercase English letters, where `s[i]` represents the character assigned to node `i`.
 * 
 * You are also given a string array `queries`, where each `queries[i]` is either:
 * 
 * 	• `"update ui c"`: Change the character at node `ui` to `c`. Formally, update `s[ui] = c`.
 * 
 * 	• `"query ui vi"`: Determine whether the string formed by the characters on the **unique** path from `ui` to `vi` (inclusive) can be **rearranged** into a **palindrome**.
 * 
 * Return a boolean array `answer`, where `answer[j]` is `true` if the `jth` query of type `"query ui vi"​​​​​​​` can be rearranged into a **palindrome**, and `false` otherwise.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]
 * 
 * **Output:** [true,false]
 * 
 * **Explanation:**
 * 
 * 	• `"query 0 2"`: Path `0 &rarr; 1 &rarr; 2` gives `"aac"`, which can be rearranged to form `"aca"`, a palindrome. Thus, `answer[0] = true`.
 * 
 * 	• `"update 1 b"`: Update node 1 to `'b'`, now `s = "abc"`.
 * 
 * 	• `"query 0 2"`: Path characters are `"abc"`, which cannot be rearranged to form a palindrome. Thus, `answer[1] = false`.
 * 
 * Thus, `answer = [true, false]`.
 * 
 * **Example 2:**
 * 
 * **Input:** n = 4, edges = [[0,1],[0,2],[0,3]], s = "abca", queries = ["query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"]
 * 
 * **Output:** [false,false,true]
 * 
 * **Explanation:**
 * 
 * 	• `"query 1 2"`: Path `1 &rarr; 0 &rarr; 2` gives `"bac"`, which cannot be rearranged to form a palindrome. Thus, `answer[0] = false`.
 * 
 * 	• `"update 0 b"`: Update node 0 to `'b'`, now `s = "bbca"`.
 * 
 * 	• `"query 2 3"`: Path `2 &rarr; 0 &rarr; 3` gives `"cba"`, which cannot be rearranged to form a palindrome. Thus, `answer[1] = false`.
 * 
 * 	• `"update 3 a"`: Update node 3 to `'a'`, `s = "bbca"`.
 * 
 * 	• `"query 1 3"`: Path `1 &rarr; 0 &rarr; 3` gives `"bba"`, which can be rearranged to form `"bab"`, a palindrome. Thus, `answer[2] = true`.
 * 
 * Thus, `answer = [false, false, true]`.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 4`
 * 
 * 	• `edges.length == n - 1`
 * 
 * 	• `edges[i] = [ui, vi]`
 * 
 * 	• `0 i, vi 4`​​​​​​​
 * 	
 * 		`queries[i] = "update ui c"` or
 * 
 * 		• `queries[i] = "query ui vi"`
 * 
 * 		• `0 i, vi
 */

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // HLD Preprocessing
        vector<int> parent(n, -1), depth(n, 0), size(n, 1), heavy(n, -1);
        vector<int> head(n), pos(n), invPos(n);
        int curPos = 0;

        // DFS 1: Compute size, parent, depth, heavy child
        function<void(int, int)> dfs1 = [&](int u, int p) {
            parent[u] = p;
            size[u] = 1;
            int maxSubtreeSize = 0;
            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs1(v, u);
                size[u] += size[v];
                if (size[v] > maxSubtreeSize) {
                    maxSubtreeSize = size[v];
                    heavy[u] = v;
                }
            }
        };
        dfs1(0, -1);

        // DFS 2: Assign head and position
        function<void(int, int)> dfs2 = [&](int u, int h) {
            head[u] = h;
            pos[u] = curPos;
            invPos[curPos] = u;
            curPos++;
            if (heavy[u] != -1) {
                dfs2(heavy[u], h);
            }
            for (int v : adj[u]) {
                if (v == parent[u] || v == heavy[u]) continue;
                dfs2(v, v);
            }
        };
        dfs2(0, 0);

        // Segment Tree for XOR of bitmasks
        vector<int> segTree(4 * n, 0);
        
        // Function to get bitmask for a character
        auto getMask = [](char c) {
            return 1 << (c - 'a');
        };

        // Build segment tree
        function<void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                int u = invPos[l];
                segTree[node] = getMask(s[u]);
                return;
            }
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
        };
        build(1, 0, n - 1);

        // Update segment tree
        function<void(int, int, int, int, int)> update = [&](int node, int l, int r, int idx, int val) {
            if (l == r) {
                segTree[node] = val;
                return;
            }
            int mid = (l + r) / 2;
            if (idx <= mid) {
                update(2 * node, l, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, r, idx, val);
            }
            segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
        };

        // Query segment tree for XOR in range [l, r]
        function<int(int, int, int, int, int)> query = [&](int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return 0;
            if (ql <= l && r <= qr) return segTree[node];
            int mid = (l + r) / 2;
            return query(2 * node, l, mid, ql, qr) ^ query(2 * node + 1, mid + 1, r, ql, qr);
        };

        // HLD Query: Get XOR of path from u to v
        auto pathQuery = [&](int u, int v) {
            int res = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) {
                    swap(u, v);
                }
                res ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            res ^= query(1, 0, n - 1, pos[u], pos[v]);
            return res;
        };

        vector<bool> answer;
        for (string& q : queries) {
            if (q[0] == 'u') { // update
                // Parse "update ui c"
                int ui;
                char c;
                // Simple parsing
                stringstream ss(q);
                string type;
                ss >> type >> ui >> c;
                int newMask = getMask(c);
                update(1, 0, n - 1, pos[ui], newMask);
                s[ui] = c; // Update string for consistency (though not strictly needed if we only use segTree)
            } else { // query
                // Parse "query ui vi"
                int ui, vi;
                stringstream ss(q);
                string type;
                ss >> type >> ui >> vi;
                int mask = pathQuery(ui, vi);
                // Check if mask has at most one bit set
                bool isPalindrome = (mask == 0) || ((mask & (mask - 1)) == 0);
                answer.push_back(isPalindrome);
            }
        }

        return answer;
    }
};
