/*
Runtime: 20 ms, faster than 51.35% of C++ online submissions for Word Break.
Memory Usage: 13.1 MB, less than 54.72% of C++ online submissions for Word Break.
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n+1, false);
        dp[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int from = q.front();
            q.pop();
            for(int k = 1; k <= n-from; ++k){
                if(dp[from+k]) continue;
                bool is = set.find(s.substr(from, k)) != set.end();
                if(is){
                    if(from+k==n) return true;
                    dp[from+k] = true;
                    q.push(from+k);
                }
            }
        }
        return false;
    }
};