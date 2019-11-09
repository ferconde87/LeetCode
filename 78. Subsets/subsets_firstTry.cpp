/*
Runtime: 8 ms, faster than 55.95% of C++ online submissions for Subsets.
Memory Usage: 9.2 MB, less than 74.58% of C++ online submissions for Subsets.
*/
void subsetsRec(vector<vector<int>> & result, vector<int> & temp, vector<int> & nums, int start){
    result.push_back(temp);
    for(int i = start; i < nums.size(); ++i){
        temp.push_back(nums[i]);
        subsetsRec(result, temp, nums, i+1);
        temp.erase(temp.end()-1);
    }
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        subsetsRec(result, temp, nums, 0);
        return result;
    }
};
