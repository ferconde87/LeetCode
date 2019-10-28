class Solution {
public:
    string toLowerCase(string str) {
        int n = str.size();
        for(int i = 0; i < n; ++i)
            if(isupper(str[i]))
                str[i] = tolower(str[i]);
        return str;
    }
};
