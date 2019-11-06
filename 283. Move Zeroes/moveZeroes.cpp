/*
Runtime: 16 ms, faster than 61.88% of C++ online submissions for Move Zeroes.
Memory Usage: 9.5 MB, less than 88.89% of C++ online submissions for Move Zeroes.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i+1;
        while(j < n){
            while(i < n && nums[i]!=0) ++i;
            j = i + 1;
            while(j < n && nums[j]==0) ++j;
            if(j < n) swap(nums[i],nums[j]);
            i++;
        }
    }
};
