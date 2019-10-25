#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
    if(x == 0) return 0;
    while(x % 10 == 0) x /= 10;
    long long ans = 0;
    while(x != 0){
        ans = 10*ans + (x % 10);
        x /= 10;
    }
    if(ans > INT_MAX || ans < INT_MIN) return 0;
    return (int)ans;
}

int main(){

    

    return 0;
}