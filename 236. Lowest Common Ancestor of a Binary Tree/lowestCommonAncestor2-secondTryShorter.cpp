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
    unordered_map<TreeNode*,TreeNode*> node_parent;
    unordered_map<TreeNode*,int> node_depth;

    void make_parent_and_depth(TreeNode* node, TreeNode* parent, int depth){
        if(node == NULL) return;
        node_parent[node] = parent;
        node_depth[node] = depth;
        make_parent_and_depth(node->left, node, depth+1);
        make_parent_and_depth(node->right, node, depth+1);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        make_parent_and_depth(root, NULL, 0);
        int p_depth = node_depth[p];
        int q_depth = node_depth[q];
        while(p != NULL && q != NULL){
            if(p == q) return p;
            if(p_depth > q_depth){
                p = node_parent[p];
                --p_depth;
            }else{
                q = node_parent[q];
               --q_depth;
            }
        }
        return NULL;
    }
};
