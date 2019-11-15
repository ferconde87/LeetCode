/*
Runtime: 24 ms, faster than 33.73% of C++ online submissions for Combination Sum.
Memory Usage: 14.3 MB, less than 38.89% of C++ online submissions for Combination Sum.
*/
void combinationSumRec(vector<vector<int>> & result, vector<int> & temp, vector<int> & candidates, int i, int n, int sum, int target){
    if(sum > target) return;
    
    if(sum == target){
        result.push_back(temp);
        return;
    }
    
    if(i == n) return;
    
    temp.push_back(candidates[i]);
    sum += candidates[i];
    combinationSumRec(result, temp, candidates, i, n, sum, target);
    temp.pop_back();
    sum -= candidates[i];
    combinationSumRec(result, temp, candidates, i+1, n, sum, target);
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        combinationSumRec(result, temp, candidates, 0, candidates.size(), 0, target);
        return result;
    }
};
