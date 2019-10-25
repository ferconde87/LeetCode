class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n <= 2) return max(nums[0],nums[n-1]);
        int last_3 = nums[0];
        int last_2 = nums[1];
        int last = nums[2] + last_3;
        for(int i = 3; i < n; ++i){
            int temp = nums[i] + max(last_2, last_3);
            last_3 = last_2;
            last_2 = last;
            last = temp;
        }
        return max(last, last_2);
    }
};
