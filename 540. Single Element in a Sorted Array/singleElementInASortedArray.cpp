/*
Runtime: 16 ms, faster than 30.54% of C++ online submissions for Single Element in a Sorted Array.
Memory Usage: 11.1 MB, less than 7.14% of C++ online submissions for Single Element in a Sorted Array.
*/

class Solution {
public:
    
    int singleNonDuplicateAux(vector<int>& nums, int lo, int hi){
        
        int mid = lo + (hi-lo)/2;
        int prev = mid-1;
        int next = mid+1;
        if((prev==-1 || nums[prev]!=nums[mid]) && (next==nums.size() || nums[next]!=nums[mid])) return nums[mid];
           
         bool isOdd = mid%2;
         if(isOdd){
            if(prev==-1 || nums[prev] == nums[mid]){
                return singleNonDuplicateAux(nums, mid+1, hi);
            }else{
                return singleNonDuplicateAux(nums, lo, mid-1);
            }
         }else{
             if(next==nums.size() || nums[mid]==nums[next]){
                return singleNonDuplicateAux(nums, mid+1, hi);
            }else{
                return singleNonDuplicateAux(nums, lo, mid-1);
            }
         }
        return 0;
    }
    
    //pre: such a single non duplicate exists
    int singleNonDuplicate(vector<int>& nums) {
        return singleNonDuplicateAux(nums, 0, nums.size()-1);
    }
}; 