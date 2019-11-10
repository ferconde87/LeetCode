/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Jewels and Stones.
Memory Usage: 8.3 MB, less than 87.50% of C++ online submissions for Jewels and Stones.
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count[58] = {0};
        for(char c : S) count[c-'A']++;
        int result = 0;
        for(char c : J) result+=count[c-'A'];
        return result;
    }
};
