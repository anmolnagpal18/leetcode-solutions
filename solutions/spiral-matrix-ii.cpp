/**
 * Problem: Spiral Matrix II (Medium)
 * Language: C++
 *
 * Description:
 * Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to `n2` in spiral order.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** n = 3
 * **Output:** [[1,2,3],[8,9,4],[7,6,5]]
 * 
 * **Example 2:**
 * 
 * **Input:** n = 1
 * **Output:** [[1]]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= n <= 20`
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        while (top <= bottom && left <= right) {
            // top row
            for (int col = left; col <= right; ++col) {
                mat[top][col] = num++;
            }
            ++top;
            // right column
            for (int row = top; row <= bottom; ++row) {
                mat[row][right] = num++;
            }
            --right;
            // bottom row
            if (top <= bottom) {
                for (int col = right; col >= left; --col) {
                    mat[bottom][col] = num++;
                }
                --bottom;
            }
            // left column
            if (left <= right) {
                for (int row = bottom; row >= top; --row) {
                    mat[row][left] = num++;
                }
                ++left;
            }
        }
        return mat;
    }
};
