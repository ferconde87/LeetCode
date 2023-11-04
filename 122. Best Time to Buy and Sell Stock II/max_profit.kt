class Solution {
    fun maxProfit(prices: IntArray): Int {
        var buyIndex = 0
        var ans = 0
        for (i in 1..< prices.size) {
            if (prices[i] > prices[buyIndex]) {
                ans += (prices[i] - prices[buyIndex])
            }
            buyIndex = i
        }
        return ans
    }
}
