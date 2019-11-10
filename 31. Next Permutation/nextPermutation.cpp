/*
Runtime: 8 ms, faster than 75.39% of C++ online submissions for Next Permutation.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Next Permutation.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i >= 1 && nums[i-1] >= nums[i]) i--;
        reverse(nums.begin()+i,nums.end());
        if(i > 0){
            int j = upper_bound(nums.begin()+i, nums.end(), nums[i-1]) - nums.begin();
            swap(nums[i-1],nums[j]);
        }
    }
};
