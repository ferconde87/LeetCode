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
    unordered_map<TreeNode*, int> depth;
    int max_depth;
    
    void dfs(TreeNode* node, TreeNode* parent){
        if(node == NULL) return;
        depth[node] = depth[parent] + 1;
        dfs(node->left, node);
        dfs(node->right, node);
    }
    
    TreeNode* allDeepest(TreeNode* node){
        if(node == NULL) return NULL;
        if(depth[node] == max_depth) return node;
        TreeNode* l = allDeepest(node->left);
        TreeNode* r = allDeepest(node->right);
        if(l != NULL && r != NULL) return node;
        if(l != NULL) return l;
        if(r != NULL) return r;
        return NULL;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth[NULL] = -1;
        max_depth = -1;
        dfs(root, NULL);
        for(auto it = depth.begin(); it != depth.end(); it++){
            if(it->second > max_depth) max_depth = it->second;
        }
        return allDeepest(root);
    }
};
