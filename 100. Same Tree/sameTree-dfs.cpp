/**
Runtime: 4 ms, faster than 59.62% of C++ online submissions for Same Tree.
Memory Usage: 9.8 MB, less than 77.78% of C++ online submissions for Same Tree.
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
            TreeNode* node_p = sp.top();
            sp.pop();
            TreeNode* node_q = sq.top();
            sq.pop();
            if(node_p == NULL && node_q == NULL) continue;
            if(node_p == NULL || node_q == NULL) return false;
            if(node_p->val != node_q->val) return false;
            sp.push(node_p->left);
            sq.push(node_q->left);
            sp.push(node_p->right);
            sq.push(node_q->right);
        }
        return sp.empty() && sq.empty();
    }
};
