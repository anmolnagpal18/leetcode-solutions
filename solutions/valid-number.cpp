/**
 * Problem: Valid Number (Hard)
 * Language: C++
 *
 * Description:
 * Given a string `s`, return whether `s` is a **valid number**.
 * 
 * For example, all the following are valid numbers: `"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"`, while the following are not valid numbers: `"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"`.
 * 
 * Formally, a **valid number** is defined using one of the following definitions:
 * 
 * 	1. $1
 * 
 * 	2. $1
 * 
 * An **integer number** is defined with an **optional sign** `'-'` or `'+'` followed by **digits**.
 * 
 * A **decimal number** is defined with an **optional sign** `'-'` or `'+'` followed by one of the following definitions:
 * 
 * 	1. $1
 * 
 * 	2. $1
 * 
 * 	3. $1
 * 
 * An **exponent** is defined with an **exponent notation** `'e'` or `'E'` followed by an **integer number**.
 * 
 * The **digits** are defined as one or more digits.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "0"
 * 
 * **Output:** true
 * 
 * **Example 2:**
 * 
 * **Input:** s = "e"
 * 
 * **Output:** false
 * 
 * **Example 3:**
 * 
 * **Input:** s = "."
 * 
 * **Output:** false
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= s.length <= 20`
 * 
 * 	• `s` consists of only English letters (both uppercase and lowercase), digits (`0-9`), plus `'+'`, minus `'-'`, or dot `'.'`.
 */

class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        if (n == 0) return false;

        // state machine:
        // 0 – start, 1 – sign, 2 – digit(s), 3 – dot (maybe after sign or digits),
        // 4 – exponent letter, 5 – exponent sign, 6 – exponent digit(s)
        int state = 0;
        bool hasDigit = false;      // any digit before exponent
        bool hasExponent = false;   // exponent seen (not used later, kept for clarity)
        bool hasDot = false;        // whether a dot has already appeared

        for (int i = 0; i < n; ++i) {
            char c = s[i];

            if (isdigit(c)) {
                hasDigit = true;
                if (state == 0 || state == 1) {
                    state = 2;                 // first digit after start/sign
                } else if (state == 3) {
                    state = 2;                 // digit after dot
                } else if (state == 4 || state == 5) {
                    state = 6;                 // first exponent digit
                } else if (state == 2 || state == 6) {
                    // stay in same state
                } else {
                    return false;
                }
            } else if (c == '+' || c == '-') {
                if (state == 0) {
                    state = 1;                 // sign at the very beginning
                } else if (state == 4) {
                    state = 5;                 // sign after exponent letter
                } else {
                    return false;
                }
            } else if (c == '.') {
                // a second dot is illegal
                if (hasDot) return false;

                if (state == 0 || state == 1) {
                    state = 3;                 // dot at start (maybe after sign)
                } else if (state == 2) {
                    state = 3;                 // digit(s) then dot
                } else {
                    return false;
                }
                hasDot = true;
            } else if (c == 'e' || c == 'E') {
                // exponent is allowed only after at least one digit.
                // It can also follow a dot provided a digit existed before the dot.
                if (state == 2 || (state == 3 && hasDigit)) {
                    state = 4;
                    hasExponent = true;
                } else {
                    return false;
                }
            } else {
                return false; // illegal character
            }
        }

        // Acceptable ending states:
        // 2 – we ended with a digit,
        // 6 – we ended with exponent digit,
        // 3 – we ended with a dot but only if a digit was seen somewhere.
        if (state == 2 || state == 6 || (state == 3 && hasDigit))
            return true;
        return false;
    }
};
