/*
Runtime: 8 ms, faster than 98.72% of C++ online submissions for Permutations.
Memory Usage: 9.2 MB, less than 95.52% of C++ online submissions for Permutations.
*/
void permuteRec(vector<vector<int> > & result, vector<int> & nums, int start, int end){
    result.push_back(nums);
    for(int i = start; i < end-1; ++i){
        for(int j = i+1; j < end; ++j){
            swap(nums[i], nums[j]);
            permuteRec(result, nums, i+1, end);
            swap(nums[i], nums[j]);
        }
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRec(result, nums, 0, nums.size());
        return result;
    }
};
