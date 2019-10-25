class Solution {
public:
    //assuming a.size() == b.size() && a != b
    bool diffEqualToOne(string & a, string & b){
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
        int n = wordList.size();
        while(!q.empty()){
            int levelSize = q.size();
            result++;
            for(int i = 0; i < levelSize; i++){
                auto str = q.front();
                if(str == endWord) return result;
                q.pop();
                int j = 0;
                while(j < n){
                    if(diffEqualToOne(str, wordList[j])){
                        q.push(wordList[j]);
                        --n;
                        swap(wordList[j],wordList[n]);
                    }else{
                        ++j;
                    }
                }
            }
        }
        return 0;
    }
};
