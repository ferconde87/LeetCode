/*
Runtime: 28 ms, faster than 26.61% of C++ online submissions for Remove K Digits.
Memory Usage: 21.5 MB, less than 9.09% of C++ online submissions for Remove K Digits.
*/

class Solution {
    int findMinimum(string num, int lo, int hi){
        char curMin = num[lo];
        int minIndex = lo;
        for(int i = lo+1; i <= hi; ++i){
            if(num[i] < curMin){
                curMin = num[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    
public:
    string removeKdigits(string num, int k){
        int n = num.size();
        int lo = 0;
        int hi = k;
        if(hi >= n) return "0";
        string result;
        int minIndex = -1;
        while(k > 0){
            minIndex = findMinimum(num, lo, hi);
            if(!result.empty() || num[minIndex] != '0'){
                result.push_back(num[minIndex]);
            }
            k -= minIndex - lo;
            lo = minIndex+1;
            hi = lo+k;
            if(hi >= n) break;//we delete the remainder
        }
        if(k == 0){
            //we need to copy the rest, we can't delete anymore
            for(int i = minIndex+1; i < n; ++i) {
                if(result.empty() && num[i] == '0') continue;
                result.push_back(num[i]);
            }
        }
        if(result.empty() && num[n-1] == '0') result.push_back('0');
        return result;
    }
};