#include <bits/stdc++.h>

using namespace std;

int baseCaseL(const vector<int> & A, int B, int l, int r){
    if(l == r)
        if(l < A.size() && A[l] == B) return l;
        else return -1;
    else if(l < A.size() && A[l] == B) return l;
    else if(r >= 0 && A[r] == B) return r;
    else return -1;
}
int baseCaseR(const vector<int> & A, int B, int l, int r){
    if(l == r)
        if(l < A.size() && A[l] == B) return l;
        else return -1;
    else if(r >= 0 && A[r] == B) return r;
    else if(l < A.size() && A[l] == B) return l;
    else return -1;
}

int searchLeftSide(const vector<int> &A, int B, int l, int r){
    if(abs(r-l) <= 1){
            return baseCaseL(A, B, l, r);
    }   
    int mid = (r + l) / 2;
    int midElement = A[mid];
    if(B <= midElement){
        return searchLeftSide(A, B, l, mid);
    }else{
        return searchLeftSide(A, B, mid+1, r);
    }
}

int searchRightSide(const vector<int> &A, int B, int l, int r){
    if(abs(r-l) <= 1){
        return baseCaseR(A, B, l, r);
    }   
    int mid = (r + l) / 2;
    int midElement = A[mid];
    if(B < midElement){
        return searchRightSide(A, B, l, mid-1);
    }else{
        return searchRightSide(A, B, mid, r);
    }
}
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size() == 0) return {-1, -1};
    int left = searchLeftSide(nums, target, 0, nums.size()-1);
    int right = searchRightSide(nums, target, 0, nums.size()-1);
    return {left, right};
}

int main(){


    return 0;
}