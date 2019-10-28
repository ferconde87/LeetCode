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
        int rootsId[1001] = {0};
        rootsId[root->val] = 1;
        for(int id : to_delete){
            auto n = node[id];
            auto p = parent[n->val];
            rootsId[n->val] = 0;
            if(n->left != NULL) rootsId[n->left->val] = 1;
            if(n->right != NULL) rootsId[n->right->val] = 1;
            if(p != NULL){
                if(p->left == n) p->left = NULL;
                else if(p->right == n) p->right = NULL;
            }
            del(n);
        }
        for(int id = 0; id < 1001; ++id)
            if(rootsId[id])
                result.push_back(node[id]);
        return result;
    }
};
