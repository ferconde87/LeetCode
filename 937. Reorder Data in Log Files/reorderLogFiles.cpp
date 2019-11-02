/*
Runtime: 8 ms, faster than 98.45% of C++ online submissions for Reorder Data in Log Files.
Memory Usage: 14.6 MB, less than 47.06% of C++ online submissions for Reorder Data in Log Files.

Pasando por referencia en el compare 'f' :) (no sé por qué corrió más lento, probablemente la medición del Runtime no es muy confiable :P)
Runtime: 12 ms, faster than 90.26% of C++ online submissions for Reorder Data in Log Files.
Memory Usage: 12.2 MB, less than 88.24% of C++ online submissions for Reorder Data in Log Files.

*/

bool f (string a, string b) {
    int index_a = a.find(" ") + 1;
    int index_b = b.find(" ") + 1;
    bool a_less_b = lexicographical_compare(a.begin()+index_a,a.end(),b.begin()+index_b,b.end());
    if(a_less_b) return true;
    bool b_less_a = lexicographical_compare(b.begin()+index_b,b.end(),a.begin()+index_a,a.end()); 
    if(b_less_a) return false; 
    return (lexicographical_compare(a.begin(), a.begin()+index_a, b.begin(), b.begin()+index_b));
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        if(n == 0) return logs;
        //separate between digit-logs & letter-logs
        vector<string> letter_logs;
        vector<string> digit_logs;
        for(string s : logs){
            int pos = s.find(" ");
            char c = s[pos+1];
            if(isdigit(c)) digit_logs.push_back(s);
            else letter_logs.push_back(s);
        }
        sort(letter_logs.begin(), letter_logs.end(), f);
        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
};
