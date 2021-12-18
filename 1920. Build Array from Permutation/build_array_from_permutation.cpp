/*
Runtime: 26 ms, faster than 10.88% of C++ online submissions for Build Array from Permutation.
Memory Usage: 16.2 MB, less than 92.36% of C++ online submissions for Build Array from Permutation.
*/

#include <vector>

using namespace std;

vector<int> buildArray(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans(n);
  for(int i=0; i<n; ++i){
      ans[i] = nums[nums[i]];
  }
  return ans;
}

int main(){
  return 0;
}
