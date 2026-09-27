/**
 * Problem: Find First and Last Position of Element in Sorted Array (Medium)
 * Language: C++
 *
 * Description:
 * Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.
 * 
 * If `target` is not found in the array, return `[-1, -1]`.
 * 
 * You must write an algorithm with `O(log n)` runtime complexity.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [5,7,7,8,8,10], target = 8
 * **Output:** [3,4]
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [5,7,7,8,8,10], target = 6
 * **Output:** [-1,-1]
 * 
 * **Example 3:**
 * 
 * **Input:** nums = [], target = 0
 * **Output:** [-1,-1]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `0 5`
 * 
 * 	• `-109 9`
 * 
 * 	• `nums` is a non-decreasing array.
 * 
 * 	• `-109 9`
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }

        int left = -1;
        int right = -1;

        // Find the first occurrence
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                left = mid;
                high = mid - 1; // Search left half
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // If target not found, return [-1, -1]
        if (left == -1) {
            return {-1, -1};
        }

        // Find the last occurrence
        low = 0;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                right = mid;
                low = mid + 1; // Search right half
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {left, right};
    }
};
