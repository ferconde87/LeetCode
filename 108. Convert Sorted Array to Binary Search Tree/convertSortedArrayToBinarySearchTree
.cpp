
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
    
    TreeNode* bstRec(vector<int> v, int l, int r){
        if(r < 0 || l > r) return NULL;
        int mid = (l+r)/2;
        int val = v[mid];
        TreeNode * node = new TreeNode(val);
        node->left = bstRec(v,l,mid-1);
        node->right = bstRec(v,mid+1,r);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bstRec(nums, 0, nums.size()-1);
    }
};
