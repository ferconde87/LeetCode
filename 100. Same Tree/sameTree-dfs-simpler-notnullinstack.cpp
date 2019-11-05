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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p) return !q;
        if(!q) return !p;
        stack<TreeNode*> sp;
        stack<TreeNode*> sq;
        sp.push(p);
        sq.push(q);
        while(!sp.empty() && !sq.empty()){
            TreeNode* a = sp.top();
            sp.pop();
            TreeNode* b = sq.top();
            sq.pop();
            
            if(a->val != b->val) return false;
            if(!a->left && b->left || (a->left && !b->left)) return false;
            if(!a->right && b->right || (a->right && !b->right)) return false;
        
            if(a->left && b->left){
                sp.push(a->left);
                sq.push(b->left);
            }
            if(a->right && b->right){
                sp.push(a->right);
                sq.push(b->right);
            }
        }
        return sp.empty() && sq.empty();
    }
};
