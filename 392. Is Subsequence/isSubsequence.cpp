class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        if(n == 0) return true;
        int index = 0;
        for(char c : t){
            char char_to_find = s[index];
            if(c == char_to_find){
                index++;
                if(index == n) return true;
            }
        }
        return false;
    }
};
