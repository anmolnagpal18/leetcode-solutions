/**
 * Problem: Divide Two Integers (Medium)
 * Language: C++
 *
 * Description:
 * Given two integers `dividend` and `divisor`, divide two integers **without** using multiplication, division, and mod operator.
 * 
 * The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.
 * 
 * Return *the **quotient** after dividing *`dividend`* by *`divisor`.
 * 
 * **Note: **Assume we are dealing with an environment that could only store integers within the **32-bit** signed integer range: `[&minus;231, 231 &minus; 1]`. For this problem, if the quotient is **strictly greater than** `231 - 1`, then return `231 - 1`, and if the quotient is **strictly less than** `-231`, then return `-231`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** dividend = 10, divisor = 3
 * **Output:** 3
 * **Explanation:** 10/3 = 3.33333.. which is truncated to 3.
 * 
 * **Example 2:**
 * 
 * **Input:** dividend = 7, divisor = -3
 * **Output:** -2
 * **Explanation:** 7/-3 = -2.33333.. which is truncated to -2.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `-231 31 - 1`
 * 
 * 	• `divisor != 0`
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of the result
        bool negative = ( (dividend < 0) ^ (divisor < 0) );

        // Work with positive 64‑bit values to avoid overflow
        long long dvd = std::llabs(static_cast<long long>(dividend));
        long long dvs = std::llabs(static_cast<long long>(divisor));

        long long quotient = 0;

        // Main loop: subtract the largest shifted divisor each time
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            // Find the biggest double of divisor that fits into dividend
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative) quotient = -quotient;

        // Result fits in 32‑bit signed int (except the handled overflow case)
        return static_cast<int>(quotient);
    }
};
