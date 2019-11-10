/*
Runtime: 16 ms, faster than 46.66% of C++ online submissions for Palindromic Substrings.
Memory Usage: 9.6 MB, less than 48.00% of C++ online submissions for Palindromic Substrings.
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        bool dp[n][n];
        for(int j = 0; j < n; ++j) 
            for(int i = j; i < n; ++i) dp[i][j] = true;
        int count = n;
        for(int l = 1; l < n; ++l){
            for(int i = 0; i < n-l; ++i){
                dp[i][i+l] = (s[i] == s[i+l]) && dp[i+1][i+l-1];
                if(dp[i][i+l]) count++;
            }
        }
        return count;
    }
};
