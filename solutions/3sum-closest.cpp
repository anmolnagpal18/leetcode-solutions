/**
 * Problem: 3Sum Closest (Medium)
 * Language: C++
 *
 * Description:
 * You are given an integer array `nums` of length `n` and an integer `target`.
 * 
 * Find three integers at **distinct indices** in `nums` such that the sum is **closest** to `target`.
 * 
 * Return the sum of the three integers.
 * 
 * You may assume that each input would have **exactly** one solution.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [-1,2,1,-4], target = 1
 * **Output:** 2
 * **Explanation:** The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [0,0,0], target = 1
 * **Output:** 0
 * **Explanation:** The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `3 4 4`
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closestSum if currentSum is closer to target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // Exact match found, which is the closest possible
                    return target;
                }
            }
        }
        
        return closestSum;
    }
};
