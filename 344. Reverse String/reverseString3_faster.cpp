/*
Runtime: 40 ms, faster than 97.31% of C++ online submissions for Reverse String.
Memory Usage: 15 MB, less than 100.00% of C++ online submissions for Reverse String.
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        int i = 0;
        while(i < j){
            swap(s[i],s[j]);
            ++i;
            --j;
        }
    }
};
