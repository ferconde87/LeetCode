/*
Runtime: 4 ms, faster than 52.48% of C++ online submissions for Longest Uncommon Subsequence I .
Memory Usage: 8.3 MB, less than 60.00% of C++ online submissions for Longest Uncommon Subsequence I .
*/
class Solution {
public:
    int findLUSlength(string a, string b) {        
        return a == b ? -1 : max(a.size(), b.size());
    }
};
