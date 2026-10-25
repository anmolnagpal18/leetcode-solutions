/**
 * Problem: Number of Closed Islands (Medium)
 * Language: C++
 *
 * Description:
 * Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An *island* is a maximal 4-directionally connected group of `0s` and a *closed island* is an island **totally** (all left, top, right, bottom) surrounded by `1s.`
 * 
 * Return the number of *closed islands*.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * **Output:** 2
 * **Explanation:** 
 * Islands in gray are closed because they are completely surrounded by water (group of 1s).
 * 
 * **Example 2:**
 * 
 * **Input:** grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * **Output:** 1
 * 
 * **Example 3:**
 * 
 * **Input:** grid = [[1,1,1,1,1,1,1],
 *                [1,0,0,0,0,0,1],
 *                [1,0,1,1,1,0,1],
 *                [1,0,1,0,1,0,1],
 *                [1,0,1,1,1,0,1],
 *                [1,0,0,0,0,0,1],
 *                [1,1,1,1,1,1,1]]
 * **Output:** 2
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= grid.length, grid[0].length <= 100`
 * 
 * 	• `0 <= grid[i][j] <=1`
 */

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        // Directions for 4-directional movement
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        // Helper function for DFS
        function<void(int, int, bool&)> dfs = [&](int x, int y, bool& isClosed) {
            // If out of bounds, this island touches the boundary, so it's not closed
            if (x < 0 || x >= m || y < 0 || y >= n) {
                isClosed = false;
                return;
            }
            
            // If current cell is water or already visited, stop
            if (grid[x][y] != 0) {
                return;
            }
            
            // Mark current cell as visited by changing it to 1 (water)
            grid[x][y] = 1;
            
            // Explore all 4 directions
            for (int i = 0; i < 4; ++i) {
                dfs(x + dx[i], y + dy[i], isClosed);
            }
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find an unvisited land cell
                if (grid[i][j] == 0) {
                    bool isClosed = true;
                    dfs(i, j, isClosed);
                    if (isClosed) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
