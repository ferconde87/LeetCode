//Runtime: 777 ms, faster than 40.00% of Kotlin online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
//Memory Usage: 78.2 MB, less than 60.00% of Kotlin online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.

fun getMax(cuts: IntArray, length: Int): Int {
    var maxValue = cuts[0]
    val size = cuts.size
    for (i in 1..size-1) {
        maxValue = maxOf(maxValue, cuts[i]-cuts[i-1])
    }
    return maxOf(maxValue, length-cuts[size-1])
}

fun maxArea(h: Int, w: Int, horizontalCuts: IntArray, verticalCuts: IntArray): Int {
    verticalCuts.sort()
    horizontalCuts.sort()
    val width = getMax(verticalCuts, w).toLong()
    val height = getMax(horizontalCuts, h).toLong()
    return ((width * height) % 1000000007).toInt()
}

fun main() {
    val h = readInt()
    val w = readInt()
    val horizontalCuts: IntArray = readInts()
    val verticalCuts: IntArray = readInts()
    println(maxArea(h,w,horizontalCuts, verticalCuts))
}

private fun readInt() = readLine()!!.toInt()
private fun readInts(): IntArray = readLine()!!.split(" ").map {it.toInt()}.toIntArray()