fun wiggleMaxLength(nums: IntArray): Int {
    val size = nums.size
    if (size == 1) return 1
    var result = 1
    var isPositive: Boolean? = null
    for (i in 1..size-1) {
        if (nums[i] == nums[i-1]) continue
        var currentIsPositive = (nums[i] - nums[i-1]) > 0
        if (isPositive == null || isPositive == !currentIsPositive) {
            result++
            isPositive = currentIsPositive
        }
    }
    return result
}

fun main() {
    repeat(readInt()) {
        val nums = readInts()
        println(wiggleMaxLength(nums))
    }
}

private fun readInt() = readLine()!!.toInt()

private fun readInts(): IntArray = readLine()!!.split(" ").map {it.toInt()}.toIntArray()