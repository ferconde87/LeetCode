/*
Runtime: 12 ms, faster than 66.94% of C++ online submissions for Permutations.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Permutations.
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result({nums});
        while(next_permutation(nums.begin(), nums.end())){
            result.push_back(nums);
        }
        return result;
    }
};
