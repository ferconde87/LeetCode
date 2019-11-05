/**
Runtime: 36 ms, faster than 86.43% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 14 MB, less than 38.89% of C++ online submissions for Merge Two Binary Trees.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) return t2;
        queue<TreeNode*> q({t1,t2});
        
        while(!q.empty()){
            auto c1 = q.front(); q.pop();
            auto c2 = q.front(); q.pop();
            if(c1 == NULL || c2 == NULL) continue;
            c1->val += c2->val;
            if(c1->left == NULL){
                c1->left = c2->left;
            } else {
                q.push(c1->left); q.push(c2->left);
            }
            if(c1->right == NULL){
                c1->right = c2->right;
            }else{
                q.push(c1->right); q.push(c2->right);
            }
        }
        return t1;
        
    }
};
