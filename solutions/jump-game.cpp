/**
 * Problem: Jump Game (Medium)
 * Language: C++
 *
 * Description:
 * You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.
 * 
 * Return `true`* if you can reach the last index, or *`false`* otherwise*.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [2,3,1,1,4]
 * **Output:** true
 * **Explanation:** Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [3,2,1,0,4]
 * **Output:** false
 * **Explanation:** You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 4`
 * 
 * 	• `0 5`
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;                     // farthest reachable index so far
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > reach) return false;   // current index is not reachable
            reach = max(reach, i + nums[i]);
            if (reach >= (int)nums.size() - 1) return true; // early exit
        }
        return true;
    }
};
