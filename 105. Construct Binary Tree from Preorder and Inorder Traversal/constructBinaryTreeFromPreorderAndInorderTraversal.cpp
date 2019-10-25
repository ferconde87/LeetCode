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
    
    int pre_index = 0;
    TreeNode* buildTreeRec(vector<int>& preorder, vector<int>& inorder, int l, int r) 
    {
        if(l < 0 || l > r){
            pre_index--;
            return NULL;
        }
        int node_id = preorder[pre_index];
        int mid = find(inorder.begin()+l, inorder.begin()+r, node_id) - inorder.begin();
        TreeNode* node = new TreeNode(node_id);
        pre_index++;
        node->left = buildTreeRec(preorder, inorder, l, mid-1);
        pre_index++;
        node->right = buildTreeRec(preorder, inorder, mid+1, r);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeRec(preorder, inorder, 0, inorder.size()-1);
    }
};
