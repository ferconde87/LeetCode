#include <bits/stdc++.h>

using namespace std;


//if the element is not in the array, return the position at the element would be
int searchRangeBaseCase(const vector<int> & A, int B, int l, int r, int offset_l, int offset_r){
    if(l == r){
        if(l == A.size()) return l;
        if(A[l] < B) return l+1;
        return l;
    }else if(offset_r == 1){
            if(A[l] < B) return l+1;
            return l;
    }else{
        assert(r >= 0);
        if(A[r] < B) return r+1;
        return r;
    }
}

int searchRangeRec(const vector<int> &A, int B, int l, int r, int offset_l, int offset_r){
    if(abs(r-l) <= 1){
            return searchRangeBaseCase(A, B, l, r, offset_l, offset_r);
    }   
    int mid = (r + l) / 2;
    cout << "mid = " << mid << endl;
    int midElement = A[mid];
    if(B < midElement){
        return searchRangeRec(A, B, l, mid+offset_l, offset_l, offset_r);
    }else if (B > midElement){
        return searchRangeRec(A, B, mid+offset_r, r, offset_l, offset_r);
    }else{
        if(offset_r == 1)
            return searchRangeRec(A, B, l, mid, offset_l, offset_r);
        else
            return searchRangeRec(A, B, mid, r, offset_l, offset_r);
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0) return {-1, -1};
    int left = searchRangeRec(nums, target, 0, nums.size()-1, 0, 1);
    int right = searchRangeRec(nums, target, 0, nums.size()-1, -1, 0);
    return {left, right};
}

///////////////////////
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return 0.0;
}

int main(){


    return 0;
}