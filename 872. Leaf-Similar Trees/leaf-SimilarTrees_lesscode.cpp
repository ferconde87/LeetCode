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
    
    void getLeaves(TreeNode* root, vector<int> & leaves){
        if(root == NULL) return;
        getLeaves(root->left, leaves);
        if(root->left == NULL && root->right == NULL) leaves.push_back(root->val);
        getLeaves(root->right, leaves);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        return leaves1 == leaves2;
    }
};
