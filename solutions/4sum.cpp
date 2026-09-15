/**
 * Problem: 4Sum (Medium)
 * Language: C++
 *
 * Description:
 * Given an array `nums` of `n` integers, return *an array of all the **unique** quadruplets* `[nums[a], nums[b], nums[c], nums[d]]` such that:
 * 
 * 	• `0 
 * **Input:** nums = [1,0,-1,0,-2,2], target = 0
 * **Output:** [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [2,2,2,2,2], target = 8
 * **Output:** [[2,2,2,2]]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 9 9`
 * 
 * 	• `-109 9`
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Early termination: if the smallest possible sum with nums[i] is greater than target
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            
            // Early termination: if the largest possible sum with nums[i] is less than target
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                // Early termination: if the smallest possible sum with nums[i] and nums[j] is greater than target
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                
                // Early termination: if the largest possible sum with nums[i] and nums[j] is less than target
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                
                int left = j + 1;
                int right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third element
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        // Skip duplicates for the fourth element
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        
                        ++left;
                        --right;
                    }
                }
            }
        }
        
        return result;
    }
};
