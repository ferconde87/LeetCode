/*
Runtime: 12 ms, faster than 99.76% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Top K Frequent Elements.

- Even though in the description of the problem is not allow to use sorting... because the algorithm has to be strictly better than 
O(n log n), if we sort, we get better performance than using a heap
*/


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