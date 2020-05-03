class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        int n = s.size();
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int from = q.front();
            q.pop();
            for(int k = 1; k <= n-from; ++k){
                bool is = set.find(s.substr(from, k)) != set.end();
                if(is){
                    if(from+k==n) return true;
                    q.push(from+k);
                }
            }
        }
        return false;
    }
};