/*
Runtime: 44 ms, faster than 92.40% of C++ online submissions for Reverse String.
Memory Usage: 15.1 MB, less than 98.78% of C++ online submissions for Reverse String.
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if (n <= 1) return;
        int j = n - 1;
        int i = 0;
        int mid = j/2;
        for(int i = 0; i <= mid; ++i){
            swap(s[i], s[j]);
            --j;
        }
    }
};
