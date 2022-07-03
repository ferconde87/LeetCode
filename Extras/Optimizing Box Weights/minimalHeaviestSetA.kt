fun minimalHeaviestSetA(array: IntArray): List<Int> {
    array.sortDescending()
    val sum = array.sum()
    val half = sum / 2
    var result = mutableListOf<Int>()
    var weight = 0
    var i = 0
    while (weight < half) {
        result.add(array[i])
        weight += array[i]
        ++i
    }
    return result.reversed()
}

fun main() {
    repeat (readInt()) {
        val array = readInts()
        val result: List<Int> = minimalHeaviestSetA(array)
        result.map {print("$it ")}
        println()
    }
}

private fun readInt() = readLine()!!.toInt()

private fun readInts(): IntArray = readLine()!!.split(" ").map {it.toInt()}.toIntArray()