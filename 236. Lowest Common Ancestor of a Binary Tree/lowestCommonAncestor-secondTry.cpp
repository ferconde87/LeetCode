/**
Runtime: 24 ms, faster than 39.16% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 24.9 MB, less than 5.45% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
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
        if(root == p || root == q) return root;
        if(p == q) return p;
        
        make_parent_and_depth(root, NULL, 0);
        
        int p_depth = node_depth[p];
        int q_depth = node_depth[q];
        
        TreeNode* p_ancestor;
        TreeNode* q_ancestor;
        if(p_depth < q_depth) {
            p_ancestor = p;
            q_ancestor = node_parent[q];
        }else if(q_depth < p_depth){
            p_ancestor = node_parent[p];
            q_ancestor = q;
        }else{
            p_ancestor = node_parent[p];
            q_ancestor = node_parent[q];
        }
        
        int p_ancestor_depth = node_depth[p_ancestor];
        int q_ancestor_depth = node_depth[q_ancestor];
        
        while(p_ancestor != NULL && q_ancestor != NULL){
            if(p_ancestor == q_ancestor) return p_ancestor;
            if(p_ancestor_depth > q_ancestor_depth){
                p_ancestor = node_parent[p_ancestor];
                --p_ancestor_depth;
            }else{
                q_ancestor = node_parent[q_ancestor];
               --q_ancestor_depth;
            }
        }
        return NULL;
    }
};
