class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int m[n][n];
        if(n == 0) return vector<int>();
        int minDistance = INT_MAX;
        for(int node_i = 0; node_i < n; node_i++){
            int edgesSize = edges.size();
            int distance = -1;
            queue<int> q;
            q.push(node_i);
            while(!q.empty()){
                distance++;
                int levelSize = q.size();
                for(int k = 0; k < levelSize; k++){
                    int node_j = q.front();
                    q.pop();
                    m[node_i][node_j] = distance;
                    m[node_j][node_i] = distance;
                    int e = 0;
                    while(e < edgesSize){
                        if(node_j==edges[e][0]){
                            q.push(edges[e][1]);
                            swap(edges[e], edges[edgesSize-1]);
                            edgesSize--;
                        }else if(node_j==edges[e][1]){
                            q.push(edges[e][0]);
                            swap(edges[e], edges[edgesSize-1]);
                            edgesSize--;
                        }else{
                            e++;
                        }
                    }
                }
            }
            if(distance < minDistance)
                minDistance = distance;            
        }
        vector<int> result;
        for(int i = 0; i < n; i++){
            int maxDistance = *max_element(m[i], m[i]+n);
            if(maxDistance == minDistance) result.push_back(i);
        }
        return result;
    }
};
