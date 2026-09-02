/*
You are given an array `nums1` of `n` **distinct** integers.

You want to construct another array `nums2` of length `n` such that the elements in `nums2` are either **all odd or all even**.

For each index `i`, you must choose **exactly one** of the following (in any order):

	- `nums2[i] = nums1[i]`

	- `nums2[i] = nums1[i] - nums1[j]`, for an index `j != i`

Return `true` if it is possible to construct such an array, otherwise, return `false`.

Example 1:**

**Input:** nums1 = [2,3]

**Output:** true

**Explanation:**

	- Choose `nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1`.

	- Choose `nums2[1] = nums1[1] = 3`.

	- `nums2 = [-1, 3]`, and both elements are odd. Thus, the answer is `true`​​​​​​​.

Example 2:**

**Input:** nums1 = [4,6]

**Output:** true

**Explanation:**​​​​​​​

	- Choose `nums2[0] = nums1[0] = 4`.

	- Choose `nums2[1] = nums1[1] = 6`.

	- `nums2 = [4, 6]`, and all elements are even. Thus, the answer is `true`.

**Constraints:**

	- `1 <= n == nums1.length <= 100`

	- `1 <= nums1[i] <= 100`

	- `nums1` consists of distinct integers.
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        
        // Check if all odd is possible
        bool allOddPossible = true;
        for (int i = 0; i < n; i++) {
            bool canBeOdd = false;
            
            // Option 1: nums1[i] is already odd
            if (nums1[i] % 2 != 0) {
                canBeOdd = true;
            }
            
            // Option 2: nums1[i] - nums1[j] is odd for some j != i
            // This requires nums1[i] and nums1[j] to have different parities
            if (!canBeOdd) {
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    if ((nums1[i] % 2) != (nums1[j] % 2)) {
                        canBeOdd = true;
                        break;
                    }
                }
            }
            
            if (!canBeOdd) {
                allOddPossible = false;
                break;
            }
        }
        
        if (allOddPossible) {
            return true;
        }
        
        // Check if all even is possible
        bool allEvenPossible = true;
        for (int i = 0; i < n; i++) {
            bool canBeEven = false;
            
            // Option 1: nums1[i] is already even
            if (nums1[i] % 2 == 0) {
                canBeEven = true;
            }
            
            // Option 2: nums1[i] - nums1[j] is even for some j != i
            // This requires nums1[i] and nums1[j] to have same parity
            if (!canBeEven) {
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    if ((nums1[i] % 2) == (nums1[j] % 2)) {
                        canBeEven = true;
                        break;
                    }
                }
            }
            
            if (!canBeEven) {
                allEvenPossible = false;
                break;
            }
        }
        
        return allEvenPossible;
    }
};