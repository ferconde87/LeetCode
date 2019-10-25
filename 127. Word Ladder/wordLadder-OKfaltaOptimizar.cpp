
//I did two BFS one from beginWord other from endWord hoping to find the solution quickly that one BFS from beginWord (but nope)
//But I didn't optimize the second BFS (starting from endWord)

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
        queue<string> qb;
        qb.push(beginWord);
        queue<string> qe;
        qe.push(endWord);
        int resultB = 0;
        int resultE = 1;
        unordered_set<string> usedB;
        unordered_set<string> usedE;
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end()) return 0;
        usedE.insert(endWord);
        int n = wordList.size();
        while(!qb.empty() or !qe.empty()){
            int levelSize = qb.size();
            resultB++;
            for(int i = 0; i < levelSize; i++){
                auto str = qb.front();
                qb.pop();
                int j = 0;
                while(j < n){
                    string w = wordList[j];
                    auto it = usedB.find(w);
                    if(it == usedB.end() && diffEqualToOne(str, w)){
                        qb.push(w);
                        usedB.insert(w);
                        swap(wordList[j],wordList[n-1]);
                        n--;
                    }else{
                        j++;
                    }
                }
            }
            for(auto sb : usedB){
                auto it = usedE.find(sb);
                if(it != usedE.end()){
                    return resultB + resultE;
                }
            }
            resultE++;
            int levelSizeEnd = qe.size();
            for(int i = 0; i < levelSizeEnd; i++){
                auto str = qe.front();
                qe.pop();
                for(string w : wordList){
                    auto it = usedE.find(w);
                    if(it == usedE.end() && diffEqualToOne(str, w)){
                        qe.push(w);
                        usedE.insert(w);
                    }
                }
            }
            for(auto se : usedE){
                auto it = usedB.find(se);
                if(it != usedB.end()){
                    return resultB + resultE;
                }
            }
            
        }
        return 0;
    }
};
