# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        node = head
        l = []
        while node:
            l.append(node.val)
            node = node.next
        n = len(l)
        mid = n // 2
        for i in range(0, mid):
            if l[i] != l[n-1-i]:
                return False
        return True
        
