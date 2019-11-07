/**

Runtime: 92 ms, faster than 5.61% of C++ online submissions for Path Sum III.
Memory Usage: 77.6 MB, less than 6.45% of C++ online submissions for Path Sum III.

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
    unordered_map<TreeNode*, vector<int> > node_sums;
    int ans = 0;
    
    void getSums(TreeNode* node, int objective){
        if(node == NULL) return;
        
        getSums(node->left, objective);
        getSums(node->right, objective);
        
        vector<int> sums;
        int sum = node->val;
        if(sum == objective) ans++;
        sums.push_back(sum);
        
        if(node->left != NULL){
            vector<int> sumsl = node_sums[node->left]; 
            for(int x : sumsl){
                if(sum+x == objective) ans++;
                sums.push_back(sum+x);
            } 
        }
        
        if(node->right != NULL){
            vector<int> susmr = node_sums[node->right];
            for(int x : susmr){
                if(sum+x == objective) ans++;
                sums.push_back(sum+x);
            } 
        }
        
        node_sums[node] = sums;
    }
    
    
    int pathSum(TreeNode* root, int sum) {
        getSums(root, sum);
        return ans;
    }
};
