/*[Disclaimer: the same perfomance than the recursive a]pproach, hmm]
Runtime: 16 ms, faster than 30.54% of C++ online submissions for Singut gle Element in a Sorted Array.
Memory Usage: 11.2 MB, less than 7.14% of C++ online submissions for Single Element in a Sorted Array.
*/
class Solution {
public:
    //pre: such a single non duplicate exists
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        while(true){
            int mid = lo + (hi-lo)/2;
            int prev = mid-1;
            int next = mid+1;
            if((prev==-1 || nums[prev]!=nums[mid]) && (next==n || nums[next]!=nums[mid])) return nums[mid];
            if(mid%2){
                if(prev==-1 || nums[prev] == nums[mid]){
                    lo = mid+1;
                }else{
                    hi = mid-1;
                }
            }else{
                if(next==n || nums[mid]==nums[next]){
                    lo = mid+1;
                }else{
                    hi = mid-1;
                }
            }
        }
        return 0;
    }
}; 