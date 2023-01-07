fun maxIceCream(costs: IntArray, coins: Int): Int {
    costs.sort()
    var money = coins
    var icecreams = 0
    for (cost in costs) {
        if (cost <= money) {
            icecreams++
            money-= cost
        } else {
            break
        }
    }
    return icecreams
}