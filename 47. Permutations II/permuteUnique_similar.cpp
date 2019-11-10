/*
Runtime: 28 ms, faster than 36.39% of C++ online submissions for Permutations II.
Memory Usage: 10.8 MB, less than 28.57% of C++ online submissions for Permutations II.

éste no chequea ésto:             if(nums[i] == nums[j]) continue;
el código queda más prolijo, con un sólo 'if' pero al ser más costoso buscar en el set que el 'if' anterior,
es más lento ;)



*/
void permuteUniqueRec(vector<vector<int>> & result, vector<int> & nums, int start,  int end){
    result.push_back(nums);
    for(int i = start; i < end-1; ++i){
        unordered_set<int> set({nums[i]});
        for(int j = i+1; j < end; ++j){
            if(set.find(nums[j])!=set.end()) continue;
            set.insert(nums[j]);
            swap(nums[i],nums[j]);
            permuteUniqueRec(result,nums,i+1,end);
            swap(nums[j],nums[i]);
        }
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permuteUniqueRec(result, nums, 0, nums.size());
        return result;
    }
};

