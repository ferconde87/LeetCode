fun printA(array: IntArray) {
    for(x in array) {
        print(x)
        print(" ")
    }
    println()
}

fun canCompleteCircuit(gas: IntArray, cost: IntArray): Int {
    val n = gas.size
    if (n == 1) {
        return if (cost[0] > gas[0]) -1 else 0
    }
    val sumDiff = IntArray(n) { 0 }
    sumDiff[0] = gas[0] - cost[0]
    for (i in 1 until n) {
        sumDiff[i] =+ sumDiff[i-1] + gas[i] - cost[i]
    }
    if (sumDiff[n-1] < 0) return -1
    var min = sumDiff[0]
    var minIndex = 0
    for (i in 1 until n) {
        if (sumDiff[i] < min) {
            min = sumDiff[i]
            minIndex = i
        }
    }
    if (minIndex == n-1) return 0
    return minIndex + 1
}