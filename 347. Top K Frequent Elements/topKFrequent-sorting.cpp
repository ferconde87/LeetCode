unordered_map<int, int> make_map(vector<int> & nums){
    unordered_map<int, int> map;
    for(int x : nums){
        map[x]++;
    }
    return map;
}

vector<pair<int, int> > make_vector_of_pairs(unordered_map<int, int> & map){
    vector<pair<int, int> > v;
    for(auto it = map.begin(); it != map.end(); ++it){
        v.push_back(make_pair(it->first, it->second));
    }
    return v;
}

bool f(pair<int, int> & p, pair<int, int> & q){
    if(p.second == q.second) return p.first < q.first;
    return p.second > q.second;
}


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map = make_map(nums);
        vector<pair<int, int> > v = make_vector_of_pairs(map);
        sort(v.begin(), v.end(), f);
        vector<int> result;
        for(int i = 0; i < k; ++i){
            result.push_back(v[i].first);
        }
        return result;
    }
};