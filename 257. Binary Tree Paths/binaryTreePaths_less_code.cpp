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
    vector<string> result;
    void binaryTreePathsRec(TreeNode* root, string current) {
        if(root == NULL) return;
        current += to_string(root->val);
        if(root->left != NULL || root->right != NULL) current += "->";
        else result.push_back(current);
        binaryTreePathsRec(root->left, current);
        binaryTreePathsRec(root->right, current);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string current = "";
        binaryTreePathsRec(root, current);
        return result;
    }
};
