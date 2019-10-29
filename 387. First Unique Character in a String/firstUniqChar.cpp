/*
Runtime: 48 ms, faster than 62.61% of C++ online submissions for First Unique Character in a String.
Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for First Unique Character in a String.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int count[26] = {0};
        for(char c : s) count[c-'a']++;
        for(int i = 0; i < n; ++i) if(count[s[i]-'a']==1) return i;
        return -1;
    }
};
