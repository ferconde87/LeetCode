/*
Runtime: 116 ms, faster than 70.62% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 15 MB, less than 43.33% of C++ online submissions for Find All Numbers Disappeared in an Array.*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int count[n+1] = {0};
        for(int x : nums)
            count[x]++;
        vector<int> result;
        for(int i = 1; i <= n; ++i)
            if(count[i] == 0)
                result.push_back(i);
        return result;
    }
};
