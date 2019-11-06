/**
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
 * Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Invert Binary Tree.
 * 
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        return root;
    }
};
