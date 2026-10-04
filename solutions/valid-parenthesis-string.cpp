/**
 * Problem: Valid Parenthesis String (Medium)
 * Language: C++
 *
 * Description:
 * Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` *if* `s` *is **valid***.
 * 
 * The following rules define a **valid** string:
 * 
 * 	• Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
 * 
 * 	• Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
 * 
 * 	• Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
 * 
 * 	• `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "()"
 * **Output:** true
 * 
 * **Example 2:**
 * 
 * **Input:** s = "(*)"
 * **Output:** true
 * 
 * **Example 3:**
 * 
 * **Input:** s = "(*))"
 * **Output:** true
 * 
 * **Example 4:**
 * 
 * **Input:** s = "("
 * **Output:** false
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= s.length <= 100`
 * 
 * 	• `s[i]` is `'('`, `')'` or `'*'`.
 */

class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--;
                max_open++;
            }
            
            // If max_open is negative, there are too many ')'
            if (max_open < 0) {
                return false;
            }
            
            // If min_open is negative, reset to 0
            if (min_open < 0) {
                min_open = 0;
            }
        }
        
        return min_open == 0;
    }
};
