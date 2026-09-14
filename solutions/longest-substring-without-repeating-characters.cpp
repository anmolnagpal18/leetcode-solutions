/**
 * Problem: Longest Substring Without Repeating Characters (Medium)
 * Language: C++
 *
 * Description:
 * Given a string `s`, find the length of the **longest** **substring** without duplicate characters.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * ```
 * "bca"
 * ```
 * 
 * **Example 2:**
 * 
 * **Input:** s = "bbbbb"
 * **Output:** 1
 * **Explanation:** The answer is "b", with the length of 1.
 * 
 * **Example 3:**
 * 
 * **Input:** s = "pwwkew"
 * **Output:** 3
 * **Explanation:** The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `0 5`
 * 
 * 	• `s` consists of English letters, digits, symbols and spaces.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Map to store the last index of each character
        // Using unordered_map for general characters
        unordered_map<char, int> lastIndex;
        
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            char c = s[right];
            
            // If character is in map and its last index is within current window
            if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= left) {
                // Move left pointer to just after the previous occurrence
                left = lastIndex[c] + 1;
            }
            
            // Update the last seen index of current character
            lastIndex[c] = right;
            
            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
