/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Roman to Integer.
Memory Usage: 8.3 MB, less than 89.22% of C++ online submissions for Roman to Integer.
*/
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int i = n - 1;
        int ans = 0;
        while(i >= 0){
            char c = s[i];
            if (c == 'M')ans += 1000;
            else if (c == 'D') ans += 500;
            else if (c == 'C')
                if (i < n-1 && (s[i+1] == 'D' || s[i+1] == 'M')) ans -= 100;
                else ans += 100;
            else if (c == 'L') ans += 50;
            else if (c == 'X')
                if (i < n-1 && (s[i+1] == 'L' || s[i+1] == 'C')) ans -= 10;
                else ans += 10;
            else if (c == 'V') ans += 5;
            else
                if (i < n-1 && (s[i+1] == 'V' || s[i+1] == 'X')) ans -= 1;
                else ans += 1;
            --i;
        }
        return ans;
    }
};
