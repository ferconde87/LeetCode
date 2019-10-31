class Solution {
public:
    int f(string s){
        char minc = *min_element(s.begin(), s.end());
        return count(s.begin(), s.end(), minc);
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int nq = queries.size();
        int n = words.size();
        vector<int> wordsGreater(12,0);
        for(string w : words)
            wordsGreater[f(w)]++;
            
        for(int i = 10; i >= 2; --i){
            wordsGreater[i-1] += wordsGreater[i];
        }
        
        vector<int> answer(nq);
        for(int i = 0; i < nq; ++i){
            answer[i] = wordsGreater[f(queries[i])+1];
        }
        
        return answer;
    }
};
