fun candy(ratings: IntArray): Int {
    val size = ratings.size
    val counter = IntArray(size) {0}
    counter[0] = 1
    for (i in 1..size-1) {
        if (ratings[i-1] < ratings[i]) {
            counter[i] = counter[i-1] + 1
        } else {
            counter[i] = 1
        }
    }
    for (i in (size-2) downTo 0) {
        if (ratings[i] > ratings[i+1]) {
            counter[i] = maxOf(counter[i], counter[i+1] + 1)
        }
    }
    return counter.sum()
}


fun main() {
    repeat (readInt()) {
        val ratings = readInts()
        println(candy(ratings))
    }
}

private fun readInt() = readLine()!!.toInt()

private fun readInts(): IntArray = readLine()!!.split(" ").map {it.toInt()}.toIntArray()