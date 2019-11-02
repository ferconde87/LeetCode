/*
Runtime: 4 ms, faster than 58.66% of C++ online submissions for Valid Parentheses.
Memory Usage: 8.5 MB, less than 75.19% of C++ online submissions for Valid Parentheses.
*/
class Solution {
public:
    
    bool isOpen(char c){
        return c == '(' || c == '{' or c == '[';
    }
    
    bool openClose(char open_c, char close_c){
        if(open_c == '(') return close_c == ')';
        if(open_c == '{') return close_c == '}';
        else return close_c == ']';
    }
    
    bool isValid(string str) {
        stack<char> s;
        for(char c : str){
            if (isOpen(c)) {
                s.push(c);
            } else {
                if(s.empty()) { return false; }
                else{
                    char open_c = s.top();
                    if(!openClose(open_c, c)) { return false; }
                    else { s.pop(); }
                }
            }
        }
        return s.empty();
    }
};
