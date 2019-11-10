/*
Runtime: 4 ms, faster than 64.86% of C++ online submissions for Jewels and Stones.
Memory Usage: 8.3 MB, less than 91.25% of C++ online submissions for Jewels and Stones.
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for(char j : J)
            for(char s : S)
                if(j == s)
                    count++;
        return count;
    }
};
