/*
Runtime: 8 ms, faster than 83.54% of C++ online submissions for Subsets II.
Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for Subsets II.
*/
void subsetsWithDupRec(vector<vector<int>> & result, vector<int> & temp, vector<int>& nums, int start, int end) {
    result.push_back(temp);
    for(int i = start; i < end; ++i){
        if(i > start && nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        subsetsWithDupRec(result, temp, nums, i+1, end);
        temp.erase(temp.end()-1);
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        subsetsWithDupRec(result,temp,nums,0,nums.size());
        return result;
    }
};
