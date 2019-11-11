/*
Runtime: 8 ms, faster than 59.38% of C++ online submissions for Fizz Buzz.
Memory Usage: 10.6 MB, less than 26.67% of C++ online submissions for Fizz Buzz.
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string multiple3 = "Fizz";
        string multiple5 = "Buzz";
        string multiple3and5 = "FizzBuzz";
        vector<string> result;
        for(int i = 1; i <= n; ++i){
            if(i % 3 == 0 && i % 5 == 0) result.push_back(multiple3and5);
            else if(i % 3 == 0) result.push_back(multiple3);
            else if(i % 5 == 0) result.push_back(multiple5);
            else result.push_back(to_string(i));
        }
        return result;
    }
};
