/**
Runtime: 4 ms, faster than 98.87% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.2 MB, less than 82.44% of C++ online submissions for Reverse Linked List.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* prev, ListNode* head){
        if(head == NULL) return prev;
        ListNode * next = head->next;
        head->next = prev;
        return reverseList(head, next);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverseList(NULL, head);
    }
};
