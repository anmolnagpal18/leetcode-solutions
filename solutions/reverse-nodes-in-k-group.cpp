/**
 * Problem: Reverse Nodes in k-Group (Hard)
 * Language: C++
 *
 * Description:
 * Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return *the modified list*.
 * 
 * `k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.
 * 
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** head = [1,2,3,4,5], k = 2
 * **Output:** [2,1,4,3,5]
 * 
 * **Example 2:**
 * 
 * **Input:** head = [1,2,3,4,5], k = 3
 * **Output:** [3,2,1,4,5]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• The number of nodes in the list is `n`.
 * 
 * 	• `1 <= k <= n <= 5000`
 * 
 * 	• `0 <= Node.val <= 1000`
 * 
 *  
 * 
 * **Follow-up:** Can you solve the problem in `O(1)` extra memory space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to simplify head operations
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;   // node before the current block
        ListNode* cur = head;    // first node of the current block

        // Count total nodes
        int n = 0;
        for (ListNode* p = head; p; p = p->next) ++n;

        while (n >= k) {
            // Reverse k nodes using head‑insertion technique
            for (int i = 1; i < k; ++i) {
                ListNode* nxt = cur->next;      // node to move to front
                cur->next = nxt->next;          // remove nxt from its place
                nxt->next = pre->next;          // insert nxt after pre
                pre->next = nxt;
            }
            // Move pre and cur to the next block
            pre = cur;
            cur = cur->next;
            n -= k;
        }
        return dummy->next;
    }
};
