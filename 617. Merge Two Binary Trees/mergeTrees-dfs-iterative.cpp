/**
 * Runtime: 40 ms, faster than 61.31% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 13.8 MB, less than 44.44% of C++ online submissions for Merge Two Binary Trees.
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
        stack<pair<TreeNode*, TreeNode*> > s({make_pair(t1,t2)});
        while(!s.empty()){
            auto p = s.top();
            s.pop();
            auto c1 = p.first;
            auto c2 = p.second;
            if(c1 == NULL || c2 == NULL) continue;
            c1->val += c2->val;
            if(c1->left == NULL){
                c1->left = c2->left;
            } else {
                s.push(make_pair(c1->left, c2->left));
            }
            if(c1->right == NULL){
                c1->right = c2->right;
            }else{
                s.push(make_pair(c1->right, c2->right));
            }
        }
        return t1;
        
    }
};
