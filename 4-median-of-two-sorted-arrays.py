"""
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

Example 1:**

**Input:** nums1 = [1,3], nums2 = [2]
**Output:** 2.00000
**Explanation:** merged array = [1,2,3] and median is 2.

Example 2:**

**Input:** nums1 = [1,2], nums2 = [3,4]
**Output:** 2.50000
**Explanation:** merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

**Constraints:**

	- `nums1.length == m`

	- `nums2.length == n`

	- `0 6 6`
"""

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Ensure nums1 is the smaller array for O(log(min(m,n))) complexity
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        m, n = len(nums1), len(nums2)
        total = m + n
        
        # Binary search on the smaller array
        # We want to find a partition such that:
        # - Left half has total//2 elements (or (total-1)//2 for even)
        # - All elements in left half <= all elements in right half
        
        lo, hi = 0, m
        
        while lo <= hi:
            i = (lo + hi) // 2  # partition index in nums1
            j = (total + 1) // 2 - i  # partition index in nums2
            
            # Handle edge cases where partition is at boundary
            left1 = nums1[i - 1] if i > 0 else float('-inf')
            right1 = nums1[i] if i < m else float('inf')
            left2 = nums2[j - 1] if j > 0 else float('-inf')
            right2 = nums2[j] if j < n else float('inf')
            
            if left1 <= right2 and left2 <= right1:
                # Found the correct partition
                if total % 2 == 1:
                    return float(max(left1, left2))
                else:
                    return (max(left1, left2) + min(right1, right2)) / 2.0
            elif left1 > right2:
                # Too many elements from nums1 in left half
                hi = i - 1
            else:
                # Too few elements from nums1 in left half
                lo = i + 1
        
        # This should never be reached if input is valid
        return 0.0