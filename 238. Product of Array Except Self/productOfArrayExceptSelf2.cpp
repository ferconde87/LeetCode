/*
Runtime: 44 ms, faster than 25.96% of C++ online submissions for Product of Array Except Self.
Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Product of Array Except Self.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int l = nums[0];
        int r = nums[n-1];
        for(int i = 1; i < n; ++i){
            res[i] = l;
            l *= nums[i];
        }
        for(int i = n-2; i >= 0; --i){
            res[i] *= r;
            r *= nums[i];
        }
        return res;
    }
};