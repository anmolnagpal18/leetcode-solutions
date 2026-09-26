/**
 * Problem: Search in Rotated Sorted Array (Medium)
 * Language: C++
 *
 * Description:
 * There is an integer array `nums` sorted in ascending order (with **distinct** values).
 * 
 * Prior to being passed to your function, `nums` is **possibly left rotated** at an unknown index `k` (`1 **Input:** nums = [4,5,6,7,0,1,2], target = 0
 * **Output:** 4
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [4,5,6,7,0,1,2], target = 3
 * **Output:** -1
 * 
 * **Example 3:**
 * 
 * **Input:** nums = [1], target = 0
 * **Output:** -1
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 4 4`
 * 
 * 	• All values of `nums` are **unique**.
 * 
 * 	• `nums` is an ascending array that is possibly rotated.
 * 
 * 	• `-104 4`
 */

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;

            // Determine which half is sorted
            if (nums[low] <= nums[mid]) {               // left half is sorted
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;                     // target in left half
                else
                    low = mid + 1;                      // target in right half
            } else {                                    // right half is sorted
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;                      // target in right half
                else
                    high = mid - 1;                     // target in left half
            }
        }
        return -1;                                      // not found
    }
};
