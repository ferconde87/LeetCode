/*
Runtime: 28 ms, faster than 24.61% of C++ online submissions for Majority Element.
Memory Usage: 11.1 MB, less than 81.82% of C++ online submissions for Majority Element
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
