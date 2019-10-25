# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque


class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        q = deque()
        q.appendleft(root)
        result = 0
        found = False
        while q:
            l = len(q)
            result += 1
            for _ in range(l):
                node = q.pop()
                if node.left == None and node.right == None:
                    return result
                if node.left != None:
                    q.appendleft(node.left)
                if node.right != None:
                    q.appendleft(node.right)
        return result
                
        
        
