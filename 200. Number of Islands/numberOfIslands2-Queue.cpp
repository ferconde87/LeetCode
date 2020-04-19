/*
Runtime: 16 ms, faster than 44.40% of C++ online submissions for Number of Islands.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Number of Islands.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        int offset[] = {0, 1, 0, -1, 0};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] =='1'){
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int> > q;
                    q.push({i,j});
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        for(int k = 0; k < 4; ++k){
                            int r = p.first + offset[k], c = p.second + offset[k+1];
                            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1'){
                                grid[r][c] = '0';
                                q.push({r,c});
                            }
                        }
                    }                    
                }
            }
        }
        return islands;
    }
};