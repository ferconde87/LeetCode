#include <bits/stdc++.h>

using namespace std;   
    
int addDigits(int num) {
    return num - 9*(floor((num-1)/9)); 
}

int main(){

    cout << addDigits(2345) << endl;

    return 0;
}