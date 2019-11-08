/**
Runtime: 12 ms, faster than 73.71% of C++ online submissions for Linked List Cycle.
Memory Usage: 9.8 MB, less than 75.00% of C++ online submissions for Linked List Cycle.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && slow != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL) return false;
            fast = fast->next;
            if(slow == fast) return true;
        }
        return false;
    }
};
