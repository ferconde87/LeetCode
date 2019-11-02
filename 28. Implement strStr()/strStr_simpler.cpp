/*
Runtime: 1336 ms, faster than 5.99% of C++ online submissions for Implement strStr().
Memory Usage: 8.9 MB, less than 97.14% of C++ online submissions for Implement strStr().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int m = needle.size();
        int n = haystack.size();
        int i = 0;
        int j = 0;
        while(i < n){
            while(i + j < n && j < m && haystack[i+j] == needle[j]) ++j;
            if(j == m) return i;
            ++i;
            j = 0;
        }
        return -1;
    }
};

