/*
Runtime: 4 ms, faster than 64.60% of C++ online submissions for First Missing Positive.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for First Missing Positive.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool seen[n+1] = {false};
        for(int x : nums){
            if(x > 0 && x < n+1)
                seen[x] = true;
        }
        for(int i = 1; i <= n; i++){
            if(!seen[i]) return i;
        }
        return n+1;
    }
};
