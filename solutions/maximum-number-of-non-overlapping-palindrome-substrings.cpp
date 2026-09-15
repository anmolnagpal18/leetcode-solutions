/**
 * Problem: Maximum Number of Non-overlapping Palindrome Substrings (Hard)
 * Language: C++
 *
 * Description:
 * You are given a string `s` and a **positive** integer `k`.
 * 
 * Select a set of **non-overlapping** substrings from the string `s` that satisfy the following conditions:
 * 
 * 	• The **length** of each substring is **at least** `k`.
 * 
 * 	• Each substring is a **palindrome**.
 * 
 * Return *the **maximum** number of substrings in an optimal selection*.
 * 
 * A **substring** is a contiguous sequence of characters within a string.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "abaccdbbd", k = 3
 * **Output:** 2
 * **Explanation:** We can select the substrings underlined in s = "**aba**cc**dbbd**". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
 * It can be shown that we cannot find a selection with more than two valid substrings.
 * 
 * **Example 2:**
 * 
 * **Input:** s = "adbcda", k = 2
 * **Output:** 0
 * **Explanation:** There is no palindrome substring of length at least 2 in the string.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= k <= s.length <= 2000`
 * 
 * 	• `s` consists of lowercase English letters.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = (int)s.size();
        // dp[i] = best answer for prefix s[0..i-1]
        vector<int> dp(n + 1, 0);
        // flatten 2‑D bool table: index = left * n + right
        vector<char> pal(n * n, 0);

        // ---- 1. enumerate all palindromes of length >= k ----
        for (int center = 0; center < n; ++center) {
            // odd length
            for (int l = 0; center - l >= 0 && center + l < n; ++l) {
                if (s[center - l] != s[center + l]) break;
                int left = center - l, right = center + l;
                if (right - left + 1 >= k)
                    pal[left * n + right] = 1;
            }
            // even length
            for (int l = 0; center - l >= 0 && center + 1 + l < n; ++l) {
                if (s[center - l] != s[center + 1 + l]) break;
                int left = center - l, right = center + 1 + l;
                if (right - left + 1 >= k)
                    pal[left * n + right] = 1;
            }
        }

        // ---- 2. DP for maximum non‑overlapping count ----
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i];                     // skip s[i]
            for (int j = 0; j <= i; ++j) {         // try a palindrome [j, i]
                if (pal[j * n + i]) {
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp[n];
    }
};
