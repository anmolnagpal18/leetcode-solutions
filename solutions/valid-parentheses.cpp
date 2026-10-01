/**
 * Problem: Valid Parentheses (Easy)
 * Language: C++
 *
 * Description:
 * Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 	1. $1
 * 
 * 	2. $1
 * 
 * 	3. $1
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "()"
 * 
 * **Output:** true
 * 
 * **Example 2:**
 * 
 * **Input:** s = "()[]{}"
 * 
 * **Output:** true
 * 
 * **Example 3:**
 * 
 * **Input:** s = "(]"
 * 
 * **Output:** false
 * 
 * **Example 4:**
 * 
 * **Input:** s = "([])"
 * 
 * **Output:** true
 * 
 * **Example 5:**
 * 
 * **Input:** s = "([)]"
 * 
 * **Output:** false
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 4`
 * 
 * 	• `s` consists of parentheses only `'()[]{}'`.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        return st.empty();
    }
};
