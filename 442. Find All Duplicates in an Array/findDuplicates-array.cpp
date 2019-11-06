/*
Runtime: 132 ms, faster than 26.21% of C++ online submissions for Find All Duplicates in an Array.
Memory Usage: 15.2 MB, less than 20.00% of C++ online submissions for Find All Duplicates in an Array.
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count[n+1] = {0};
        vector<int> result;
        for(int x : nums)
            count[x]++;
        for(int i = 1; i <= n; ++i){
            if(count[i] == 2)
                result.push_back(i);
        }
        return result;
    }
};
