/*
Runtime: 4 ms, faster than 96.43% of C++ online submissions for Fizz Buzz.
Memory Usage: 9.8 MB, less than 90.00% of C++ online submissions for Fizz Buzz.
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string multiple3 = "Fizz";
        string multiple5 = "Buzz";
        string multiple3and5 = "FizzBuzz";
        vector<string> result(n);
        for(int i = 1; i <= n; ++i){
            if(i % 3 == 0 && i % 5 == 0) result[i-1] = multiple3and5;
            else if(i % 3 == 0) result[i-1] = multiple3;
            else if(i % 5 == 0) result[i-1] = multiple5;
            else result[i-1] = to_string(i);
        }
        return result;
    }
};
