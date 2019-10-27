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
    
    vector<int> concatenation(vector<int> & left, int midValue, vector<int> & right){
        left.push_back(midValue);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
    
    vector<int> getNodes(TreeNode* root){
        if(root == NULL) return vector<int>();
        vector<int> left = getNodes(root->left);
        vector<int> right = getNodes(root->right);
        return concatenation(left, root->val, right);
    }
    
    TreeNode* createInOderTree(vector<int> & nodes){
        int n = nodes.size();
        if(n == 0) return NULL;
        TreeNode * root = new TreeNode(nodes[0]);
        TreeNode * temp = root;
        for(int i = 1; i < n; ++i){
            TreeNode * node = new TreeNode(nodes[i]);
            temp->right = node;
            temp = node;
        }
        return root;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nodes = getNodes(root);
        return createInOderTree(nodes);
    }
};
