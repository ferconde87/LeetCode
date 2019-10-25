/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            result++;
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                if(node->left == NULL && node->right == NULL) return result;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        return result;
        
    }
};
