/**
Runtime: 24 ms, faster than 42.72% of C++ online submissions for Minimum Absolute Difference in BST.
Memory Usage: 21.6 MB, less than 100.00% of C++ online submissions for Minimum Absolute Difference in BST.
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
    int min_diff;
    int prev = INT_MAX;
    void inOrder(TreeNode* root){
        if(root == NULL) return;
        inOrder(root->left);
        if(prev == INT_MAX) {
            prev = root->val;
        }else{
            min_diff = min(min_diff, root->val - prev);
            prev = root->val;
        }
        inOrder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        min_diff = INT_MAX;
        inOrder(root);
        return min_diff;
    }
};
