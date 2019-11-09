/*
Runtime: 4 ms, faster than 97.89% of C++ online submissions for Subsets.
Memory Usage: 9 MB, less than 94.92% of C++ online submissions for Subsets.
*/
void subsetsRec(vector<vector<int>> & result, vector<int> & temp, vector<int> & nums, int start, int end){
    result.push_back(temp);
    for(int i = start; i < end; ++i){
        temp.push_back(nums[i]);
        subsetsRec(result, temp, nums, i+1, end);
        temp.erase(temp.end()-1);
    }
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        subsetsRec(result, temp, nums, 0, nums.size());
        return result;
    }
};
