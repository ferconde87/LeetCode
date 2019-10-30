/*
Runtime: 4 ms, faster than 99.68% of C++ online submissions for Groups of Special-Equivalent Strings.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Groups of Special-Equivalent Strings.
*/
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> set;
        if(A.size() == 0) return 0;
        int n = A[0].size();
        for(string s : A){
            string t;
            for(int i = 0; i < n; i+=2) t.push_back(s[i]);
            for(int i = 1; i < n; i+=2) t.push_back(s[i]-32);
            sort(t.begin(), t.end());
            set.insert(t);
        }
        return set.size();
    }
};
