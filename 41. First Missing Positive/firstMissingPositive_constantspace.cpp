/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
Memory Usage: 8.7 MB, less than 82.00% of C++ online submissions for First Missing Positive.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
            if(nums[i] <= 0)
                nums[i] = n+2;
        
        for(int i = 0; i < n; ++i){
            int index = abs(nums[i]) - 1;
            if(index < n && nums[index] > 0) nums[index] *= -1;
        }
        
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0)
                return i+1;
        }
        
        return n+1;
    }
};
