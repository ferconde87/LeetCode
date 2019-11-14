/*
Runtime: 272 ms, faster than 17.43% of C++ online submissions for Combinations.
Memory Usage: 20.6 MB, less than 40.00% of C++ online submissions for Combinations.
*/
void combineRec(vector<vector<int> > & result, vector<int> & temp, int x, int size, int n, int k){
    if(x > n) return;
    
    if(size == k){
        result.push_back(temp);
        return;
    }
    
    temp.push_back(x+1);
    combineRec(result, temp, x+1, size+1, n, k);
    temp.erase(temp.end()-1);
    combineRec(result, temp, x+1, size, n, k);
}


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> temp;
        combineRec(result, temp, 0, 0, n, k);
        return result;
    }
};
