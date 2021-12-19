/*
Runtime: 26 ms, faster than 6.23% of C++ online submissions for Concatenation of Array.
Memory Usage: 12.5 MB, less than 70.07% of C++ online submissions for Concatenation of Array.
*/

#include <vector>

using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans(2*n);
  for(int i=0; i < n; ++i) ans[i] = nums[i];
  for(int i=0; i < n; ++i) ans[i+n] = nums[i];
  return ans;
}

int main(){
  return 0;
}
