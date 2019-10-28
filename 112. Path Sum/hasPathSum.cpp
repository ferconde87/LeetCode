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
    bool prueba = false;
    bool hasPathSumRec(TreeNode* root, int sum, int current) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL){
            current += root->val;
            return sum == current;
        } 
        return hasPathSumRec(root->left, sum, current+root->val) || hasPathSumRec(root->right, sum, current+root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        bool ans = hasPathSumRec(root, sum, 0);
        return ans;
    }
};
