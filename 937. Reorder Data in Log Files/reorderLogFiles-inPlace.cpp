/*
Runtime: 16 ms, faster than 64.92% of C++ online submissions for Reorder Data in Log Files.
Memory Usage: 13.6 MB, less than 52.94% of C++ online submissions for Reorder Data in Log Files.

Pasando por referencia en el compare 'f' :)
Runtime: 12 ms, faster than 90.26% of C++ online submissions for Reorder Data in Log Files.
Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Reorder Data in Log Files.

*/

bool f (string & a, string & b) {
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
    
    //count consecutive letter-logs
    int countLetterLog(vector<string> & logs){
        int n  = logs.size();
        int j = 0;
        int result = 0;
        while(j < n){
            int pos = logs[j].find(" ");
            if(!isdigit(logs[j][pos+1])) result++;
            else break;
            j++;
        }
        return result;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        if(n == 0) return logs;
        int j = n -1;
        int i = j - 1;
        int limit = -1;
        bool aSwap = false;
        while(i >= 0 && j >= 0){
            while(j >= 0){
                int pos = logs[j].find(" ");
                if(!isdigit(logs[j][pos+1])) break;
                --j;
            }
            i = j - 1;
            while(i >= 0){
                int pos = logs[i].find(" ");
                if(isdigit(logs[i][pos+1])) break; 
                --i;
            }
            if(i >= 0){
                limit = j;
                swap(logs[i--],logs[j--]);
            }
        }
        
        if (limit != -1){
            sort(logs.begin(), logs.begin()+limit, f);
        }else{
            int k = countLetterLog(logs);
            if(k > 0) sort(logs.begin(), logs.begin()+k, f);
        }
        return logs;
    }
};
