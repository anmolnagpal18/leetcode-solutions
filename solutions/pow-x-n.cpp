/**
 * Problem: Pow(x, n) (Medium)
 * Language: C++
 *
 * Description:
 * Implement pow(x, n), which calculates `x` raised to the power `n` (i.e., `xn`).
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** x = 2.00000, n = 10
 * **Output:** 1024.00000
 * 
 * **Example 2:**
 * 
 * **Input:** x = 2.10000, n = 3
 * **Output:** 9.26100
 * 
 * **Example 3:**
 * 
 * **Input:** x = 2.00000, n = -2
 * **Output:** 0.25000
 * **Explanation:** 2-2 = 1/22 = 1/4 = 0.25
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `-100.0 31 31-1`
 * 
 * 	• `n` is an integer.
 * 
 * 	• Either `x` is not zero or `n > 0`.
 * 
 * 	• `-104 n 4`
 */

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? fastPow(x, N) : 1.0 / fastPow(x, -N);
    }

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        
        double half = fastPow(x, n >> 1);
        
        if (n & 1) {
            return x * half * half;
        } else {
            return half * half;
        }
    }
};
