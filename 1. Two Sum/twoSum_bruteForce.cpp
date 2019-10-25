#include <bits/stdc++.h>

using namespace std;

//Time complexity : O(n^2)
//Space complexity : O(1)

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; i < n; j++){
            if(nums[i]+nums[j]==target)
                return {i,j};
        }
    }
    return vector<int>();
}

int main(){

    return 0;
}