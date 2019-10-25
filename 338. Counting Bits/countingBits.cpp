class Solution {
public:
    
    int findPowerOfTwoLower(int x, vector<int> & pows){
        int i = 0;
        int n = pows.size();
        for(; i < n; ++i){
            if(pows[i] > x) return pows[i-1];
        }
        return pows[i-1];
    }
    
    vector<int> countBits(int num) {
        vector<int> pows;
        for(int i = 1; i <= num; i*=2) pows.push_back(i);
        
        vector<int> dp(num+1,0);
        for(int x : pows){
            dp[x] = 1;
        }
        for(int i = 3; i <= num; i++){
            int powLower = findPowerOfTwoLower(i, pows);
            dp[i] = 1 + dp[i-powLower];
        }
        return dp;
    }
};
