/*
Runtime: 392 ms, faster than 5.15% of C++ online submissions for Daily Temperatures.
Memory Usage: 17.9 MB, less than 8.00% of C++ online submissions for Daily Temperatures.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> temp_indices[101];
        for(int i = 0; i < n; ++i){
            temp_indices[T[i]].push_back(i);
        }
        vector<int> result(n,-1);
        int max_seen = INT_MIN;
        for(int i = n-1; i >= 0; --i){
            if(T[i] >= max_seen){
                result[i] = 0;
                max_seen = T[i];
            }
        }
        for(int i = 0; i < n; ++i){
            if(result[i] == 0) continue;
            int t = T[i];
            int min_j = n;
            for(int k = t+1; k <= 100; ++k){
                if(temp_indices[k].size()==0) continue;
                if(temp_indices[k].back() < i) continue;
                int cur = *upper_bound(temp_indices[k].begin(), temp_indices[k].end(),i);
                if(cur < min_j) min_j = cur;
            }
            result[i] = min_j - i;
        }
        return result;
    }
};
