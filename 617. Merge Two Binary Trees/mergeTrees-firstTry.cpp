/**
Runtime: 36 ms, faster than 86.43% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 23.8 MB, less than 8.33% of C++ online submissions for Merge Two Binary Trees.
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
        TreeNode* merged;
        if(t1 == NULL && t2 == NULL) return NULL;
        int val = 0;
        val += (t1 == NULL) ? 0 : t1->val;
        val += (t2 == NULL) ? 0 : t2->val;
        merged = new TreeNode(val);
        if(t1 == NULL) { 
            merged->left = mergeTrees(NULL, t2->left);
            merged->right = mergeTrees(NULL, t2->right);
        } else if(t2 == NULL) {
            merged->left = mergeTrees(t1->left, NULL);
            merged->right = mergeTrees(t1->right, NULL);
        } else {
            merged->left = mergeTrees(t1->left, t2->left);
            merged->right = mergeTrees(t1->right, t2->right);
        }
        return merged;
    }
};
