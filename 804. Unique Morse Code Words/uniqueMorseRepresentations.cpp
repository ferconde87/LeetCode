/*
Runtime: 4 ms, faster than 81.73% of C++ online submissions for Unique Morse Code Words.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Unique Morse Code Words.
*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string char_morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> transformations;
        for(string s : words){
            string cur = "";
            for(char c : s){
                cur += char_morse[c-'a'];
            }
            transformations.insert(cur);
        }
        return transformations.size();
    }
};
