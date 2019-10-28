/*
Runtime: 4 ms, faster than 58.45% of C++ online submissions for Split a String in Balanced Strings.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Split a String in Balanced Strings.
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int result = 0;
        for(char c : s){
            if(c == 'R') count++;
            else count--;
            if(count == 0) result++;
        }
        return result;
    }
};
