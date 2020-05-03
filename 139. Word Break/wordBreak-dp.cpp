/*
Runtime: 8 ms, faster than 79.97% of C++ online submissions for Word Break.
Memory Usage: 9.4 MB, less than 86.79% of C++ online submissions for Word Break.
*/
class Solution {
public:
    bool wordBreakAux(string s, unordered_set<string> &set) {
        if(set.size()==0) return false;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        int start = 0;
        for(int i=1;i<=s.size();i++) {
            for(int j=i-1;j>=0;j--) {
                if(dp[j]) {
                    string word = s.substr(j,i-j);
                    if(set.find(word)!= set.end()) {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreakAux(s, set);
    }
};