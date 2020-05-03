/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Break.
Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Word Break.
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;
        vector<bool> visited(s.length(), false);
        unordered_set<string> set;
        int l = 0;
        for(string& k : wordDict){
            set.insert(k);
            int a = k.length();
            l = max(l, a);
        }
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(visited[i] == false){
                string s2 = "";
                for(int j = i; j < s.length() && j - i < l; j++){
                    s2 += s[j];
                    if(set.find(s2) != set.end()){
                        if(j == s.length() - 1) return true;
                        q.push(j + 1);
                    }
                }
            }
            visited[i] = true;
        }
        return false;
    }

};