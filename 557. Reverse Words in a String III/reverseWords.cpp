/*
Runtime: 16 ms, faster than 96.53% of C++ online submissions for Reverse Words in a String III.
Memory Usage: 11.8 MB, less than 91.30% of C++ online submissions for Reverse Words in a String III.
*/
class Solution {
public:
    void reverse(string & s, int l, int r){
        int mid = (l+r) / 2;
        while(l <= mid){
            swap(s[l++],s[r--]);
        }
    }
    
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        while(i < n){
            size_t j = s.find(' ', i);
            if(j == string::npos) j = n;
            if(i < j) reverse(s, i, (int)j-1);
            i = j+1;
        }
        return s;
    }
};
