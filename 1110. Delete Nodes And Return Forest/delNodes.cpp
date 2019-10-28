/**
Runtime: 36 ms, faster than 15.29% of C++ online submissions for Delete Nodes And Return Forest.
Memory Usage: 25.5 MB, less than 100.00% of C++ online submissions for Delete Nodes And Return Forest.
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
    unordered_map<TreeNode*, TreeNode*> node_parent;
    unordered_map<int, TreeNode*> id_node;
    
    void getNodeParent(TreeNode * node, TreeNode * parent){
        if(node == NULL) return;
        node_parent[node] = parent;
        getNodeParent(node->left, node);
        getNodeParent(node->right, node);
    }
    
    void getIdNode(TreeNode * node){
        if(node == NULL) return;
        id_node[node->val] = node;
        getIdNode(node->left);
        getIdNode(node->right);
    }
    
    void del(TreeNode * node){
        node->left = NULL;
        node->right = NULL;
        node = NULL;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        getNodeParent(root, NULL);
        getIdNode(root);
        vector<TreeNode*> result;
        unordered_set<int> rootsId;
        rootsId.insert(root->val);
        for(int id : to_delete){
            auto node = id_node[id];
            auto parent = node_parent[node];
            rootsId.erase(node->val);
            if(node->left != NULL) rootsId.insert(node->left->val);
            if(node->right != NULL) rootsId.insert(node->right->val);
            if(parent != NULL){
                if(parent->left == node) parent->left = NULL;
                else if(parent->right == node) parent->right = NULL;
            }
            del(node);
        }
        for(int id : rootsId) result.push_back(id_node[id]);
        return result;
    }
};
