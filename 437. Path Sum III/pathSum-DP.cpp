/**
Runtime: 12 ms, faster than 97.66% of C++ online submissions for Path Sum III.
Memory Usage: 18.1 MB, less than 16.13% of C++ online submissions for Path Sum III.
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
    int pathSum(TreeNode* root, int current, int sum, unordered_map<int, int> & sum_count){
        if(root == NULL) return 0;
        
        current += root->val;
        int res = 0;
        auto it = sum_count.find(current-sum);
        if(it != sum_count.end()){
            res += it->second;
        }
        auto itCurrent = sum_count.find(current);
        if(itCurrent != sum_count.end()){
            itCurrent->second += 1;
        }else{
            sum_count[current] = 1;
        }
        res += pathSum(root->left, current, sum, sum_count);
        res += pathSum(root->right, current, sum, sum_count);
        
        sum_count[current]--;
        
        return res;
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sum_count({make_pair(0,1)});
        return pathSum(root, 0, sum, sum_count);
    }
};
