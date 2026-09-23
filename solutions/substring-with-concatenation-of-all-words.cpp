/**
 * Problem: Substring with Concatenation of All Words (Hard)
 * Language: C++
 *
 * Description:
 * You are given a string `s` and an array of strings `words`. All the strings of `words` are of **the same length**.
 * 
 * A **concatenated string** is a string that exactly contains all the strings of any permutation of `words` concatenated.
 * 
 * 	• For example, if `words = ["ab","cd","ef"]`, then `"abcdef"`, `"abefcd"`, `"cdabef"`, `"cdefab"`, `"efabcd"`, and `"efcdab"` are all concatenated strings. `"acdbef"` is not a concatenated string because it is not the concatenation of any permutation of `words`.
 * 
 * Return an array of *the starting indices* of all the concatenated substrings in `s`. You can return the answer in **any order**.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** s = "barfoothefoobarman", words = ["foo","bar"]
 * 
 * **Output:** [0,9]
 * 
 * **Explanation:**
 * 
 * The substring starting at 0 is `"barfoo"`. It is the concatenation of `["bar","foo"]` which is a permutation of `words`.
 * The substring starting at 9 is `"foobar"`. It is the concatenation of `["foo","bar"]` which is a permutation of `words`.
 * 
 * **Example 2:**
 * 
 * **Input:** s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * 
 * **Output:** []
 * 
 * **Explanation:**
 * 
 * There is no concatenated substring.
 * 
 * **Example 3:**
 * 
 * **Input:** s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * 
 * **Output:** [6,9,12]
 * 
 * **Explanation:**
 * 
 * The substring starting at 6 is `"foobarthe"`. It is the concatenation of `["foo","bar","the"]`.
 * The substring starting at 9 is `"barthefoo"`. It is the concatenation of `["bar","the","foo"]`.
 * The substring starting at 12 is `"thefoobar"`. It is the concatenation of `["the","foo","bar"]`.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 4`
 * 
 * 	• `1 <= words.length <= 5000`
 * 
 * 	• `1 <= words[i].length <= 30`
 * 
 * 	• `s` and `words[i]` consist of lowercase English letters.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int len = words[0].size();          // length of each word
        int k   = words.size();             // number of words
        long long total = 1LL * len * k;    // total length of concatenation
        if (s.size() < total) return ans;

        // frequency of each word we need
        unordered_map<string, int> need;
        for (const string& w : words) ++need[w];

        // try every possible offset modulo len
        for (int off = 0; off < len; ++off) {
            unordered_map<string, int> have;
            int left = off;          // start of current window
            int cnt  = 0;            // number of words inside window

            // walk through the string block by block
            for (int right = off; right + len <= (int)s.size(); right += len) {
                string w = s.substr(right, len);

                // word not needed → reset window
                if (need.find(w) == need.end()) {
                    have.clear();
                    cnt = 0;
                    left = right + len;
                    continue;
                }

                // add word to window
                ++have[w];
                ++cnt;

                // shrink window while we have too many of w
                while (have[w] > need[w]) {
                    string leftWord = s.substr(left, len);
                    --have[leftWord];
                    --cnt;
                    left += len;
                }

                // window size matches exactly k words → record answer
                if (cnt == k) {
                    ans.push_back(left);
                    // move left one word forward to look for next possible answer
                    string leftWord = s.substr(left, len);
                    --have[leftWord];
                    --cnt;
                    left += len;
                }
            }
        }
        return ans;
    }
};
