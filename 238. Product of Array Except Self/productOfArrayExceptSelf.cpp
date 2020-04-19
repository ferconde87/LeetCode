/*
Runtime: 88 ms, faster than 5.85% of C++ online submissions for Product of Array Except Self.
Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Product of Array Except Self.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n,1);
        vector<int> r(n,1);
        l[0] = nums[0];
        for(int i = 1; i < n; ++i){
            l[i] *= l[i-1]*nums[i];
        }
        
        r[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i){
            r[i] *= r[i+1]*nums[i];
        }
        
        vector<int> ans(n,1);
        ans[0] = r[1];
        for(int i = 1; i < n-1; ++i){
            ans[i] = r[i+1]*l[i-1];
        }
        ans[n-1] = l[n-2];
        return ans;
    }
};