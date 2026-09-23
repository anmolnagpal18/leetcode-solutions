/**
 * Problem: Minimum Operations to Reduce X to Zero (Medium)
 * Language: C++
 *
 * Description:
 * You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.
 * 
 * Return *the **minimum number** of operations to reduce *`x` *to **exactly*** `0` *if it is possible**, otherwise, return *`-1`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [1,1,4,2,3], x = 5
 * **Output:** 2
 * **Explanation:** The optimal solution is to remove the last two elements to reduce x to zero.
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [5,6,7,8,9], x = 4
 * **Output:** -1
 * 
 * **Example 3:**
 * 
 * **Input:** nums = [3,2,20,1,1,3], x = 10
 * **Output:** 5
 * **Explanation:** The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 5`
 * 
 * 	• `1 4`
 * 
 * 	• `1 9`
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        long long target = totalSum - x;
        
        // If target is negative, it means x is greater than total sum, impossible
        if (target < 0) {
            return -1;
        }
        
        // Special case: if target is 0, we need to remove all elements
        // This corresponds to a subarray of length 0, so operations = n
        // But our sliding window logic handles this if we look for max length subarray with sum 0.
        // However, since nums[i] >= 1, a subarray with sum 0 only exists if length is 0.
        // So maxLen will remain 0, and answer is n - 0 = n.
        
        long long currentSum = 0;
        int left = 0;
        int maxLen = -1; // Initialize to -1 to indicate no valid subarray found yet
        
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            
            // Shrink window from left if currentSum exceeds target
            while (left <= right && currentSum > target) {
                currentSum -= nums[left];
                ++left;
            }
            
            // If currentSum equals target, update max length
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        if (maxLen == -1) {
            return -1;
        }
        
        return n - maxLen;
    }
};
