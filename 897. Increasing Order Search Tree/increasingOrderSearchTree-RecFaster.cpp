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
    void getNodes(TreeNode* root, vector<int> & nodes){
        if(root == NULL) return;
        getNodes(root->left, nodes);
        nodes.push_back(root->val);
        getNodes(root->right, nodes);
    }
    
    TreeNode* createInOderTree(vector<int> & nodes){
        int n = nodes.size();
        if(n == 0) return NULL;
        TreeNode * root = new TreeNode(nodes[0]);
        TreeNode * node = root;
        for(int i = 1; i < n; ++i){
            node->right = new TreeNode(nodes[i]);
            node = node->right;
        }
        return root;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nodes;
        getNodes(root, nodes);
        return createInOderTree(nodes);
    }
};
