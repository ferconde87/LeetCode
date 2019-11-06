/*
Runtime: 116 ms, faster than 70.62% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 14.8 MB, less than 96.67% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int k = 0; k < 4; ++k){
            for(int i = 0; i < n; ++i){
                if(nums[i] != i+1){
                    swap(nums[nums[i]-1], nums[i]);
                }
            }
        }
        vector<int> result;
        for(int i = 0; i < n; ++i){
            if(nums[i] != i+1) result.push_back(i+1);
        }
        return result;
        
    }
};
