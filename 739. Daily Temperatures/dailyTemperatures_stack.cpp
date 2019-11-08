/*
Runtime: 196 ms, faster than 59.86% of C++ online submissions for Daily Temperatures.
Memory Usage: 14.8 MB, less than 96.00% of C++ online submissions for Daily Temperatures.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> result(n);
        stack<int> s;
        for(int i = n-1; i >= 0; --i){
            while(!s.empty() && T[i] >= T[s.top()]) s.pop();
            result[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return result;
    }
};
