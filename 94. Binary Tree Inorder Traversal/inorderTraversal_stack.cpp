/**
Runtime: 4 ms, faster than 59.12% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 9.2 MB, less than 89.00% of C++ online submissions for Binary Tree Inorder Traversal.
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return vector<int>();
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node = root;
        vector<int> result;
        while(!s.empty()){
            while(node->left != NULL){
                s.push(node->left);
                node = node->left;
            }
            result.push_back(node->val);
            s.pop();
            while(!s.empty() && node->right == NULL){
                node = s.top();
                result.push_back(node->val);
                s.pop();
            }
            if(node->right != NULL){
                s.push(node->right);
                node = node->right;
            }
        }
        return result;
    }
};
