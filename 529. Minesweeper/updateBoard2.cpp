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

void addNeighbors(vector<vector<char> > & board, int rows, int cols, int i, int j, queue<pair<int, int> > & q){
    if(i > 0 && j > 0 && board[i-1][j-1] == 'E') {q.push(make_pair(i-1,j-1)); board[i-1][j-1] = 'B';}
    if(i > 0 && board[i-1][j] == 'E') {q.push(make_pair(i-1,j)); board[i-1][j] = 'B';}
    if(i > 0 && j < cols-1 && board[i-1][j+1] == 'E') {q.push(make_pair(i-1,j+1)); board[i-1][j+1] = 'B';}

    if(j > 0 && board[i][j-1] == 'E') {q.push(make_pair(i,j-1)); board[i][j-1] = 'B';}
    if(j < cols-1 && board[i][j+1] == 'E') {q.push(make_pair(i,j+1)); board[i][j+1] = 'B';}

    if(i < rows-1 && j > 0 && board[i+1][j-1] == 'E') {q.push(make_pair(i+1,j-1));  board[i+1][j-1] = 'B';}
    if(i < rows-1 && board[i+1][j] == 'E') {q.push(make_pair(i+1,j));  board[i+1][j] = 'B';}
    if(i < rows-1 && j < cols-1 && board[i+1][j+1] == 'E') {q.push(make_pair(i+1,j+1));  board[i+1][j+1] = 'B';}
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
        board[x][y] = 'B';
        while(!q.empty()){
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            if(adjacentMines[x][y] > 0){
                board[x][y] = '0' + adjacentMines[x][y];
                continue;
            }
            
            addNeighbors(board, rows, cols, x, y, q);
        }
        
        return board;
    }
};
