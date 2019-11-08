/*
Runtime: 44 ms, faster than 44.52% of C++ online submissions for Shortest Unsorted Continuous Subarray.
Memory Usage: 11.2 MB, less than 42.86% of C++ online submissions for Shortest Unsorted Continuous Subarray.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums);
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        while(i < n && copy[i] == nums[i]) ++i;
        if(i == n) return 0;
        int j = n-1;
        while(j >= 0 && copy[j] == nums[j]) --j;
        return j - i + 1;
    }
};
