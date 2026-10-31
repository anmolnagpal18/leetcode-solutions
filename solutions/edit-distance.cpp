/**
 * Problem: Edit Distance (Medium)
 * Language: C++
 *
 * Description:
 * Given two strings `word1` and `word2`, return *the minimum number of operations required to convert `word1` to `word2`*.
 * 
 * You have the following three operations permitted on a word:
 * 
 * 	• Insert a character
 * 
 * 	• Delete a character
 * 
 * 	• Replace a character
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** word1 = "horse", word2 = "ros"
 * **Output:** 3
 * **Explanation:** 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * **Example 2:**
 * 
 * **Input:** word1 = "intention", word2 = "execution"
 * **Output:** 5
 * **Explanation:** 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `0 <= word1.length, word2.length <= 500`
 * 
 * 	• `word1` and `word2` consist of lowercase English letters.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // Ensure we use the shorter string for the DP width to minimise memory.
        if (n > m) {
            // swap to make n <= m
            swap(word1, word2);
            swap(m, n);
        }

        vector<int> prev(n + 1), cur(n + 1);
        // dp[0][j] = j
        for (int j = 0; j <= n; ++j) prev[j] = j;

        for (int i = 1; i <= m; ++i) {
            cur[0] = i;                     // dp[i][0] = i
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];   // no operation needed
                } else {
                    cur[j] = 1 + min({prev[j],      // delete
                                      cur[j - 1],   // insert
                                      prev[j - 1]}); // replace
                }
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};
