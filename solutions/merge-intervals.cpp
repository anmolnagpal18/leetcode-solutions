/**
 * Problem: Merge Intervals (Medium)
 * Language: C++
 *
 * Description:
 * Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** intervals = [[1,3],[2,6],[8,10],[15,18]]
 * **Output:** [[1,6],[8,10],[15,18]]
 * **Explanation:** Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 * 
 * **Example 2:**
 * 
 * **Input:** intervals = [[1,4],[4,5]]
 * **Output:** [[1,5]]
 * **Explanation:** Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * **Example 3:**
 * 
 * **Input:** intervals = [[4,7],[1,4]]
 * **Output:** [[1,7]]
 * **Explanation:** Intervals [1,4] and [4,7] are considered overlapping.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 4`
 * 
 * 	• `intervals[i].length == 2`
 * 
 * 	• `0 i i 4`
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        for (const auto& interval : intervals) {
            // If the result is empty or there is a gap between the last merged interval and the current one
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlapping intervals: extend the end of the last merged interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
