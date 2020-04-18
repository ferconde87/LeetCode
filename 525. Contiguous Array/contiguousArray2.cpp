/*
Runtime: 144 ms, faster than 83.93% of C++ online submissions for Contiguous Array.
Memory Usage: 18.9 MB, less than 100.00% of C++ online submissions for Contiguous Array.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, pair<int, int> > map;
        int max_len = 0;
        int n = nums.size();
        map[0] = {-1, INT_MIN};
        int count = 0;
        for(int i = 0; i < n; ++i){
            count += (nums[i] == 0) ? -1 : 1;
            auto it = map.find(count);
            if(it != map.end()){
                it->second.second = i;
                max_len = max(max_len, i - it->second.first);
            }else{
                pair<int, int> p(i, INT_MIN);
                map[count] = p;
            }
        }
        
        return max_len;
    }
};