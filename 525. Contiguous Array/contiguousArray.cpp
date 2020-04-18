/*
Runtime: 152 ms, faster than 79.60% of C++ online submissions for Contiguous Array.
Memory Usage: 21.9 MB, less than 33.33% of C++ online submissions for Contiguous Array.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, pair<int, int> > map;
        int max_len = 0;
        int n = nums.size();
        
        vector<int> count(n+1, 0);
        for(int i = 0; i < n; ++i){
            count[i+1] = count[i] + (nums[i] == 0 ? -1 : 1); 
        }
        
        for(int i = 0; i < n+1; ++i){
            auto it = map.find(count[i]);
            if(it != map.end()){
                it->second.second = i;
                max_len = max(max_len, i - it->second.first);
            }else{
                pair<int, int> p(i, INT_MIN);
                map[count[i]] = p;
            }
        }
        
        return max_len;
    }
};