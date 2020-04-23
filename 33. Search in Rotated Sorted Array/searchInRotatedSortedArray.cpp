/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Search in Rotated Sorted Array.
*/
class Solution {
public:
        int searchAux(vector<int>& arr, int lo, int hi, int target){
            if(lo > hi){
                return -1;
            } 
            
            int mid = (lo + hi) / 2;
            if(arr[mid] == target) return mid;

            if(mid+1 <= hi && arr[mid] > arr[mid+1]){
                if(target < arr[lo]){
                    return searchAux(arr, mid+1, hi, target);
                }else{
                    return searchAux(arr, lo, mid-1, target);
                }
            }
            
            if(mid-1 >= lo && arr[mid] < arr[mid-1]){
                if(arr[hi] < target){
                    return searchAux(arr, lo, mid-1, target);
                }else{
                    return searchAux(arr, mid+1, hi, target);
                }
            }
            
            int res = searchAux(arr, lo, mid-1, target);
            if(res == -1) res = searchAux(arr, mid+1, hi, target);
            return res;
        }
    
    int search(vector<int>& nums, int target) {
        return searchAux(nums, 0, nums.size()-1, target);
    }
};