/*
Runtime: 20 ms, faster than 60.66% of C++ online submissions for Top K Frequent Words.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Top K Frequent Words.
*/

bool compare(pair<string, int> & p, pair<string, int> & q){
    if(p.second < q.second) return true;
    if(q.second < p.second) return false;
    return !lexicographical_compare(p.first.begin(), p.first.end(), q.first.begin(), q.first.end());
}

class Solution {
public:    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for(string s : words){
            auto it = map.find(s);
            if(it != map.end()){
                it->second++;
            }else{
                map[s] = 1;
            }
        }
        
        int n = map.size();
        int i = 0;
        vector<pair<string,int> > v(map.size());//amount-string;
        for(auto it = map.begin(); it != map.end(); ++it){
            v[i++] = {it->first, it->second};
        }
        
        make_heap(v.begin(), v.end(), compare);
        vector<string> result(k);
        for(int i = 0; i < k; ++i){
            result[i] = v.front().first;
            pop_heap(v.begin(), v.end()-i, compare);
        }
        
        return result;
    }
};