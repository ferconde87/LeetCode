/*
Runtime: 12 ms, faster than 77.13% of C++ online submissions for Roman to Integer.
Memory Usage: 8.4 MB, less than 72.55% of C++ online submissions for Roman to Integer.
*/
class Solution {
public:
    int 	romanToInt(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        while(i < n){
            char c = s[i];
            if (c == 'M')ans += 1000;
            else if (c == 'D') ans += 500;
            else if (c == 'C'){
                if (i < n-1){
                    if (s[i+1] == 'D') {ans += 400; ++i;}
                    else if (s[i+1] == 'M') {ans += 900; ++i;}
                    else ans+= 100;
                }else{
                    ans += 100;
                }
            }
            else if (c == 'L') ans += 50;
            else if (c == 'X'){
                if (i < n-1){
                    if (s[i+1] == 'L') {ans += 40; ++i;}
                    else if (s[i+1] == 'C') {ans += 90; ++i;}
                    else ans+= 10;
                }else{
                    ans += 10;
                } 
            }
            else if (c == 'V') ans += 5;
            else{
                if (i < n-1){
                    if (s[i+1] == 'V') {ans += 4; ++i;}
                    else if (s[i+1] == 'X') {ans += 9; ++i;}
                    else ans+= 1;
                }else{
                    ans += 1;
                }
            }
            ++i;
        }
        return ans;
    }
};
