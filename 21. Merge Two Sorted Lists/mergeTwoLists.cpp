/**
Runtime: 8 ms, faster than 77.46% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 8.9 MB, less than 76.23% of C++ online submissions for Merge Two Sorted Lists.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* node;
        if(l1->val < l2->val){
            node = l1;
            l1 = l1->next;
        }else{
            node = l2;
            l2 = l2->next;
        }
        ListNode* result = node;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                node->next = l1;
                l1 = l1->next;
            }else{
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if(l1 != NULL) node->next = l1;
        if(l2 != NULL) node->next = l2;
        return result;
    }
};
