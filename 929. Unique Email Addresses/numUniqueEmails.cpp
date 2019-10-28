/*
Runtime: 20 ms, faster than 98.61% of C++ online submissions for Unique Email Addresses.
Memory Usage: 13 MB, less than 66.67% of C++ online submissions for Unique Email Addresses.*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> names;
        for(string e : emails){
            string cur = "";
            for(char c : e){
                if(c == '+' || c == '@') break;
                if(c == '.') continue;
                cur.push_back(c);                
            }
            auto it = e.find('@');
            cur.insert(cur.end(), e.begin()+it, e.end());
            names.insert(cur);
        }
        return names.size();
    }
};
