fun maxIceCream(costs: IntArray, coins: Int): Int {
    costs.sort()
    var moneySpent = 0
    var icecreams = 0
    for (cost in costs) {
        moneySpent+= cost
        if (moneySpent <= coins) {
            icecreams++
        } else {
            break
        }
    }
    return icecreams
}