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
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        if(p == NULL) return q == NULL;
        if(q == NULL) return p == NULL;
        while(!queue.empty()){
            auto a = queue.front();
            queue.pop();
            auto b = queue.front();
            queue.pop();
            if(a->val != b->val) return false;
            if(a->left == NULL && b->left != NULL || (a->left != NULL && b->left == NULL)) return false;
            if(a->right == NULL && b->right != NULL || (a->right != NULL && b->right == NULL)) return false;
            if(a->left != NULL){
                queue.push(a->left);
                queue.push(b->left);
            }
            if(a->right != NULL){
                queue.push(a->right);
                queue.push(b->right);
            }
        }
        return true;
    }
};
