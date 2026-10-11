/**
 * Problem: N-Queens II (Hard)
 * Language: C++
 *
 * Description:
 * The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.
 * 
 * Given an integer `n`, return *the number of distinct solutions to the **n-queens puzzle***.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** n = 4
 * **Output:** 2
 * **Explanation:** There are two distinct solutions to the 4-queens puzzle as shown.
 * 
 * **Example 2:**
 * 
 * **Input:** n = 1
 * **Output:** 1
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= n <= 9`
 */

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Initial state: no columns or diagonals are blocked
        // We use 0 as the starting row
        backtrack(n, 0, 0, 0, 0, count);
        return count;
    }

private:
    void backtrack(int n, int row, int cols, int diag1, int diag2, int& count) {
        // Base case: if we have placed queens in all rows
        if (row == n) {
            count++;
            return;
        }

        // available positions: all columns (1..n) minus blocked cols, diag1, diag2
        // (1 << n) - 1 creates a mask with n bits set to 1
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            // Get the lowest set bit (the position of the next available column)
            int pos = available & (-available);
            // Remove this position from available for the next iteration
            available -= pos;

            // Update masks for the next row
            // diag1 shifts left because the diagonal index increases by 1 each row
            // diag2 shifts right because the diagonal index decreases by 1 each row (conceptually)
            // Note: The shift direction depends on how we define the diagonal indices.
            // Standard approach:
            // diag1 (top-left to bottom-right): index = row + col. As row increases, index increases. So we shift left.
            // diag2 (top-right to bottom-left): index = row - col. As row increases, index increases. 
            // However, a common trick is to use bit shifts directly on the mask.
            // Let's stick to the standard bit manipulation logic:
            // If we place a queen at column 'pos' in current 'row':
            // Next row's cols mask: cols | pos
            // Next row's diag1 mask: (diag1 | pos) << 1
            // Next row's diag2 mask: (diag2 | pos) >> 1
            
            backtrack(n, row + 1, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1, count);
        }
    }
};
