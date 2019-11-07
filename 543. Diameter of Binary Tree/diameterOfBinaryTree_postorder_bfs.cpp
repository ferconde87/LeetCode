/**

Runtime: 16 ms, faster than 37.47% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 22.5 MB, less than 7.41% of C++ online submissions for Diameter of Binary Tree.

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
    
    unordered_map<TreeNode*, int> node_diam; //from node to descendants
    
    void make_diam(TreeNode* node){
        if(node == NULL) return;
        make_diam(node->left);
        make_diam(node->right);
        int diam_left = (node->left == NULL) ? -1 : node_diam[node->left];
        int diam_right = (node->right == NULL) ? -1 : node_diam[node->right];
        node_diam[node] = 1 + max(diam_left, diam_right);
    }
    
    int getDiameter(TreeNode* root){
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            int diam_left = 0;
            if(node->left != NULL){
                diam_left = node_diam[node->left] + 1;
                q.push(node->left);
            }
            int diam_right = 0;
            if(node->right  != NULL){
                diam_right = node_diam[node->right] + 1;
                q.push(node->right);
            }
            int cur_diam = diam_left + diam_right;
            if(cur_diam > result){
                result = cur_diam;
            }
        }
        return result;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        make_diam(root);
        return getDiameter(root);
        
    }
};
