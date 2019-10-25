/**
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
    bool isSymmetric(TreeNode * a, TreeNode* b){
        if(a == NULL) return b == NULL;
        if(b == NULL) return false;
        if(a->val != b->val) return false;
        return isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
        
    }
};
