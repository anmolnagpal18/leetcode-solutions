/**
 * Problem: N-Queens (Hard)
 * Language: C++
 *
 * Description:
 * The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.
 * 
 * Given an integer `n`, return *all distinct solutions to the **n-queens puzzle***. You may return the answer in **any order**.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** n = 4
 * **Output:** [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * **Explanation:** There exist two distinct solutions to the 4-queens puzzle as shown above
 * 
 * **Example 2:**
 * 
 * **Input:** n = 1
 * **Output:** [["Q"]]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= n <= 9`
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queenPos(n, -1);          // queenPos[row] = column
        int all = (1 << n) - 1;               // mask with lowest n bits set

        function<void(int,int,int,int)> dfs = [&](int row, int cols, int diag1, int diag2) {
            if (row == n) {
                // build board
                vector<string> board(n, string(n, '.'));
                for (int r = 0; r < n; ++r) board[r][queenPos[r]] = 'Q';
                ans.push_back(move(board));
                return;
            }
            int available = (~(cols | diag1 | diag2)) & all;
            while (available) {
                int bit = available & -available;          // lowest set bit
                int col = __builtin_ctz(bit);               // column index
                queenPos[row] = col;
                // place queen and move to next row
                dfs(row + 1,
                    cols | bit,
                    (diag1 | bit) << 1,
                    (diag2 | bit) >> 1);
                // backtrack
                queenPos[row] = -1;
                available &= available - 1;                // clear lowest set bit
            }
        };

        dfs(0, 0, 0, 0);
        return ans;
    }
};
