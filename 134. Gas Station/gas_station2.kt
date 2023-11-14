class Solution {
    fun canCompleteCircuit(gas: IntArray, cost: IntArray): Int {
        val n = gas.size
        val diff = IntArray(n)
        var accum = 0
        var minValue = 100000
        var minIndex = -1

        for (i in 0..< n) {
            diff[i] = gas[i] - cost[i]
        }

        for (i in 0..< n) {
            accum += diff[i]
            if (accum <= minValue) {
                minValue = accum
                minIndex = i
            }
        }

        if (accum < 0) return -1

        return (minIndex + 1) % n
    }
}
