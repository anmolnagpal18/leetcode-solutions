/**
 * Problem:  Check if There Is a Valid Parentheses String Path (Hard)
 * Language: C++
 *
 * Description:
 * A parentheses string is a **non-empty** string consisting only of `'('` and `')'`. It is **valid** if **any** of the following conditions is **true**:
 * 
 * 	• It is `()`.
 * 
 * 	• It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid parentheses strings.
 * 
 * 	• It can be written as `(A)`, where `A` is a valid parentheses string.
 * 
 * You are given an `m x n` matrix of parentheses `grid`. A **valid parentheses string path** in the grid is a path satisfying **all** of the following conditions:
 * 
 * 	• The path starts from the upper left cell `(0, 0)`.
 * 
 * 	• The path ends at the bottom-right cell `(m - 1, n - 1)`.
 * 
 * 	• The path only ever moves **down** or **right**.
 * 
 * 	• The resulting parentheses string formed by the path is **valid**.
 * 
 * Return `true` *if there exists a **valid parentheses string path** in the grid.* Otherwise, return `false`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
 * **Output:** true
 * **Explanation:** The above diagram shows two possible paths that form valid parentheses strings.
 * The first path shown results in the valid parentheses string "()(())".
 * The second path shown results in the valid parentheses string "((()))".
 * Note that there may be other valid parentheses string paths.
 * 
 * **Example 2:**
 * 
 * **Input:** grid = [[")",")"],["(","("]]
 * **Output:** false
 * **Explanation:** The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `m == grid.length`
 * 
 * 	• `n == grid[i].length`
 * 
 * 	• `1 <= m, n <= 100`
 * 
 * 	• `grid[i][j]` is either `'('` or `')'`.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalLen = m + n - 1;                 // number of cells on any path
        if (totalLen % 2 != 0) return false;      // odd length can never be balanced

        int maxBalance = totalLen / 2;            // at most this many '(' can appear

        // dp[i][j][k] = reachable with balance k at cell (i,j)
        vector<vector<vector<char>>> dp(
            m, vector<vector<char>>(n, vector<char>(maxBalance + 1, 0)));

        // start cell must be '('
        if (grid[0][0] != '(') return false;
        dp[0][0][1] = 1;   // balance = 1 after first '('

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;   // already initialised

                for (int bal = 0; bal <= maxBalance; ++bal) {
                    // from top
                    if (i > 0 && dp[i-1][j][bal]) {
                        if (grid[i][j] == '(') {
                            if (bal + 1 <= maxBalance) dp[i][j][bal+1] = 1;
                        } else { // ')'
                            if (bal > 0) dp[i][j][bal-1] = 1;
                        }
                    }
                    // from left
                    if (j > 0 && dp[i][j-1][bal]) {
                        if (grid[i][j] == '(') {
                            if (bal + 1 <= maxBalance) dp[i][j][bal+1] = 1;
                        } else { // ')'
                            if (bal > 0) dp[i][j][bal-1] = 1;
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};
