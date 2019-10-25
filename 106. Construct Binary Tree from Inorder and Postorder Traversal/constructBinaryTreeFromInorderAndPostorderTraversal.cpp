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
    int index;
    TreeNode* buildTreeRec(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if(l < 0 || l > r){
            index++;
            return NULL;
        } 
        int node_i = postorder[index];
        int mid_index = find(inorder.begin()+l,inorder.begin()+r,node_i) - inorder.begin();
        TreeNode* node = new TreeNode(node_i);
        index--;
        node->right = buildTreeRec(inorder, postorder, mid_index+1, r);
        index--;
        node->left = buildTreeRec(inorder, postorder, l, mid_index-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = inorder.size()-1;
        return buildTreeRec(inorder, postorder, 0, inorder.size()-1);
    }
};
