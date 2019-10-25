#include <bits/stdc++.h>

using namespace std;


int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> char_per_index;
    int ans = 0;
    int cur = 0;
    int last_repeated = 0;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        auto it = char_per_index.find(c);
        if(it != char_per_index.end()){
            if(cur > ans){
                ans = cur;
            }
            last_repeated = max(it->second, last_repeated);
            cur = i - last_repeated;
            it->second = i;  
        }else{
            char_per_index[c] = i;
            cur++;

        }
    }
    
    return max(ans,cur);
    
}



int main(){




    return 0;
}