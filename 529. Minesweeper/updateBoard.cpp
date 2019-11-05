/*
Runtime: 40 ms, faster than 91.72% of C++ online submissions.
Memory Usage: 14.9 MB, less than 100.00% of C++ online submissions.
*/

int const WIDTH = 51;
int const HEIGHT = 51;

void mine(int adjacentMines[][WIDTH], int rows, int cols, int i, int j){
    if(i > 0 && j > 0) adjacentMines[i-1][j-1]++;
    if(i > 0) adjacentMines[i-1][j]++;
    if(i > 0 && j < cols-1) adjacentMines[i-1][j+1]++;

    if(j > 0) adjacentMines[i][j-1]++;
    if(j < cols-1) adjacentMines[i][j+1]++;

    if(i < rows-1 && j > 0) adjacentMines[i+1][j-1]++;
    if(i < rows-1) adjacentMines[i+1][j]++;
    if(i < rows-1 && j < cols-1) adjacentMines[i+1][j+1]++;
}

void addNeighbors(vector<vector<char> > & board, bool seen[][WIDTH], int rows, int cols, int i, int j, queue<pair<int, int> > & q){
    if(i > 0 && j > 0 && !seen[i-1][j-1]) {q.push(make_pair(i-1,j-1)); seen[i-1][j-1] = true;}
    if(i > 0 && !seen[i-1][j]) {q.push(make_pair(i-1,j)); seen[i-1][j] = true;}
    if(i > 0 && j < cols-1 && !seen[i-1][j+1]) {q.push(make_pair(i-1,j+1)); seen[i-1][j+1] = true;}

    if(j > 0 && !seen[i][j-1]) {q.push(make_pair(i,j-1)); seen[i][j-1] = true;}
    if(j < cols-1 && !seen[i][j+1]) {q.push(make_pair(i,j+1)); seen[i][j+1] = true;}

    if(i < rows-1 && j > 0 && !seen[i+1][j-1]) {q.push(make_pair(i+1,j-1));  seen[i+1][j-1] = true;}
    if(i < rows-1 && !seen[i+1][j]) {q.push(make_pair(i+1,j));  seen[i+1][j] = true;}
    if(i < rows-1 && j < cols-1 && !seen[i+1][j+1]) {q.push(make_pair(i+1,j+1));  seen[i+1][j+1] = true;}
}

class Solution {
public:

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        if(rows == 0) return board;
        
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        int cols = board[0].size();
        int adjacentMines[rows][WIDTH] = {0};
        bool seen[HEIGHT][WIDTH] = {false};
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == 'M'){
                    mine(adjacentMines, rows, cols, i, j);
                }
            }
        }
             
        if(adjacentMines[x][y] > 0){
            board[x][y] = '0' + adjacentMines[x][y];
            return board;
        }
        
        queue< pair<int, int> > q;
        q.push(make_pair(x,y));
        while(!q.empty()){
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            seen[x][y] = true;
            if(adjacentMines[x][y] > 0){
                board[x][y] = '0' + adjacentMines[x][y];
                continue;
            }
            board[p.first][p.second] = 'B';
            
            addNeighbors(board, seen, rows, cols, x, y, q);
        }
        
        return board;
    }
};
