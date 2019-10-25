# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def isSymmetric(a: TreeNode, b: TreeNode) -> bool:
    if not a:
        return not b
    if not b:
        return False
    if a.val != b.val:
        return False
    return isSymmetric(a.left, b.right) and isSymmetric(a.right, b.left)
        
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return isSymmetric(root, root)
        
