class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        int result = 0;
        int bestBuy  = prices[0];
        int bestSell = prices[1];
        for(int i = 0; i < n; ++i){
            if(prices[i] < bestBuy){
                result = max(result, bestSell - bestBuy);
                bestBuy = prices[i];
                bestSell = prices[i];    
            }else if(prices[i] > bestSell){
                bestSell = prices[i];
            }
        }
        return result = max(result, bestSell - bestBuy);        
    }
};
