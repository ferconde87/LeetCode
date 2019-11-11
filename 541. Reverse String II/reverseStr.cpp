/*
Runtime: 8 ms, faster than 66.82% of C++ online submissions for Reverse String II.
Memory Usage: 9.5 MB, less than 70.00% of C++ online submissions for Reverse String II.
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int m = 2*k;
        for(int i = 0; i < n; i+= m){
            reverse(s.begin()+i, s.begin()+min(i+k,n));
        }
        return s;
    }
};
