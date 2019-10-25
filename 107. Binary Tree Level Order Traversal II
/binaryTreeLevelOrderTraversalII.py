# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        result = []
        if root == None:
            return result
        q = deque()
        q.append(root)
        while q:
            level = []
            levelSize = len(q)
            for _ in range(levelSize):
                node = q.pop()
                if node.left:
                    q.appendleft(node.left)
                if node.right:
                    q.appendleft(node.right)
                level.append(int(node.val))
            result.append(level)
        return reversed(result)
