# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        q = deque()
        q.append(root)
        result = []
        while q:
            level = []
            temp = q.copy()
            while temp:
                e = temp.pop()
                q.pop()
                level.append(e.val)
                if e.left != None:
                    q.appendleft(e.left)
                if e.right != None:
                    q.appendleft(e.right)
            result.append(level)
        return result
                    
