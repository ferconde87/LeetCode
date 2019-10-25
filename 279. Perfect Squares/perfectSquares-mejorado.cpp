#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int nsqrt = (int)sqrt(n);
        vector<int> perfectSquares = {0};
        for(int i = 1; i < nsqrt+1; i++){
            perfectSquares.push_back(i*i);
        }
        int nps = perfectSquares.size();
        int m[n+1];
        for(int i = 0; i <= n; i++){
                m[i] = INT_MAX;
        }
        m[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < nps; j++){
                int curPerfectSquare = perfectSquares[j];
                if(curPerfectSquare <= i){
                    m[i] = min(m[i],1+m[i-curPerfectSquare]);
                }
            }
        }
        return m[n];
    }
};

