//1 <= tasks.length <= 10^5
//1 <= tasks[i] <= 10^9

fun calculateRoundsPerLevel(level: Int): Int {
    val rem = level % 3
    if (rem == 2) return 1 + (level - 2) / 3
    if (rem == 1) return 2 + (level - 4) / 3
    return level / 3
}

fun minimumRounds(tasks: IntArray): Int {
    val map = hashMapOf<Int, Int>()
    var result: Int = 0

    for (task in tasks) {
        val times = map.get(task)
        if (times == null) {
            map.put(task, 1)
        } else {
            map.put(task, times + 1)
        }
    }

    val amounts = map.values
    for (amount in amounts) {
        if (amount == 1) return -1
        result += calculateRoundsPerLevel(amount)
    }

    return result
}