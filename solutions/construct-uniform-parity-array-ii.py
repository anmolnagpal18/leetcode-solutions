/**
 * Problem: Construct Uniform Parity Array II (Medium)
 * Language: Python
 *
 * Description:
 * You are given an array `nums1` of `n` **distinct** integers.
 * 
 * You want to construct another array `nums2` of length `n` such that the elements in `nums2` are either **all odd or all even**.
 * 
 * For each index `i`, you must choose **exactly one** of the following (in any order):
 * 
 * 	• `nums2[i] = nums1[i]`​​​​​​​
 * 
 * 	• `nums2[i] = nums1[i] - nums1[j]`, for an index `j != i`, such that `nums1[i] - nums1[j] >= 1`
 * 
 * Return `true` if it is possible to construct such an array, otherwise return `false`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums1 = [1,4,7]
 * 
 * **Output:** true
 * 
 * **Explanation:**​​​​​​​​​​​​​​
 * 
 * 	• Set `nums2[0] = nums1[0] = 1`.
 * 
 * 	• Set `nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3`.
 * 
 * 	• Set `nums2[2] = nums1[2] = 7`.
 * 
 * 	• `nums2 = [1, 3, 7]`, and all elements are odd. Thus, the answer is `true`.
 * 
 * **Example 2:**
 * 
 * **Input:** nums1 = [2,3]
 * 
 * **Output:** false
 * 
 * **Explanation:**
 * 
 * It is not possible to construct `nums2` such that all elements have the same parity. Thus, the answer is `false`.
 * 
 * **Example 3:**
 * 
 * **Input:** nums1 = [4,6]
 * 
 * **Output:** true
 * 
 * **Explanation:**
 * 
 * 	• Set `nums2[0] = nums1[0] = 4`.
 * 
 * 	• Set `nums2[1] = nums1[1] = 6`.
 * 
 * 	• `nums2 = [4, 6]`, and all elements are even. Thus, the answer is `true`.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 5`
 * 
 * 	• `1 9`
 * 
 * 	• `nums1` consists of distinct integers.
 */

class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        min_odd = float('inf')
        min_even = float('inf')
        
        for num in nums1:
            if num % 2 == 0:
                if num < min_even:
                    min_even = num
            else:
                if num < min_odd:
                    min_odd = num
        
        # Case 1: No odd numbers. We can just keep all evens.
        if min_odd == float('inf'):
            return True
            
        # Case 2: No even numbers. We can just keep all odds.
        if min_even == float('inf'):
            return True
            
        # Case 3: Both exist.
        # To make all elements odd, every even number must be able to subtract a smaller odd number.
        # The most constrained even number is the smallest one (min_even).
        # It needs to subtract an odd number smaller than itself.
        # The smallest available odd number is min_odd.
        # So we need min_odd < min_even.
        return min_odd < min_even
