/**
 * Problem: Insert Interval (Medium)
 * Language: C++
 *
 * Description:
 * You are given an array of non-overlapping intervals `intervals` where `intervals[i] = [starti, endi]` represent the start and the end of the `ith` interval and `intervals` is sorted in ascending order by `starti`. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.
 * 
 * Two intervals are considered overlapping if they share **at least** one point.
 * 
 * Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by `starti` and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).
 * 
 * Return `intervals`* after the insertion*.
 * 
 * **Note** that you don't need to modify `intervals` in-place. You can make a new array and return it.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** intervals = [[1,3],[6,9]], newInterval = [2,5]
 * **Output:** [[1,5],[6,9]]
 * 
 * **Example 2:**
 * 
 * **Input:** intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * **Output:** [[1,2],[3,10],[12,16]]
 * **Explanation:** Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `0 4`
 * 
 * 	• `intervals[i].length == 2`
 * 
 * 	• `0 i i 5`
 * 
 * 	• `intervals` is sorted by `starti` in **ascending** order.
 * 
 * 	• `newInterval.length == 2`
 * 
 * 	• `0 5`
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // 1. Add all intervals that end before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            ++i;
        }

        // 2. Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        result.push_back(newInterval);   // the merged interval

        // 3. Append the rest
        while (i < n) {
            result.push_back(intervals[i]);
            ++i;
        }

        return result;
    }
};
