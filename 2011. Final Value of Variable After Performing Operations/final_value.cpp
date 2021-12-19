/*
Runtime: 26 ms, faster than 6.23% of C++ online submissions for Concatenation of Array.
Memory Usage: 12.5 MB, less than 70.07% of C++ online submissions for Concatenation of Array.
*/

#include <vector>
#include <string>

using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;
    for(string s : operations){
        if(s == "++X" || s == "X++") ans++;
        else ans--;
    }
    return ans;
}

int main(){
  return 0;
}
