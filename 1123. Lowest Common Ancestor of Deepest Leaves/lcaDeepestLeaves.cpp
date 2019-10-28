/**
Runtime: 20 ms, faster than 41.18% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.
Memory Usage: 22.2 MB, less than 100.00% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.
 *
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
    unordered_map<TreeNode*, int> depth;
    int max_depth;
    
    void dfsDepths(TreeNode* node, TreeNode* parent){
        if(node == NULL) return;
        depth[node] = depth[parent] + 1;
        dfsDepths(node->left, node);
        dfsDepths(node->right, node);
    }
    
    TreeNode* lca(TreeNode* node){
        if(node == NULL) return NULL;
        if(depth[node] == max_depth) return node;
        TreeNode* l = lca(node->left);
        TreeNode* r = lca(node->right);
        if(l != NULL && r != NULL) return node;
        if(l != NULL) return l;
        if(r != NULL) return r;
        return NULL;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        max_depth = -1;
        depth[NULL] = -1;
        dfsDepths(root, NULL);
        for(auto it = depth.begin(); it != depth.end(); ++it){
            if(it->second > max_depth) max_depth = it->second;
        }
        return lca(root);
    }
};
