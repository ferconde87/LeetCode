/*
Runtime: 4 ms, faster than 64.86% of C++ online submissions for Jewels and Stones.
Memory Usage: 8.6 MB, less than 33.75% of C++ online submissions for Jewels and Stones.
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> map;
        for(char c : S){
            auto it = map.find(c);
            if(it != map.end()){
                it->second++;
            }else{
                map[c] = 1;
            }
        }
        int result = 0;
        for(char c : J){
            auto it = map.find(c);
            if(it != map.end()){
                result += it->second;
            }
        }
        return result;
    }
};
