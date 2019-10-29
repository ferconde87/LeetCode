/**
Runtime: 508 ms, faster than 5.00% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 17.3 MB, less than 36.36% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
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
    
    bool containsAny(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        if(root == p || root == q) return true;
        return containsAny(root->left, p, q) || containsAny(root->right, p, q);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        bool l = containsAny(root->left, p, q);
        bool r = containsAny(root->right, p, q);
        if((root == p || root == q) && (l || r)) return root;
        if(l && r) return root;
        if(l) return lowestCommonAncestor(root->left, p, q);
        if(r) return lowestCommonAncestor(root->right, p, q);
        return NULL;
    }
};
