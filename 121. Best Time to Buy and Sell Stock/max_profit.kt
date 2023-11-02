class Solution {
    fun maxProfit(prices: IntArray): Int {
        var buyDay = 0
        val lastDay = prices.size - 1
        var ans = 0
        var sellDay = 1
        while (buyDay < lastDay && sellDay < prices.size) {
            val current = prices[sellDay] - prices[buyDay]
            if (current > ans) {
                ans = current
            }
            if (prices[sellDay] < prices[buyDay]) {
                buyDay = sellDay
            }
            sellDay++
        }
        return ans
    }
}
