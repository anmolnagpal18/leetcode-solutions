/**
 * Problem: Minimum Insertions to Balance a Parentheses String (Medium)
 * Language: C++
 *
 * Description:
 * Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is **balanced** if:
 * 
 * 	• Any left parenthesis `'('` must have a corresponding two consecutive right parenthesis `'))'`.
 * 
 * 	• Left parenthesis `'('` must go before the corresponding two consecutive right parenthesis `'))'`.
 * 
 * In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.
 * 
 * 	• For example, `"())"`, `"())(())))"` and `"(())())))"` are balanced, `")()"`, `"()))"` and `"(()))"` are not balanced.
 * 
 * You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.
 * 
 * Return *the minimum number of insertions* needed to make `s` balanced.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "(()))"
 * **Output:** 1
 * **Explanation:** The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.
 * 
 * **Example 2:**
 * 
 * **Input:** s = "())"
 * **Output:** 0
 * **Explanation:** The string is already balanced.
 * 
 * **Example 3:**
 * 
 * **Input:** s = "))())("
 * **Output:** 3
 * **Explanation:** Add '(' to match the first '))', Add '))' to match the last '('.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 5`
 * 
 * 	• `s` consists of `'('` and `')'` only.
 */

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int insertions = 0;
        
        for (int i = 0; i < n; ) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                // s[i] is ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    // We have a pair "))"
                    // This pair can match one '('
                    if (open > 0) {
                        open--;
                    } else {
                        // No '(' to match, need to insert one '('
                        insertions++;
                    }
                    i += 2; // Skip both ')'
                } else {
                    // We have a single ')'
                    // Need to insert one ')' to make it "))"
                    insertions++;
                    
                    // Now we have a virtual "))" pair
                    if (open > 0) {
                        open--;
                    } else {
                        // No '(' to match, need to insert one '('
                        insertions++;
                    }
                    i++; // Skip only one ')'
                }
            }
        }
        
        // Each remaining '(' needs two ')' to be balanced
        insertions += 2 * open;
        
        return insertions;
    }
};
