/**
 * Problem: Maximum Alternating Sum of Squares (Medium)
 * Language: C++
 *
 * Description:
 * You are given an integer array `nums`. You may **rearrange the elements** in any order.
 * 
 * The **alternating score** of an array `arr` is defined as:
 * 
 * 	• `score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...`
 * 
 * Return an integer denoting the **maximum possible alternating score** of `nums` after rearranging its elements.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [1,2,3]
 * 
 * **Output:** 12
 * 
 * **Explanation:**
 * 
 * A possible rearrangement for `nums` is `[2,1,3]`, which gives the maximum alternating score among all possible rearrangements.
 * 
 * The alternating score is calculated as:
 * 
 * `score = 22 - 12 + 32 = 4 - 1 + 9 = 12`
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [1,-1,2,-2,3,-3]
 * 
 * **Output:** 16
 * 
 * **Explanation:**
 * 
 * A possible rearrangement for `nums` is `[-3,-1,-2,1,3,2]`, which gives the maximum alternating score among all possible rearrangements.
 * 
 * The alternating score is calculated as:
 * 
 * `score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16`
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 5`
 * 
 * 	• `-4 * 104 4`
 */

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares;
        squares.reserve(n);
        
        for (int num : nums) {
            squares.push_back((long long)num * num);
        }
        
        // Sort squares in ascending order
        sort(squares.begin(), squares.end());
        
        long long score = 0;
        int negCount = n / 2;
        
        // The first 'negCount' elements are the smallest, so they get the negative sign
        for (int i = 0; i < negCount; ++i) {
            score -= squares[i];
        }
        
        // The remaining elements are the largest, so they get the positive sign
        for (int i = negCount; i < n; ++i) {
            score += squares[i];
        }
        
        return score;
    }
};
