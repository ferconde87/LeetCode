/*
Runtime: 180 ms, faster than 5.63% of C++ online submissions for Count Binary Substrings.
Memory Usage: 259.5 MB, less than 25.00% of C++ online submissions for Count Binary Substrings.
*/
class Solution {
public:
    int countBinarySubstrings(string s) {
        stack<int> s0;
        stack<int> s1;
        int count = 0;
        bool one = false;
        bool zero = false;
        for(char c : s){
            if(c == '0'){
                if(one){
                    s0 = {};
                    one = false;
                }
                s0.push(0);
                zero = true;
                if(!s1.empty()){
                    count++;
                    s1.pop();
                }
                
            }else{
                if(zero){
                    s1 = {};
                    zero = false;
                }
                s1.push(1);
                one = true;
                if(!s0.empty()){
                    count++;
                    s0.pop();
                }
            }
        }
        return count;
    }
};
