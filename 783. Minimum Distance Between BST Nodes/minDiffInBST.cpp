/**

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Distance Between BST Nodes.
Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Minimum Distance Between BST Nodes.

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
    
    int minDiffInBST(TreeNode* root) {
        min_diff = INT_MAX;
        inOrder(root);
        return min_diff;
    }
};
