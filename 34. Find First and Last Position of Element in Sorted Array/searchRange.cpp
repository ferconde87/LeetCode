#include <bits/stdc++.h>

using namespace std;

int searchLeftSide(const vector<int> &A, int B, int l, int r){
        if(l >= r){
            if(l < A.size()){
                if(A[l] == B) return l;
            }else if(r >= 0){
                if(A[r] == B) return r;
            }
            return -1;
        }   
        int mid = (r + l) / 2;
        int midElement = A[mid];
        if(B < midElement){
            return searchLeftSide(A, B, l, mid-1);
        }else if(B > midElement){
            return searchLeftSide(A, B, mid+1, r);
        }else{
            if((mid > 0 && B != A[mid-1]) || mid == 0)
                return mid;
            else
                return searchLeftSide(A, B, l, mid-1);
        }
    }

    int searchRightSide(const vector<int> &A, int B, int l, int r){
        if(l >= r){
            if(l < A.size()){
                if(A[l] == B) return l;
            }else if(r >= 0){
                if(A[r] == B) return r;
            }
            return -1;
            
        }   
        int mid = (r + l) / 2;
        int midElement = A[mid];
        if(B < midElement){
            return searchRightSide(A, B, l, mid-1);
        }else if(B > midElement){
            return searchRightSide(A, B, mid+1, r);
        }else{
            if((mid < A.size()-1 && B != A[mid+1]) || mid == A.size()-1)
                return mid;
            else
                return searchRightSide(A, B, mid+1, r);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int left = searchLeftSide(nums, target, 0, nums.size()-1);
        if(left==-1) return {-1,-1};
        int right = searchRightSide(nums, target, 0, nums.size()-1);
        return {left, right};
    }

int main(){


    return 0;
}