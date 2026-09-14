/**
 * Problem: Longest Palindromic Substring (Medium)
 * Language: C++
 *
 * Description:
 * Given a string `s`, return *the longest* *palindromic* *substring* in `s`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "babad"
 * **Output:** "bab"
 * **Explanation:** "aba" is also a valid answer.
 * 
 * **Example 2:**
 * 
 * **Input:** s = "cbbd"
 * **Output:** "bb"
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= s.length <= 1000`
 * 
 * 	• `s` consist of only digits and English letters.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 1;
        
        auto expandFromCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            // After the loop, left and right are one step too far
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };
        
        for (int i = 0; i < s.size(); ++i) {
            // Odd length palindromes
            expandFromCenter(i, i);
            // Even length palindromes
            expandFromCenter(i, i + 1);
        }
        
        return s.substr(start, maxLen);
    }
};
