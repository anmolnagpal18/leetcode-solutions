/**
 * Problem: Rotate List (Medium)
 * Language: C++
 *
 * Description:
 * Given the `head` of a linked list, rotate the list to the right by `k` places.
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** head = [1,2,3,4,5], k = 2
 * **Output:** [4,5,1,2,3]
 * 
 * **Example 2:**
 * 
 * **Input:** head = [0,1,2], k = 4
 * **Output:** [2,0,1]
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• The number of nodes in the list is in the range `[0, 500]`.
 * 
 * 	• `-100 9`
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        // Compute length and close the list into a circle
        ListNode* cur = head;
        int len = 1;
        while (cur->next) {
            cur = cur->next;
            ++len;
        }
        // cur is now the last node
        cur->next = head; // make it circular

        // Effective rotations
        k %= len;
        if (k == 0) {
            cur->next = nullptr; // break the circle
            return head;
        }

        // Find new tail: (len - k - 1) steps from head
        int stepsToNewTail = len - k - 1;
        ListNode* newTail = head;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr; // break the circle

        return newHead;
    }
};
