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
    string arrow = "->";
    void binaryTreePathsRec(TreeNode* root, string current) {
        if(root == NULL) return;
        string val = to_string(root->val);
        current.insert(current.end(), val.begin(), val.end());
        if(root->left != NULL || root->right != NULL)
            current.insert(current.end(), arrow.begin(), arrow.end());
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
