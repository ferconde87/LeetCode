#include <bits/stdc++.h>

using namespace std;   

int addDigits(int num) {
    if (num == 0){
        return 0;
    }
    if (num % 9 == 0){
        return 9;
    }
    else {
        return num % 9;
    }
}

int main(){

    cout << addDigits(2345) << endl;

    return 0;
}