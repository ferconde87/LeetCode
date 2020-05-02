/*
Runtime: 12 ms, faster than 26.82% of C++ online submissions for Rotting Oranges.
Memory Usage: 13.4 MB, less than 6.25% of C++ online submissions for Rotting Oranges.
*/

class Solution {
public:
    
    queue<pair<int, int>> initializeWithRottenOranges(vector<vector<int>>& grid, vector<vector<int>> & minutes, int n, int m){
        queue<pair<int, int> > q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    minutes[i][j] = 0;
                }
            }
        }
	    return q;
    }
    
    //return max minute in the minutes matrix or -1 if we found one orange without be turned into rotten
    int getResult(vector<vector<int>> & grid, vector<vector<int>> & minutes, int n, int m){
        int max_value = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    int cur = minutes[i][j];
                    if(cur == -1) return -1;
                    max_value = max(max_value, cur);
                }
            }
        }
        return max_value;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> offset = {0,1,0,-1,0};
        int n = grid.size(), m = n ? grid[0].size() : 0;
        if(m == 0) return -1;

        vector<vector<int>> minutes(n, vector<int>(m, -1));
        queue<pair<int, int> > q = initializeWithRottenOranges(grid, minutes, n, m);

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            for(int k = 0; k < 4; ++k){
                int r = p.first + offset[k], c = p.second + offset[k+1];
		        if(0 <= r && r < n && 0 <= c && c < m && grid[r][c]==1 && minutes[r][c]==-1){
			        minutes[r][c] = minutes[p.first][p.second] + 1;
			        q.push({r,c});
                }
            }
        }
        return getResult(grid, minutes, n, m);
    }
};