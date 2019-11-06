/*
Runtime: 20 ms, faster than 21.77% of C++ online submissions for Move Zeroes.
Memory Usage: 9.6 MB, less than 52.78% of C++ online submissions for Move Zeroes.
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
            if(j < n){
                nums[i] = nums[j];
                nums[j] = 0;
            }
            i++;
        }
    }
};
