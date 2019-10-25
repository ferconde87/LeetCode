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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        stack<TreeNode*> s;
        s.push(root);
        int result = 1;
        unordered_map<TreeNode*,int> m;
        m[root] = 1;
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            int depth = m[node];
            if(node->left != NULL){
                m[node->left] = depth + 1;
                s.push(node->left);
            }
            if(node->right != NULL){
                m[node->right] = depth + 1;
                s.push(node->right);
            }
            
            if(node->left != NULL || node->right != NULL){
                if(depth + 1 > result){
                    result = depth + 1;
                }
            }
        }
        return result;
    }
};
