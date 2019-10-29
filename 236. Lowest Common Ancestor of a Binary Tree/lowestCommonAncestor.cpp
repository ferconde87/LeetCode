/**
Runtime: 20 ms, faster than 73.11% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 16.4 MB, less than 100.00% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode * l = lowestCommonAncestor(root->left, p, q);
        TreeNode * r = lowestCommonAncestor(root->right, p, q);
        if(l != NULL && r != NULL) return root;
        if(l != NULL) return l;
        return r;
    }
};
