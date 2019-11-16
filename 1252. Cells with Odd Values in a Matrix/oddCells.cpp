/*
Runtime: 4 ms, faster than 83.08% of C++ online submissions for Cells with Odd Values in a Matrix.
Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Cells with Odd Values in a Matrix.
*/
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int> > matrix(n, vector<int>(m, 0));
        for(vector<int> rc : indices){
            int row = rc[0];
            int col = rc[1];
            for(int j = 0; j < m; ++j) matrix[row][j]++;
            for(int i = 0; i < n; ++i) matrix[i][col]++;
        }
        int result = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(matrix[i][j] % 2) result++;
        return result;
    }
}; 
