/*
Runtime: 24 ms, faster than 70.08% of C++ online submissions for Permutations II.
Memory Usage: 10.2 MB, less than 52.38% of C++ online submissions for Permutations II.
*/
void permuteUniqueRec(vector<vector<int>> & result, vector<int> & nums, int start,  int end){
    result.push_back(nums);
    for(int i = start; i < end-1; ++i){
        unordered_set<int> set;
        for(int j = i+1; j < end; ++j){
            if(set.find(nums[j])!=set.end()) continue;
            if(nums[i] == nums[j]) continue;
            set.insert(nums[j]);
            swap(nums[i],nums[j]);
            permuteUniqueRec(result,nums,i+1,end);
            swap(nums[j],nums[i]);
        }
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permuteUniqueRec(result, nums, 0, nums.size());
        return result;
    }
};
