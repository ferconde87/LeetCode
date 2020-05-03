class Solution {
public:
    bool wordBreakAux(string s, unordered_set<string> & wordDict){
        if(s == "") return true;
        int n = s.size();
        for(int i = 1; i <= n; ++i){
            bool found = wordDict.find(s.substr(0,i)) != wordDict.end();
            if(found && wordBreakAux(s.substr(i, n-i), wordDict)){
                return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreakAux(s, set);
    }
};