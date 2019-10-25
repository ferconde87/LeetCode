
int result_g = INT_MAX;

class Solution {
public:
    //assuming a.size() == b.size() && a != b
    bool diffEqualToOne(string a, string b){
        int n = a.size();
        int result = 0;
        for(int i = 0; i < n; ++i){
            if(a[i]!=b[i]) result++;
            if(result > 1) return false;
        }
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int result = 0;
        set<string> used;
        while(!q.empty()){
            int levelSize = q.size();
            result++;
            for(int i = 0; i < levelSize; i++){
                auto str = q.front();
                if(str == endWord) return result;
                q.pop();
                for(string w : wordList){
                    auto it = used.find(w);
                    if(it == used.end() && diffEqualToOne(str, w)){
                        q.push(w);
                        used.insert(w);
                    }
                }
            }
        }
        return 0;
    }
};
