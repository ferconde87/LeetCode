class Solution {
public:
    bool checkValidStringAux(string str, int start, int end, int open){
        for(int i = start; i < end; ++i){
            char c = str[i];
            if(c == '('){
                open++;
            }else if(c == ')'){
                if(open == 0) return false;
                open--;
            }else{            
                return checkValidStringAux(str, i+1, end, open) || checkValidStringAux(str, i+1, end, open+1) 
                    || (open > 0 && checkValidStringAux(str, i+1, end, open-1));
            }
        }
        return open == 0;
    }
    
    bool checkValidString(string str) {
        return checkValidStringAux(str, 0, str.size(), 0);            
    }
};