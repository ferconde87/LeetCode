class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> result;
        for(int x : nums){
            auto it = s.find(x);
            if(it != s.end()){
                result.push_back(x);
            }else{
                s.insert(x);
            }
        }
        return result;
    }
};
