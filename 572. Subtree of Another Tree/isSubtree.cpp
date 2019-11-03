/**

Runtime: 24 ms, faster than 91.85% of C++ online submissions for Subtree of Another Tree.
Memory Usage: 20.9 MB, less than 93.75% of C++ online submissions for Subtree of Another Tree.

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
    bool equal(TreeNode* s, TreeNode* ss){
        if(s == NULL) return ss == NULL;
        if(ss == NULL) return s == NULL;
        if(s->val != ss->val) return false;
        return equal(s->left, ss->left) && equal(s->right, ss->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* ss) {
        if(s == NULL) return ss == NULL;
        if(ss == NULL) return s == NULL;
        if(s->val != ss->val) return isSubtree(s->left, ss) || isSubtree(s->right, ss);
        return equal(s, ss) || isSubtree(s->left, ss) || isSubtree(s->right, ss);
    }
};
