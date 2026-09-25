/**
 * Problem: Longest Valid Parentheses (Hard)
 * Language: C++
 *
 * Description:
 * Given a string containing just the characters `'('` and `')'`, return *the length of the longest valid (well-formed) parentheses **substring*.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "(()"
 * **Output:** 2
 * **Explanation:** The longest valid parentheses substring is "()".
 * 
 * **Example 2:**
 * 
 * **Input:** s = ")()())"
 * **Output:** 4
 * **Explanation:** The longest valid parentheses substring is "()()".
 * 
 * **Example 3:**
 * 
 * **Input:** s = ""
 * **Output:** 0
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `0 4`
 * 
 * 	• `s[i]` is `'('`, or `')'`.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1); // Base index for length calculation
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // New base index
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        
        return maxLen;
    }
};
