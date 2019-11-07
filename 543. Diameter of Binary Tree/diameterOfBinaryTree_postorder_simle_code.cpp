/**
Runtime: 12 ms, faster than 68.72% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 19.7 MB, less than 92.59% of C++ online submissions for Diameter of Binary Tree.
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
    
    int ans = 0;
    int getDiameter(TreeNode* node){
        if(node == NULL) return -1;
        int l = getDiameter(node->left);
        int r = getDiameter(node->right);
        ans = max(ans, l+r+2);
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        getDiameter(root);
        return ans;
    }
};
