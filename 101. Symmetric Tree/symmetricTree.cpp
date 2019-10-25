/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

void print(vector<int> & v){
    for(int x : v) cout << x << " "; cout << endl;
    cout << endl;
}

bool checkSymmetric(vector<TreeNode*> & v){
    //cout << v.size() << endl;
    int mid = v.size()/2;
    int last = v.size() - 1;
    for(int i = 0; i < mid; i++){
        if(v[i] == NULL && v[last-i] == NULL) continue;
        if((v[i] == NULL && v[last-i] != NULL) || (v[i] != NULL && v[last-i] == NULL))         {
            return false;
        }else{
           if(v[i]->val != v[last-i]->val){
               return false;
           } 
        }        
    }
    return true;
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<TreeNode*> v;
            queue<TreeNode*> temp(q);
            while(!temp.empty()){
                TreeNode * top = q.front();
                temp.pop();
                q.pop();
                v.push_back(top->left);
                if(top->left != NULL){
                    q.push(top->left);
                }
                v.push_back(top->right);
                if(top->right != NULL){
                    q.push(top->right);
                }
            }
            if(!checkSymmetric(v)){
                return false;
            }
        }
        return true;
    }
};
