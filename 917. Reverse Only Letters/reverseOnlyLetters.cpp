/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.
Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Reverse Only Letters.
*/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.size() - 1;
        while(i < j){
            while(i < j && !isalpha(S[i])) ++i;
            while(i < j && !isalpha(S[j])) --j;
            swap(S[i++],S[j--]);
        }
        return S;
    }
};
