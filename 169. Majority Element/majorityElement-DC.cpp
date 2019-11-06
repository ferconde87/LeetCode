/*
Runtime: 28 ms, faster than 24.61% of C++ online submissions for Majority Element.
Memory Usage: 11.3 MB, less than 6.06% of C++ online submissions for Majority Element.*/
class Solution {
public:
    int majorityElement(vector<int>&nums, int lo, int hi){
        if(lo == hi) return nums[lo];
        int mid = ((hi-lo)/2) + lo;
        int left = majorityElement(nums,lo,mid);
        int right = majorityElement(nums,mid+1,hi);
        if(left == right) return left;
        
        auto it = nums.begin();
        int leftCount = count(it+lo, it+hi+1, left);
        int rightCount = count(it+lo, it+hi+1, right);
        return leftCount > rightCount ? left : right;
    }
    
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums,0,nums.size()-1);
    }
};
