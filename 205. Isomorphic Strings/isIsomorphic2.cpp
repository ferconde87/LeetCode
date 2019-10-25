#include <bits/stdc++.h>

using namespace std;    

const int size = 256; //amount of possible different characteres

bool isIsomorphic(string s, string t) {
    
    int position_s[size] = {0};
    int position_t[size] = {0};

    for(int i = 0; i < s.size(); i++){
        if(position_s[s[i]] != position_t[t[i]]) return false;
        position_s[s[i]] = i+1;
        position_t[t[i]] = i+1;
    }

    return true;
}

int main(){

    string s = "egg";
    string t = "add";

    assert (isIsomorphic(s,t) == true);

    s = "abba";
    t = "abab";

    assert (isIsomorphic(s,t) == false);

    return 0;
}