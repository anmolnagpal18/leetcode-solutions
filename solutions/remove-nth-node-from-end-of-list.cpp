/**
 * Problem: Remove Nth Node From End of List (Medium)
 * Language: C++
 *
 * Description:
 * Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** head = [1,2,3,4,5], n = 2
 * **Output:** [1,2,3,5]
 * 
 * **Example 2:**
 * 
 * **Input:** head = [1], n = 1
 * **Output:** []
 * 
 * **Example 3:**
 * 
 * **Input:** head = [1,2], n = 1
 * **Output:** [1]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• The number of nodes in the list is `sz`.
 * 
 * 	• `1 <= sz <= 30`
 * 
 * 	• `0 <= Node.val <= 100`
 * 
 * 	• `1 <= n <= sz`
 * 
 *  
 * 
 * **Follow up:** Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        
        // Move first n steps ahead
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        
        // If first is nullptr, we need to delete the head
        if (!first) {
            ListNode* newHead = head->next;
            // Optional: delete head; // if managing memory manually
            return newHead;
        }
        
        // Move both pointers until first reaches the last node
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        
        // Delete the nth node from the end
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        // Optional: delete nodeToDelete; // if managing memory manually
        
        return head;
    }
};
