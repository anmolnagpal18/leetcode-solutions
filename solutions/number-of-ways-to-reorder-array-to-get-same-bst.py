/**
 * Problem: Number of Ways to Reorder Array to Get Same BST (Hard)
 * Language: Python
 *
 * Description:
 * Given an array `nums` that represents a permutation of integers from `1` to `n`. We are going to construct a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST. Find the number of different ways to reorder `nums` so that the constructed BST is identical to that formed from the original array `nums`.
 * 
 * 	• For example, given `nums = [2,1,3]`, we will have 2 as the root, 1 as a left child, and 3 as a right child. The array `[2,3,1]` also yields the same BST but `[3,2,1]` yields a different BST.
 * 
 * Return *the number of ways to reorder* `nums` *such that the BST formed is identical to the original BST formed from* `nums`.
 * 
 * Since the answer may be very large, **return it modulo **`109 + 7`.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** nums = [2,1,3]
 * **Output:** 1
 * **Explanation:** We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
 * 
 * **Example 2:**
 * 
 * **Input:** nums = [3,4,5,1,2]
 * **Output:** 5
 * **Explanation:** The following 5 arrays will yield the same BST: 
 * [3,1,2,4,5]
 * [3,1,4,2,5]
 * [3,1,4,5,2]
 * [3,4,1,2,5]
 * [3,4,1,5,2]
 * 
 * **Example 3:**
 * 
 * **Input:** nums = [1,2,3]
 * **Output:** 0
 * **Explanation:** There are no other orderings of nums that will yield the same BST.
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `1 <= nums.length <= 1000`
 * 
 * 	• `1 <= nums[i] <= nums.length`
 * 
 * 	• All integers in `nums` are **distinct**.
 */

class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        # Precompute factorials and inverse factorials for binomial coefficients
        fact = [1] * (n + 1)
        inv_fact = [1] * (n + 1)
        
        for i in range(1, n + 1):
            fact[i] = fact[i - 1] * i % MOD
        
        inv_fact[n] = pow(fact[n], MOD - 2, MOD)
        for i in range(n - 1, -1, -1):
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD
        
        def nCr(n_val, r_val):
            if r_val < 0 or r_val > n_val:
                return 0
            return fact[n_val] * inv_fact[r_val] % MOD * inv_fact[n_val - r_val] % MOD
        
        def count_ways(arr):
            if len(arr) <= 2:
                return 1
            
            root = arr[0]
            left = [x for x in arr[1:] if x < root]
            right = [x for x in arr[1:] if x > root]
            
            l = len(left)
            r = len(right)
            
            # Number of ways to interleave left and right subtrees
            ways = nCr(l + r, l)
            
            # Multiply by ways to form left and right subtrees
            ways = ways * count_ways(left) % MOD
            ways = ways * count_ways(right) % MOD
            
            return ways
        
        # The problem asks for the number of *different* ways to reorder.
        # The original order is one of the ways, so we subtract 1.
        return (count_ways(nums) - 1) % MOD
