class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;
        int r = n-1;
        int l;
        bool found = false;
        for(; r >= 1; --r){
            for(l = r-1; l >= 0; --l){
                if(nums[l] < nums[r]){
                    found = true;
                    break;
                } 
            }
            if(found) break;
        }
        if(!found){
            reverse(nums.begin(), nums.end());
            return;
            
        } 
        swap(nums[l],nums[r]);
        sort(nums.begin()+l+1,nums.end());
    }
};
