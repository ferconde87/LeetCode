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
    bool isSame(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p,q);
    }
};
