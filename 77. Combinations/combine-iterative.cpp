/*
Runtime: 68 ms, faster than 84.68% of C++ online submissions for Combinations.
Memory Usage: 11.7 MB, less than 95.00% of C++ online submissions for Combinations.
*/
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> c(k, 0);
		while (i >= 0) {
			c[i]++;
			if (c[i] > n) --i;
			else if (i == k - 1) result.push_back(c);
			else {
			    ++i;
			    c[i] = c[i - 1];
			}
		}
		return result;
	}
};
