#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> map;
    int prev = 0;
    int next = 0;
    for(int e : nums){
        if(map.find(e)!=map.end()) continue;
        int cur = 1;
        if(e > INT_MIN){
            for(int prev = e-1; prev >= INT_MIN; prev--){
                auto itPrev = map.find(prev);
                if(itPrev == map.end()) break;
                itPrev->second++;
                cur = max(itPrev->second, cur);
            }
        }
        map[e] = cur;
        if(e < INT_MAX){
            for(int next = e+1; next <= INT_MAX; next++){
                auto itNext = map.find(next);
                if(itNext == map.end()) break;
                itNext->second += cur;
            }
        }
    }
    
    int ans = 0;
    for(auto pair : map){
        if(pair.second > ans){
            ans = pair.second;
        }
    }
    
    return ans;
}

int main(){

    return 0;
}