/**
 * Problem: Combination Sum II (Medium)
 * Language: C++
 *
 * Description:
 * Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.
 * 
 * Each number in `candidates` may only be used **once** in the combination.
 * 
 * **Note:** The solution set must not contain duplicate combinations.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** candidates = [10,1,2,7,6,1,5], target = 8
 * **Output:** 
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * **Example 2:**
 * 
 * **Input:** candidates = [2,5,2,1,2], target = 5
 * **Output:** 
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= candidates.length <= 100`
 * 
 * 	• `1 <= candidates[i] <= 50`
 * 
 * 	• `1 <= target <= 30`
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort to handle duplicates and enable pruning
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target is 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Pruning: if current candidate is greater than target, 
            // no need to continue as array is sorted
            if (candidates[i] > target) {
                break;
            }
            
            // Skip duplicates: 
            // If i > start and candidates[i] == candidates[i-1], 
            // it means we are considering the same value at the same recursion level 
            // that was already considered (and either included or skipped) in the previous iteration.
            // To avoid duplicate combinations, we skip it.
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            
            // Include current candidate
            current.push_back(candidates[i]);
            
            // Recurse with the next index (i+1) since each number can be used only once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Backtrack: remove the last added candidate
            current.pop_back();
        }
    }
};
