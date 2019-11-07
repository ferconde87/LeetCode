/**
Runtime: 8 ms, faster than 96.19% of C++ online submissions for Path Sum.
Memory Usage: 19.6 MB, less than 100.00% of C++ online submissions for Path Sum.
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
        current += root->val;
        if(root->left == NULL && root->right == NULL){
            return sum == current;
        } 
        return hasPathSumRec(root->left, sum, current) || hasPathSumRec(root->right, sum, current);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        bool ans = hasPathSumRec(root, sum, 0);
        return ans;
    }
};
