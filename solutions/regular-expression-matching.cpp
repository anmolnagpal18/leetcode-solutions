/**
 * Problem: Regular Expression Matching (Hard)
 * Language: C++
 *
 * Description:
 * Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:
 * 
 * 	• `'.'` Matches any single character.​​​​
 * 
 * 	• `'*'` Matches zero or more of the preceding element.
 * 
 * Return a boolean indicating whether the matching covers the entire input string (not partial).
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "aa", p = "a"
 * **Output:** false
 * **Explanation:** "a" does not match the entire string "aa".
 * 
 * **Example 2:**
 * 
 * **Input:** s = "aa", p = "a*"
 * **Output:** true
 * **Explanation:** '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * **Example 3:**
 * 
 * **Input:** s = "ab", p = ".*"
 * **Output:** true
 * **Explanation:** ".*" means "zero or more (*) of any character (.)".
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= s.length <= 20`
 * 
 * 	• `1 <= p.length <= 20`
 * 
 * 	• `s` contains only lowercase English letters.
 * 
 * 	• `p` contains only lowercase English letters, `'.'`, and `'*'`.
 * 
 * 	• It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] means s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns that can match empty string (e.g., "a*", ".*")
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // Two cases:
                    // 1. '*' matches zero occurrences: ignore p[j-2] and p[j-1]
                    // 2. '*' matches one or more occurrences: 
                    //    p[j-2] must match s[i-1], and s[0..i-2] must match p[0..j-1]
                    dp[i][j] = dp[i][j - 2] || 
                               ((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j]);
                } else {
                    // Normal case: current characters must match
                    if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};
