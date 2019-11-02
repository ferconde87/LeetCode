/*
Runtime: 4 ms, faster than 95.07% of C++ online submissions for Longest Common Prefix.
Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Longest Common Prefix.
*/
class Solution {
public:
    int getSmallestSize(vector<string>& strs){
        int sizeSmallWord = strs[0].size();
        int n = strs.size();
        for(int i = 1; i < n; ++i)
            if(strs[i].size() < sizeSmallWord)
                sizeSmallWord = strs[i].size();
        return sizeSmallWord;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        int sizeSmallWord = getSmallestSize(strs);
        string ans = "";
        for(int j = 0; j < sizeSmallWord; ++j){
            char c = strs[0][j];
            for(int i = 1; i < n; ++i){
                if(strs[i][j] != c) return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
