class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int> > & image, int sr, int sc, int newColor)     {
        int rows = image.size();
        if(rows == 0) return image;
        int cols = image[0].size();
        if(cols == 0) return image;
        vector<vector<bool> > checked(rows, vector<bool>(cols, false));
        queue<pair<int, int> > colors;
        colors.push(make_pair(sr,sc));
        int oldColor = image[sr][sc];
        while(!colors.empty()){
            auto c = colors.front();
            colors.pop();
            int x = c.first;
            int y = c.second;
            if(checked[x][y]) continue;
            checked[x][y] = true;
            image[x][y] = newColor;
            if(x > 0 && !checked[x-1][y] && image[x-1][y] == oldColor)
                colors.push(make_pair(x-1,y));
            
            if(x < rows-1 && !checked[x+1][y] && image[x+1][y] == oldColor)
                colors.push(make_pair(x+1,y));
            
            if(y > 0 && !checked[x][y-1] && image[x][y-1] == oldColor)
                colors.push(make_pair(x,y-1));
            
            if(y < cols-1 && !checked[x][y+1] && image[x][y+1] == oldColor)
                colors.push(make_pair(x,y+1));
        }
        return image;
    }
};
