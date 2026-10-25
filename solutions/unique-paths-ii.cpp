/**
 * Problem: Unique Paths II (Medium)
 * Language: C++
 *
 * Description:
 * You are given an `m x n` integer array `grid`. There is a robot initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.
 * 
 * An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include **any** square that is an obstacle.
 * 
 * Return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.
 * 
 * The testcases are generated so that the answer will be less than or equal to `2 * 109`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * **Output:** 2
 * **Explanation:** There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * **Example 2:**
 * 
 * **Input:** obstacleGrid = [[0,1],[0,0]]
 * **Output:** 1
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `m == obstacleGrid.length`
 * 
 * 	• `n == obstacleGrid[i].length`
 * 
 * 	• `1 <= m, n <= 100`
 * 
 * 	• `obstacleGrid[i][j]` is `0` or `1`.
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If start or end is an obstacle, no path exists
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        
        // dp[j] represents the number of ways to reach the current row's j-th column
        vector<int> dp(n, 0);
        dp[0] = 1; // Starting point
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle blocks all paths to this cell
                } else {
                    if (j > 0) {
                        // Add paths from the left (dp[j-1] is already updated for current row)
                        dp[j] += dp[j-1];
                    }
                    // If j == 0, dp[0] remains as is (carries value from above)
                }
            }
        }
        
        return dp[n-1];
    }
};
