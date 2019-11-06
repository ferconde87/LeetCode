/*
Runtime: 16 ms, faster than 67.57% of C++ online submissions for Single Number.
Memory Usage: 9.7 MB, less than 95.06% of C++ online submissions for Single Number.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int x : nums){
            result ^= x;
        }
        return result;
    }
};
