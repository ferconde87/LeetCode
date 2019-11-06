/*
Runtime: 112 ms, faster than 88.46% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 14.9 MB, less than 80.00% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            while(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
            ++i;
        }
        vector<int> result;
        for(int i = 0; i < n; ++i){
            if(nums[i] != i+1) result.push_back(i+1); 
        }
        return result;
    }
};
