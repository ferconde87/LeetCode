#include <bits/stdc++.h>

using namespace std;

int baseCase(const vector<int> & A, int B, int l, int r, int offset_l, int offset_r){
    if(l == r){
        if(l < A.size() && A[l] == B) return l;
        else return -1;
    }else if(offset_r == 1){
        if(l < A.size() && A[l] == B) return l;
        else if(r >= 0 && A[r] == B) return r;
        else return -1;
    }else{
        if(r >= 0 && A[r] == B) return r;
        else if(l < A.size() && A[l] == B) return l;
        else return -1;
    }
}

int searchRangeRec(const vector<int> &A, int B, int l, int r, int offset_l, int offset_r){
    if(abs(r-l) <= 1){
            return baseCase(A, B, l, r, offset_l, offset_r);
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

int main(){


    return 0;
}