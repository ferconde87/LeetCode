/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight.
Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Last Stone Weight.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        while(n > 1){
            int bigger = stones[n-1];
            int bigger2 = stones[n-2];
            int rem = bigger - bigger2;
            stones.erase(stones.end()-2, stones.end());
            if (rem != 0){
                auto it = upper_bound(stones.begin(), stones.end(), rem);
                stones.insert(it, rem);
            }
            n = stones.size();
        }
        if (stones.size() == 0) {
            return 0;
        }
        return stones[0];    
    }
};

	