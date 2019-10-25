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
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        while(!queue.empty()){
            auto a = queue.front();
            queue.pop();
            auto b = queue.front();
            queue.pop();
            if(a == NULL && b == NULL) continue;
            if(a == NULL || b == NULL) return false;
            if(a->val != b->val) return false;
            queue.push(a->left);
            queue.push(b->left);
            queue.push(a->right);
            queue.push(b->right);
        }
        return true;
    }
};
