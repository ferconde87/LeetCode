/*
Runtime: 84 ms, faster than 58.59% of C++ online submissions for Queue Reconstruction by Height.
Memory Usage: 12.9 MB, less than 28.57% of C++ online submissions for Queue Reconstruction by Height.
*/
bool f(vector<int> & a, vector<int> & b){
    if(-a[0] < -b[0]) return true;
    if(-a[0] > -b[0]) return false;
    return a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), f);
        vector<vector<int>> q;
        for(auto p : people){
            q.insert(q.begin()+p[1], p);
        }
        return q;
    }
};
