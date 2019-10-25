class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n);
        if(n==0) return;
        sum[0] = nums[0];
        for(int i = 1; i < n; ++i){
            sum[i] = sum[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return sum[j];
        return sum[j] - sum[i-1]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
