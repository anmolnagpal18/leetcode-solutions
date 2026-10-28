/**
 * Problem: Minimum XOR Path in a Grid (Medium)
 * Language: C++
 *
 * Description:
 * You are given a 2D integer array `grid` of size `m * n`.
 * 
 * You start at the **top-left** cell `(0, 0)` and want to reach the **bottom-right** cell `(m - 1, n - 1)`.
 * 
 * At each step, you **may** move either **right or down**.
 * 
 * The **cost** of a path is defined as the **bitwise XOR** of all the values in the cells along that path, **including** the start and end cells.
 * 
 * Return the **minimum** possible XOR value among all valid paths from `(0, 0)` to `(m - 1, n - 1)`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** grid = [[1,2],[3,4]]
 * 
 * **Output:** 6
 * 
 * **Explanation:**
 * 
 * There are two valid paths:
 * 
 * 	• `(0, 0) &rarr; (0, 1) &rarr; (1, 1)` with XOR: `1 XOR 2 XOR 4 = 7`
 * 
 * 	• `(0, 0) &rarr; (1, 0) &rarr; (1, 1)` with XOR: `1 XOR 3 XOR 4 = 6`
 * 
 * The minimum XOR value among all valid paths is 6.
 * 
 * **Example 2:**
 * 
 * **Input:** grid = [[6,7],[5,8]]
 * 
 * **Output:** 9
 * 
 * **Explanation:**
 * 
 * There are two valid paths:
 * 
 * 	• `(0, 0) &rarr; (0, 1) &rarr; (1, 1)` with XOR: `6 XOR 7 XOR 8 = 9`
 * 
 * 	• `(0, 0) &rarr; (1, 0) &rarr; (1, 1)` with XOR: `6 XOR 5 XOR 8 = 11`
 * 
 * The minimum XOR value among all valid paths is 9.
 * 
 * **Example 3:**
 * 
 * **Input:** grid = [[2,7,5]]
 * 
 * **Output:** 0
 * 
 * **Explanation:**
 * 
 * There is only one valid path:
 * 
 * 	• `(0, 0) &rarr; (0, 1) &rarr; (0, 2)` with XOR: `2 XOR 7 XOR 5 = 0`
 * 
 * The XOR value of this path is 0, which is the minimum possible.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= m == grid.length <= 1000`
 * 
 * 	• `1 <= n == grid[i].length <= 1000`
 * 
 * 	• `m * n <= 1000`
 * 
 * 	• `0 <= grid[i][j] <= 1023​`
 */

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] is a bitset where bit k is 1 if XOR value k is achievable at cell (i, j)
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        
        // Initialize the start cell
        dp[0][0].set(grid[0][0]);
        
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < 1024; ++k) {
                if (dp[0][j-1].test(k)) {
                    dp[0][j].set(k ^ grid[0][j]);
                }
            }
        }
        
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            for (int k = 0; k < 1024; ++k) {
                if (dp[i-1][0].test(k)) {
                    dp[i][0].set(k ^ grid[i][0]);
                }
            }
        }
        
        // Fill the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // From top
                for (int k = 0; k < 1024; ++k) {
                    if (dp[i-1][j].test(k)) {
                        dp[i][j].set(k ^ grid[i][j]);
                    }
                }
                // From left
                for (int k = 0; k < 1024; ++k) {
                    if (dp[i][j-1].test(k)) {
                        dp[i][j].set(k ^ grid[i][j]);
                    }
                }
            }
        }
        
        // Find the minimum XOR value at the bottom-right cell
        for (int k = 0; k < 1024; ++k) {
            if (dp[m-1][n-1].test(k)) {
                return k;
            }
        }
        
        return -1; // Should never reach here
    }
};
