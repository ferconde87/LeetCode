/**
Runtime: 4 ms, faster than 57.44% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.2 MB, less than 90.91% of C++ online submissions for Invert Binary Tree.
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
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left != NULL) s.push(node->left);
            if(node->right != NULL) s.push(node->right);
        }
        return root;
    }
};
