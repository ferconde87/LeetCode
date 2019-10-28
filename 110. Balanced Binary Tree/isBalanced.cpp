/**
Runtime: 12 ms, faster than 84.28% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 17.1 MB, less than 96.61% of C++ online submissions for Balanced Binary Tree.
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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int l = height(root->left);
        int r = height(root->right);
        return abs(l-r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
