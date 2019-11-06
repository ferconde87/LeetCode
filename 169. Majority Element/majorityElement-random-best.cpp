/*
Runtime: 12 ms, faster than 99.24% of C++ online submissions for Majority Element.
Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Majority Element.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> dist(0,n-1);
        int mid = n / 2;
        while(true){
            int index = dist(rng);
            int candidate = nums[index];
            int count = 0;
            for(int x : nums){
                if(x == candidate) count++;
            }
            if(count > mid) return candidate;
        }
        return nums[0];
    }
};
