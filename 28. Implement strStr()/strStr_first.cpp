/*
Runtime: 1336 ms, faster than 5.99% of C++ online submissions for Implement strStr().
Memory Usage: 9.2 MB, less than 50.00% of C++ online submissions for Implement strStr().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        if(m == 0) return 0;
        int n = haystack.size();
        int i = 0;
        int j = 1;
        while(i < n){
            if(haystack[i] != needle[0]){
                ++i;
            }else{
                while(i + j < n && j < m &&haystack[i+j] == needle[j]){
                    ++j;
                }
                if(j == m) return i;
                ++i;
                j = 1;
            }
        }
        return -1;
    }
};
