/*
Runtime: 20 ms, faster than 86.86% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
*/
class Solution {
public:
    int f(string s){
        int minc = 'z';
        int answer = 0;
        for(char c : s){
            if(c == minc) answer++;
            else if(c < minc){
                minc = c;
                answer = 1;
            }
        }
        return answer;
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
