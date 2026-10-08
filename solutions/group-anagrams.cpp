/**
 * Problem: Group Anagrams (Medium)
 * Language: C++
 *
 * Description:
 * Given an array of strings `strs`, group the anagrams together. You can return the answer in **any order**.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** strs = ["eat","tea","tan","ate","nat","bat"]
 * 
 * **Output:** [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * **Explanation:**
 * 
 * 	• There is no string in strs that can be rearranged to form `"bat"`.
 * 
 * 	• The strings `"nat"` and `"tan"` are anagrams as they can be rearranged to form each other.
 * 
 * 	• The strings `"ate"`, `"eat"`, and `"tea"` are anagrams as they can be rearranged to form each other.
 * 
 * **Example 2:**
 * 
 * **Input:** strs = [""]
 * 
 * **Output:** [[""]]
 * 
 * **Example 3:**
 * 
 * **Input:** strs = ["a"]
 * 
 * **Output:** [["a"]]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 4`
 * 
 * 	• `0 <= strs[i].length <= 100`
 * 
 * 	• `strs[i]` consists of lowercase English letters.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        mp.reserve(strs.size() * 2);   // reduce rehashes

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());          // canonical form
            mp[key].push_back(s);                  // group by canonical form
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());
        for (auto& kv : mp) {
            ans.emplace_back(std::move(kv.second));
        }
        return ans;
    }
};
