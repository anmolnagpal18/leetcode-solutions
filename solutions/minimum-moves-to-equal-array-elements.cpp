/**
 * Problem: Minimum Moves to Equal Array Elements (Medium)
 * Language: C++
 *
 * Description:
 * Given an integer array `nums` of size `n`, return *the minimum number of moves required to make all array elements equal*.
 * 
 * In one move, you can increment `n - 1` elements of the array by `1`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [1,2,3]
 * **Output:** 3
 * **Explanation:** Only three moves are needed (remember each move increments two elements):
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [1,1,1]
 * **Output:** 0
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `n == nums.length`
 * 
 * 	• `1 5`
 * 
 * 	• `-109 9`
 * 
 * 	• The answer is guaranteed to fit in a **32-bit** integer.
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int minVal = nums[0];
        long long sum = 0;
        
        for (int num : nums) {
            minVal = std::min(minVal, num);
            sum += num;
        }
        
        // The answer is sum - n * minVal
        // Since the answer fits in a 32-bit integer, we can cast back to int
        return (int)(sum - (long long)nums.size() * minVal);
    }
};
