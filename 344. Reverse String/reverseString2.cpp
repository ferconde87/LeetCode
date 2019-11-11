/*
Runtime: 52 ms, faster than 44.18% of C++ online submissions for Reverse String.
Memory Usage: 15.1 MB, less than 97.56% of C++ online submissions for Reverse String.
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        int i = 0;
        while(i < j){
            swap(s[i++],s[j--]);
        }
    }
};
