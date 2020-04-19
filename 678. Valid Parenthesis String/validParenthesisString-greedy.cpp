/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parenthesis String.
Memory Usage: 6.1 MB, less than 100.00% of C++ online submissions for Valid Parenthesis String.
*/

class Solution {
public:
    //* => 3 options nothing, '(' or ')'
    //lo => the minimum valid amount of '('
    //hi => the maximum amount of '('
    //if '(' => lo++ && hi++
    //if ')' => if(hi == 0) return false (is not possible to have a valid expression) else hi-- and lo = max(lo-1, 0)
    //if '*' => hi++ && lo = max(lo-1, 0) ... this way we consider the 3 options
    //and if lo == 0 => the '(' is equal to the ')' so we can have a valid expression
    bool checkValidString(string s){
        int lo = 0, hi = 0;
        for(char c : s){
            if(c == '('){
                lo++;
                hi++;
            }else{
                if(c == ')'){
                    if(hi == 0) return false;
                    hi--;
                }else{
                    hi++;
                }
                if(lo > 0) lo--;
            } 
        }
        return lo == 0;       
    }
};