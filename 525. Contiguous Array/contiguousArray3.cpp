/*
Runtime: 244 ms, faster than 26.16% of C++ online submissions for Contiguous Array.
Memory Usage: 18.3 MB, less than 100.00% of C++ online submissions for Contiguous Array.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> map({{0,-1}});//only save the first occurrences
        int max_len = 0;
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; ++i){
            count += (nums[i] == 0) ? -1 : 1;
            auto it = map.find(count);
            if(it != map.end()){
                max_len = max(max_len, i - it->second);
            }else{
                map[count] = i;
            }
        }        
        return max_len;
    }
};