/*
Runtime: 116 ms, faster than 70.62% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 14.8 MB, less than 96.67% of C++ online submissions for Find All Numbers Disappeared in an Array.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0) nums[index] *= -1;//mark 'nums[i]' as seen
        }
        vector<int> result;
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0) // > 0 ==> not seen before
                result.push_back(i+1); 
        }
        return result;
    }
};
