/**
 * Problem: Permutations II (Medium)
 * Language: C++
 *
 * Description:
 * Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [1,1,2]
 * **Output:**
 * [[1,1,2],
 *  [1,2,1],
 *  [2,1,1]]
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [1,2,3]
 * **Output:** [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= nums.length <= 8`
 * 
 * 	• `-10 <= nums[i] <= 10`
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        // Sort to group duplicates together
        sort(nums.begin(), nums.end());
        
        // Helper function for backtracking
        function<void()> backtrack = [&]() {
            // If current permutation is complete, add to result
            if (current.size() == nums.size()) {
                result.push_back(current);
                return;
            }
            
            for (int i = 0; i < nums.size(); ++i) {
                // Skip if already used in current path
                if (used[i]) continue;
                
                // Skip duplicates: 
                // If current element is same as previous and previous is NOT used,
                // it means we are trying to use a duplicate before its "original" 
                // in the current level, which would create a duplicate permutation.
                // We only allow using nums[i] if nums[i-1] is already used (part of current path).
                if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                    continue;
                }
                
                // Choose
                used[i] = true;
                current.push_back(nums[i]);
                
                // Explore
                backtrack();
                
                // Un-choose
                used[i] = false;
                current.pop_back();
            }
        };
        
        backtrack();
        return result;
    }
};
