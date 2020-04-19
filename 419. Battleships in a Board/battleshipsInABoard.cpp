/*
Runtime: 4 ms, faster than 96.83% of C++ online submissions for Battleships in a Board.
Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Battleships in a Board.
*/

class Solution {
public:
    
    void markV(vector<vector<char>>& board, vector<vector<bool> > & visited, int n, int m, int row, int col){
        for(int i = row; i < n; ++i){
            if(board[i][col]=='X') visited[i][col] = true;
            else break;
        }
    }
    
    int markHAndNextIndex(vector<vector<char>>& board, vector<vector<bool> > & visited, int n, int m, int row, int col){
        int j = col;
        for(; j < m; ++j){
            if(board[row][j]=='X') visited[row][j] = true;
            else break;
        }
        return j;
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return 0;
        int m = board[0].size();
        vector<vector<bool> >  visited(n, vector<bool>(m, false));
        int result = 0;
        for(int row = 0; row < n; ++row){
             int col = 0;
            for(; col < m; ++col){
                if(visited[row][col]) continue;
                if(board[row][col] == '.') continue;
                result++;
                markV(board, visited, n, m, row, col);
                col = markHAndNextIndex(board, visited, n, m, row, col);
            }
        }
        return result;
    }
};