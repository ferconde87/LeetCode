/*
Runtime: 72 ms, faster than 15.78% of C++ online submissions for Unique Paths III.
Memory Usage: 35.1 MB, less than 100.00% of C++ online submissions for Unique Paths III.
*/
class Solution {
public:
    //find start point
    
    //count numbers of 0 cells, cuz we need to go through all of them
    
    //recursive explore marking as visited and counting the cells you go through
    
    //when you find the end position (grid[i][j]==2) and if you walk through all the cells
        //result++    

    
    int result = 0;
    
    
    pair<int, int> getStartPosition(vector<vector<int>> & grid){
        int n = grid.size(), m = n ? grid[0].size() : 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1) return {i,j};
            }
        }
        return {-1,-1};
    }
    
    int countEmptySquares(vector<vector<int>> & grid){
        int n = grid.size(), m = n ? grid[0].size() : 0;
        int count = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 0) count++;
            }
        }
        return count;
    }
    
    void uniquePathsIIIRec(vector<vector<int>> & grid, int r, int c, vector<vector<bool>> visited, int squares, int totalSquares, int n, int m){
        if(grid[r][c] == 2){
            squares--;//-1 cuz we add an extra +1 when grid[r][c]==2 right here ;)
            if((squares) == totalSquares) result++;
            return;
        }
        visited[r][c] = true;
        if(0 <= r-1 && !visited[r-1][c] && grid[r-1][c] != -1) uniquePathsIIIRec(grid, r-1, c, visited, squares+1, totalSquares, n, m);
        if(r+1 < n && !visited[r+1][c] && grid[r+1][c] != -1) uniquePathsIIIRec(grid, r+1, c, visited, squares+1, totalSquares, n, m);
        if(0 <= c-1 && !visited[r][c-1] && grid[r][c-1] != -1) uniquePathsIIIRec(grid, r, c-1, visited, squares+1, totalSquares, n, m);
        if(c+1 < m && !visited[r][c+1] && grid[r][c+1] != -1) uniquePathsIIIRec(grid, r, c+1, visited, squares+1, totalSquares, n, m);
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = n ? grid[0].size() : 0;
        pair<int, int> start = getStartPosition(grid);
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        visited[start.first][start.second] = true;
        int emptySquares = countEmptySquares(grid);
        uniquePathsIIIRec(grid, start.first, start.second, visited, 0, emptySquares, n, m);
        return result;
    }
};