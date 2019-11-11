/*
Runtime: 4 ms, faster than 97.57% of C++ online submissions for Reverse String II.
Memory Usage: 9.5 MB, less than 70.00% of C++ online submissions for Reverse String II.
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int m = 2*k;
        auto it = s.begin();
        for(int i = 0; i < n; i+= m){
            reverse(it+i, it+min(i+k,n));
        }
        return s;
    }
};
