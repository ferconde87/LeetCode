/*Runtime: 20 ms, faster than 77.71% of C++ online submissions for Majority Element.
Memory Usage: 11.2 MB, less than 12.12% of C++ online submissions for Majority Element.*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int x : nums){
            auto it = m.find(x);
            if(it != m.end()){
                it->second++;
            }else{
                m[x] = 1;
            }
        }
        int result;
        int times = 0;
        for(auto pair : m){
            if(pair.second > times){
                times = pair.second;
                result = pair.first;
            }
        }
        return result;
    }
};
