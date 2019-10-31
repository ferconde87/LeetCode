/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotated Digits.
Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Rotated Digits.
*/
class Solution {
public:
    
    bool notValid(int x){
        return x == 3 || x == 4 || x == 7;
    }

    bool makeItDifferent(int x){
        return x == 2 || x == 5 || x == 6 || x == 9;
    }
    
    int rotatedDigits(int N) {
        int count = 0;
        for(int i = 1; i <= N; ++i){
            bool ok = false;
            int num = i;
            while(num != 0){
                int digit = num % 10;
                if(notValid(digit)){
                    ok = false;
                    break;
                }
                if(makeItDifferent(digit)) ok = true;
                num /= 10;
            }
            if(ok) count++;
        }
        return count;
    }
};
