int k;
void print(vector<int> & temp, int i){
    cout << k++ << " > ";
    for(int x : temp) cout << x << " ";
    cout << "@ " << i << endl;
}

void printWithOutIncrementIteration(vector<int> & temp, int i){
    cout << "temp = ";
    for(int x : temp) cout << x << " ";
    cout << "@ i = " << i << endl;
}


void subsetsWithDupRec(vector<vector<int>> & result, vector<int> & temp, vector<int>& nums, int start, int end) {
    print(temp, start);
    result.push_back(temp);
    for(int i = start; i < end; ++i){
        bool dup = i > start && nums[i] == nums[i-1];
        if(dup){
            cout << "iteration = " << k << endl;
            cout << "   start = " << start << " > ";
            printWithOutIncrementIteration(temp,i);
            continue;
        } 
        temp.push_back(nums[i]);
        ++i;
        subsetsWithDupRec(result, temp, nums, i, end);
        --i;
        temp.erase(temp.end()-1);
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        k = 1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        subsetsWithDupRec(result,temp,nums,0,nums.size());
        return result;
    }
};
