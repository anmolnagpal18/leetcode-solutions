/**
 * Problem: Wildcard Matching (Hard)
 * Language: C++
 *
 * Description:
 * Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:
 * 
 * 	• `'?'` Matches any single character.
 * 
 * 	• `'*'` Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the **entire** input string (not partial).
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
 * **Input:** s = "aa", p = "*"
 * **Output:** true
 * **Explanation:** '*' matches any sequence.
 * 
 * **Example 3:**
 * 
 * **Input:** s = "cb", p = "?a"
 * **Output:** false
 * **Explanation:** '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `0 <= s.length, p.length <= 2000`
 * 
 * 	• `s` contains only lowercase English letters.
 * 
 * 	• `p` contains only lowercase English letters, `'?'` or `'*'`.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0;               // indices for s and p
        int starIdx = -1;               // last position of '*' in p
        int matchIdx = 0;               // position in s that '*' is currently matching

        while (i < n) {
            if (j < m && (p[j] == '?' || p[j] == s[i])) {
                // direct match
                ++i; ++j;
            } else if (j < m && p[j] == '*') {
                // remember star position and the match start in s
                starIdx = j;
                matchIdx = i;
                ++j; // treat '*' as matching empty sequence for now
            } else if (starIdx != -1) {
                // mismatch but we have a previous '*', backtrack
                j = starIdx + 1;   // pattern after '*'
                ++matchIdx;        // let '*' consume one more char
                i = matchIdx;      // restart matching from new position
            } else {
                // mismatch and no previous '*'
                return false;
            }
        }

        // skip trailing '*' in pattern
        while (j < m && p[j] == '*') ++j;

        return j == m;
    }
};
