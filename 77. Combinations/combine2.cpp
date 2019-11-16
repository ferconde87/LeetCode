/*
Runtime: 172 ms, faster than 18.95% of C++ online submissions for Combinations.
Memory Usage: 20.7 MB, less than 40.00% of C++ online submissions for Combinations.
*/
void combineRec(vector<vector<int> > & result, vector<int> & temp, int x, int size, int n, int k){
    if(size == k){
        result.push_back(temp);
        return;
    }
    if(x > n) return;
    temp.push_back(x);
    combineRec(result, temp, x+1, size+1, n, k);
    temp.erase(temp.end()-1);
    combineRec(result, temp, x+1, size, n, k);
}


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> temp;
        combineRec(result, temp, 1, 0, n, k);
        return result;
    }
};
