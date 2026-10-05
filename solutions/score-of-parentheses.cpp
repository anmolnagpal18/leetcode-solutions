/**
 * Problem: Score of Parentheses (Medium)
 * Language: C++
 *
 * Description:
 * Given a balanced parentheses string `s`, return *the **score** of the string*.
 * 
 * The **score** of a balanced parentheses string is based on the following rule:
 * 
 * 	• `"()"` has score `1`.
 * 
 * 	• `AB` has score `A + B`, where `A` and `B` are balanced parentheses strings.
 * 
 * 	• `(A)` has score `2 * A`, where `A` is a balanced parentheses string.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "()"
 * **Output:** 1
 * 
 * **Example 2:**
 * 
 * **Input:** s = "(())"
 * **Output:** 2
 * 
 * **Example 3:**
 * 
 * **Input:** s = "()()"
 * **Output:** 2
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `2 <= s.length <= 50`
 * 
 * 	• `s` consists of only `'('` and `')'`.
 * 
 * 	• `s` is a balanced parentheses string.
 */

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                // If the previous character is '(', we have a "()" pair
                if (i > 0 && s[i-1] == '(') {
                    // Add 2^(depth-1) to the score
                    score += (1 << (depth - 1));
                }
                depth--;
            }
        }
        
        return score;
    }
};
