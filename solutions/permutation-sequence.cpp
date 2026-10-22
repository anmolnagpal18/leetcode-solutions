/**
 * Problem: Permutation Sequence (Hard)
 * Language: C++
 *
 * Description:
 * The set `[1, 2, 3, ..., n]` contains a total of `n!` unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the following sequence for `n = 3`:
 * 
 * 	1. $1
 * 
 * 	2. $1
 * 
 * 	3. $1
 * 
 * 	4. $1
 * 
 * 	5. $1
 * 
 * 	6. $1
 * 
 * Given `n` and `k`, return the `kth` permutation sequence.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** n = 3, k = 3
 * **Output:** "213"
 * 
 * **Example 2:**
 * 
 * **Input:** n = 4, k = 9
 * **Output:** "2314"
 * 
 * **Example 3:**
 * 
 * **Input:** n = 3, k = 1
 * **Output:** "123"
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= n <= 9`
 * 
 * 	• `1 <= k <= n!`
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // factorials
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

        // numbers to pick from
        vector<int> nums;
        for (int i = 1; i <= n; ++i) nums.push_back(i);

        // convert k to zero‑based index
        k--;  

        string ans;
        for (int i = n; i >= 1; --i) {
            int idx = k / fact[i - 1];          // which number to take
            ans.push_back('0' + nums[idx]);    // append digit
            nums.erase(nums.begin() + idx);    // remove it
            k %= fact[i - 1];                   // remaining offset
        }
        return ans;
    }
};
