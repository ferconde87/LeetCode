#include <bits/stdc++.h>

using namespace std;
 
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addCarry(ListNode * node){
    ListNode * newNode = new ListNode(1);
    node->next = newNode;
}

void copyRemaining(ListNode * current, ListNode * listToCopy, int carry){
    while(listToCopy != NULL){
        int value = listToCopy->val + carry;
        if(value >= 10){
            value = value % 10;
            carry = 1;
        }else{
            carry = 0;
        }
        listToCopy = listToCopy->next;
        current->next = new ListNode(value);
        current = current->next;
    }
    if(carry == 1){
        addCarry(current);
    }
}

void print(ListNode * result){
    ListNode * node = result;
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
        
    }
    cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    int carry = 0;
    ListNode * result = new ListNode(0);
    ListNode * node = result;
    while(l1 != NULL && l2 != NULL){
        int sum = l1->val + l2->val + carry;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        node->val = sum;
        l1 = l1->next;
        l2 = l2->next;
        if(l1 != NULL && l2 != NULL){//is there a next digit?
            ListNode * next = new ListNode(0);//create a node
            node->next = next;
            node = next;
        }
    }
    
    if(l1 == NULL && l2 == NULL){//case: l1 & l1 have the same length
        if(carry == 1){
            addCarry(node);
        }
    }else{
        if(l1 != NULL) copyRemaining(node, l1, carry);
        else if(l2 != NULL) copyRemaining(node, l2, carry);
    }
    
    return result;
    
}


int main(){

    ListNode * a1 = new ListNode(1);
    ListNode * a2 = new ListNode(2);
    ListNode * a3 = new ListNode(3);
    ListNode * b1 = new ListNode(6);
    ListNode * b2 = new ListNode(7);
    ListNode * b3 = new ListNode(8);
    a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;

    //a1 => 1 -> 2 -> 3 === 321
    //b1 => 6 -> 7 -> 8 === 876
    //result => 7 -> 9 -> 1 -> 1 === 321 + 876 = 1197
    ListNode * result = addTwoNumbers(a1,b1);
    print(result);

    return 0;
}