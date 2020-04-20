/*
Runtime: 4 ms, faster than 99.30% of C++ online submissions for Minimum Path Sum.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Minimum Path Sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = n ? grid[0].size() : 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == 0 && j == 0) continue;
                if(i == 0) grid[i][j] += grid[i][j-1];
                else if(j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};