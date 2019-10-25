#include <bits/stdc++.h>

using namespace std;

//Time complexity : O(n)
//Space complexity : O(n)


vector<int> twoSum(vector<int>& nums, int target) {
    
    unordered_map<int, int> hashMap;
    
    for(int i = 0; i < nums.size(); i++){
        int x = nums[i];
        int y = target-x;
        auto it = hashMap.find(y);
        if(it!=hashMap.end()){
            return {i,it->second};
        }
        hashMap[x] = i;
    }
    
    return vector<int>();
}
int main(){

    return 0;
}