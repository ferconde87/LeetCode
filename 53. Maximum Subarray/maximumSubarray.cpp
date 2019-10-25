class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return INT_MIN;
        int max_value = *max_element(nums.begin(), nums.end());
        if(max_value < 0){
            return max_value;
        }
        int current = 0;
        int result = 0;
        for(int x : nums){
            current = max(current+x,0);
            if(current > result) result = current;
        }
        return result;
    }
};
