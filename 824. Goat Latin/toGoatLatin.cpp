/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Goat Latin.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Goat Latin.
*/
class Solution {
public:
    bool isVowel(char ch){
        char c = tolower(ch);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string toGoatLatin(string S) {
        stringstream s(S);
        string word;
        int i = 1;
        string result;
        if(S == " ") result = " ";
        while(s >> word){
            char c = word[0];
            if(!isVowel(c)){
                //remove the first letter and append it to the end
                word.erase(0,1);
                word.push_back(c);
            }           
            word+="ma";
            string as(i,'a');
            i++;
            word+=as;
            result+=word;
            result+=" ";
        }
        result.erase(result.size()-1);
        return result;
    }
};
