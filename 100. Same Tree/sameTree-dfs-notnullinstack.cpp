/**
Runtime: 4 ms, faster than 59.62% of C++ online submissions for Same Tree.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Same Tree.
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
            TreeNode* n1 = sp.top();
            sp.pop();
            TreeNode* n2 = sq.top();
            sq.pop();
            if(n1->val != n2->val) return false;
            if(!n1->left && !n1->right && !n2->left && !n2->right) continue;
            if(!n1->left && n2->left || (n1->left && !n2->left)) return false;
            if(n1->left && n2->left){
                sp.push(n1->left);
                sq.push(n2->left);
            }
            if(!n1->right && n2->right || (n1->right && !n2->right)) return false;
            if(!n1->right && !n2->right) continue;
            sp.push(n1->right);
            sq.push(n2->right);
        }
        return sp.empty() && sq.empty();
    }
};
