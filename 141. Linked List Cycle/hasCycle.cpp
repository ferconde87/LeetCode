/**

Runtime: 20 ms, faster than 15.29% of C++ online submissions for Linked List Cycle.
Memory Usage: 12 MB, less than 18.42% of C++ online submissions for Linked List Cycle.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    unordered_set<ListNode*> set;
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* node = head;
        while(node != NULL){
            auto it = set.find(node);
            if(it != set.end()) return true;
            set.insert(node);
            node = node->next;
        }
        return false;
    }
};
