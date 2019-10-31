/*
Runtime: 40 ms, faster than 66.35% of C++ online submissions for Count Binary Substrings.
Memory Usage: 12.8 MB, less than 25.00% of C++ online submissions for Count Binary Substrings.
*/
class Solution
{
public:
    int countBinarySubstrings(string s) {
        int s0 = 0;
        int s1 = 0;
        int count = 0;
        bool one = false;
        bool zero = false;
        for(char c : s){
            if(c == '0'){
                if(one){
                    s0 = 0;
                    one = false;
                }
                ++s0;
                zero = true;
                if(s1 > 0){
                    ++count;
                    --s1;
                }
                
            }else{
                if(zero){
                    s1 = 0;
                    zero = false;
                }
                ++s1;
                one = true;
                if(s0 > 0){
                    ++count;
                    --s0;
                }
            }
        }
        return count;
    }
};

