/**
 * Problem: Count Islands With Total Value Divisible by K (Medium)
 * Language: C++
 *
 * Description:
 * You are given an `m x n` matrix `grid` and a positive integer `k`. An **island** is a group of **positive** integers (representing land) that are **4-directionally** connected (horizontally or vertically).
 * 
 * The **total value** of an island is the sum of the values of all cells in the island.
 * 
 * Return the number of islands with a total value **divisible by** `k`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
 * 
 * **Output:** 2
 * 
 * **Explanation:**
 * 
 * The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.
 * 
 * **Example 2:**
 * 
 * **Input:** grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
 * 
 * **Output:** 6
 * 
 * **Explanation:**
 * 
 * The grid contains six islands, each with a total value that is divisible by 3.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `m == grid.length`
 * 
 * 	• `n == grid[i].length`
 * 
 * 	• `1 5`
 * 
 * 	• `0 6`
 * 
 * 	• `1 6`
 */

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // Directions for 4-directional movement: up, down, left, right
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        // Lambda function for DFS
        function<void(int, int, long long&)> dfs = [&](int r, int c, long long& sum) {
            // Base case: out of bounds or not land (0)
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
                return;
            }
            
            // Add current cell's value to the sum
            sum += grid[r][c];
            
            // Mark as visited by setting to 0
            grid[r][c] = 0;
            
            // Explore neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];
                dfs(nr, nc, sum);
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find a positive number, it's the start of a new island
                if (grid[i][j] > 0) {
                    long long sum = 0;
                    dfs(i, j, sum);
                    
                    // Check if the sum is divisible by k
                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
