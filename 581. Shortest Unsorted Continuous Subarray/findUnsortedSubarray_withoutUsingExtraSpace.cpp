/*
Runtime: 32 ms, faster than 92.64% of C++ online submissions for Shortest Unsorted Continuous Subarray.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Shortest Unsorted Continuous Subarray.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n-1 && nums[i] <= nums[i+1]) ++i;
        if(i == n-1) return 0;
        int min_elem = *min_element(nums.begin()+i+1, nums.end());
        int l = 0;
        for(; l < i; ++l)
            if(nums[l] > min_elem) 
                break;
        int j = n-1;
        while(j > 0 && nums[j-1] <= nums[j]) --j;
        int max_elem = *max_element(nums.begin(), nums.begin()+j);
        int r = n-1;
        for(; r > j; --r)
            if(nums[r] < max_elem)
                break;
        return r - l + 1;
    }
};
