/**
 * Problem: Minimum Path Sum (Medium)
 * Language: C++
 *
 * Description:
 * Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
 * 
 * **Note:** You can only move either down or right at any point in time.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** grid = [[1,3,1],[1,5,1],[4,2,1]]
 * **Output:** 7
 * **Explanation:** Because the path 1 &rarr; 3 &rarr; 1 &rarr; 1 &rarr; 1 minimizes the sum.
 * 
 * **Example 2:**
 * 
 * **Input:** grid = [[1,2,3],[4,5,6]]
 * **Output:** 12
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `m == grid.length`
 * 
 * 	• `n == grid[i].length`
 * 
 * 	• `1 <= m, n <= 200`
 * 
 * 	• `0 <= grid[i][j] <= 200`
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);

        // initialise first row
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j)
            dp[j] = dp[j - 1] + grid[0][j];

        // process remaining rows
        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];               // first column of current row
            for (int j = 1; j < n; ++j) {
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
