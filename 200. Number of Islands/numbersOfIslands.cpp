/*
Runtime: 20 ms, faster than 21.07% of C++ online submissions for Number of Islands.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Number of Islands.
*/
class Solution {
public:
    
    void markIsland(vector<vector<char>>& grid, vector<vector<bool> > & visited, int n, int m, int row, int col){
        if(row == -1 || row == n || col == -1 || col == m) return;
        if(visited[row][col]) return;
        visited[row][col] = true;
        if(grid[row][col] == '0') return;
        markIsland(grid, visited, n, m, row+1, col);
        markIsland(grid, visited, n, m, row, col+1);
        markIsland(grid, visited, n, m, row-1, col);
        markIsland(grid, visited, n, m, row, col-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        int result = 0;
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < m; ++col){
                if(visited[row][col]) continue;
                if(grid[row][col] == '0') continue;
                result++;
                markIsland(grid, visited, n, m, row, col);
            }
        }
        return result;
    }
};