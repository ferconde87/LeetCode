#include <bits/stdc++.h>

using namespace std;    
    
unordered_map<char, int> makeHashMap(string s){
    unordered_map<char, int> hashMapS;
    for(char c : s){
        auto it = hashMapS.find(c);
        if(it != hashMapS.end()){
            it->second++;
        }else{
            hashMapS[c] = 1;
        }
    }
    return hashMapS;
}

bool isIsomorphic(string s, string t) {
    
    int n = s.size();
    if(n != t.size()) return false;
    
    unordered_map<char, char> s_to_t;
    unordered_map<char, char> t_to_s;
    
    for(int i = 0; i < n; i++){
        char a = s[i];
        char b = t[i];
        auto itS = s_to_t.find(a);
        if(itS == s_to_t.end()){
            s_to_t[a] = b;
        }else if(s_to_t[a] != b){
            return false;
        }
        
        auto itT = t_to_s.find(b);
        if(itT == t_to_s.end()){
            t_to_s[b] = a;
        }else if(t_to_s[b] != a){
            return false;
        }
        
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