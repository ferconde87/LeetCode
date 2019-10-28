/**
Runtime: 28 ms, faster than 44.18% of C++ online submissions for Delete Nodes And Return Forest.
Memory Usage: 17.6 MB, less than 100.00% of C++ online submissions for Delete Nodes And Return Forest.
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
    TreeNode* parent[1001];
    TreeNode* node[1001];
    
    void getNodeParent(TreeNode * n, TreeNode * p){
        if(n == NULL) return;
        parent[n->val] = p;
        node[n->val] = n;
        getNodeParent(n->left, n);
        getNodeParent(n->right, n);
    }
    
    void del(TreeNode * node){
        node->left = NULL;
        node->right = NULL;
        node = NULL;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        getNodeParent(root, NULL);
        vector<TreeNode*> result;
        unordered_set<int> rootsId;
        rootsId.insert(root->val);
        for(int id : to_delete){
            auto n = node[id];
            auto p = parent[n->val];
            rootsId.erase(n->val);
            if(n->left != NULL) rootsId.insert(n->left->val);
            if(n->right != NULL) rootsId.insert(n->right->val);
            if(p != NULL){
                if(p->left == n) p->left = NULL;
                else if(p->right == n) p->right = NULL;
            }
            del(n);
        }
        for(int id : rootsId) result.push_back(node[id]);
        return result;
    }
};
