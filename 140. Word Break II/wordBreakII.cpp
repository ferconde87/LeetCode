/*
Runtime: 16 ms, faster than 80.67% of C++ online submissions for Word Break II.
Memory Usage: 14 MB, less than 63.64% of C++ online submissions for Word Break II.
*/
class Solution {
    //catsanddog
    //iter 0
    // q    0
    //iter 1
    //from 0
    //q     3,4
    //count [3]=1 / [4]=1
    //dp    0:{3,4}
    //iter 2
    //from 3
    //q     4,7
    //count [3]=1 / [4]=1 / [7]=1
    //dp    0:{3,4} / 3:{7}
    //iter 3
    //from 4
    //q     7,7
    //count [3]=1 / [4]=1 / [7]=2
    //dp    0:{3,4} / 3:{7} / 4:{7}
    //iter 4
    //from 7
    //q     7,10
    //count [3]=1 / [4]=1 / [7]=2 /[10]=1
    //dp    0:{3,4} / 3:{7} / 4:{7} / 7:{10}
    //iter 5
    //from 7
    //q     10
    //count[10]=2
    //iter 
    
 
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak2(string s, unordered_set<string>& dict) {
        if(m.find(s)!=m.end()) return m[s];
        vector<string> result;
        if(dict.find(s)!=dict.end()){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.find(word)!=dict.end()){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak2(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result;
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string> & dict){
        unordered_set<string> set(dict.begin(), dict.end());
        return wordBreak2(s, set);
    }
};