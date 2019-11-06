/*
Runtime: 112 ms, faster than 89.44% of C++ online submissions for Find All Duplicates in an Array.
Memory Usage: 14.7 MB, less than 100.00% of C++ online submissions for Find All Duplicates in an Array.
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n; ++i){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) result.push_back(index+1);
            else nums[index] *= -1;
        }
        return result;
    }
};
