
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
    
    
    int ladder(string b, string e, set<string> s, int result){
        if(b == e) {
            if(result < result_g){
                result_g = result;
            }
            return result;
        }
        if(s.empty()) return INT_MAX;
        for(auto it = s.begin(); it != s.end(); ){
            if(diffEqualToOne(b,*it)){
                string next = *it;
                s.erase(it++);
                if(result_g == result) return INT_MAX;
                ladder(next,e,s,result+1);
            }else{
                ++it;
            }
        }
        return INT_MAX;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        result_g = INT_MAX;
        set<string> set;
        for(auto s : wordList) set.insert(s);
        ladder(beginWord, endWord, set, 1);
        if(result_g == INT_MAX) return 0;
        return result_g;
    }
};
