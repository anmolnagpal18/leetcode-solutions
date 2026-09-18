/**
 * Problem: Merge k Sorted Lists (Hard)
 * Language: C++
 *
 * Description:
 * You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.
 * 
 * *Merge all the linked-lists into one sorted linked-list and return it.*
 * 
 *  
 * 
 * **Example 1:**
 * 
 * **Input:** lists = [[1,4,5],[1,3,4],[2,6]]
 * **Output:** [1,1,2,3,4,4,5,6]
 * **Explanation:** The linked-lists are:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * merging them into one sorted linked list:
 * 1->1->2->3->4->4->5->6
 * 
 * **Example 2:**
 * 
 * **Input:** lists = []
 * **Output:** []
 * 
 * **Example 3:**
 * 
 * **Input:** lists = [[]]
 * **Output:** []
 * 
 *  
 * 
 * **Constraints:**
 * 
 * 	• `k == lists.length`
 * 
 * 	• `0 4`
 * 
 * 	• `0 4 4`
 * 
 * 	• `lists[i]` is sorted in **ascending order**.
 * 
 * 	• The sum of `lists[i].length` will not exceed `104`.
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
    // Comparator for the min‑heap
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;   // smallest value has highest priority
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Initialize heap with the first node of each list
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* cur = pq.top(); pq.pop();
            tail->next = cur;
            tail = tail->next;
            if (cur->next) pq.push(cur->next);
        }
        
        return dummy.next;
    }
};
