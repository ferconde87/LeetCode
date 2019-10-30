/*
Runtime: 8 ms, faster than 94.73% of C++ online submissions for Groups of Special-Equivalent Strings.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Groups of Special-Equivalent Strings.
*/
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> set;
        if(A.size() == 0) return 0;
        int n = A[0].size();
        int mid = n/2;
        if(n%2) mid++;
        int last = (n%2) ? n-1 : n-2;
        for(string s : A){
            for(int i = 1, j = last; i < j; i+=2, j-=2) swap(s[i],s[j]);
            sort(s.begin(), s.begin()+mid);
            sort(s.begin()+mid,s.end());
            set.insert(s);
        }
        return set.size();
    }
};
