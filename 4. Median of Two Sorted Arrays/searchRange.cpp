#include <bits/stdc++.h>

using namespace std;

//if the element is not in the array, return the position at the element would be

int baseCase(const vector<int> & A, int B, int l, int r, int offset_l, int offset_r){
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

    vector<int> nums = {1,2,3,4,5};
    nums = {6,7,8,9,10};

    nums = {2,2,3,4,5,10};
    vector<int> ans = searchRange(nums, 4);//[3,3];
    cout << ans[0] << " " << ans[1] << endl;
    
    nums = {1,2,4,6,7,9};
    ans = searchRange(nums, 3);//[2,2];
    cout << ans[0] << " " << ans[1] << endl;

    nums = {1,2,2,2,7,9};
    ans = searchRange(nums, 2);//[1,3];
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}