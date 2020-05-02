/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for First Bad Version.
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int lo, int hi){
        if(lo > hi) return -1;
        int mid = lo + (hi - lo) / 2;
        if(isBadVersion(mid)){
            if((mid == 0) || (mid > 0 && !isBadVersion(mid-1))){
                return mid;
            }else{
                return binarySearch(lo, mid-1);
            }
        }else{
            return binarySearch(mid+1, hi);
        }
        return mid;
    }
    
    int firstBadVersion(int n) {
        return binarySearch(1, n);
    }
};