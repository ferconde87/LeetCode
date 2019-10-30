/*
Runtime: 4 ms, faster than 91.75% of C++ online submissions for Maximum Number of Balloons.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Maximum Number of Balloons.
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {0};
        for(char c : text){
            count[c-'a']++;
        }
        int lo = min(count[11], count[14])/2;
        int ban = min(count[1], min(count[0],count[13]));
        return min(lo,ban);
    }
};
