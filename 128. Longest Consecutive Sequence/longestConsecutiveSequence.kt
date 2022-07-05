fun longestConsecutive(nums: IntArray): Int {
    if(nums.size <= 1) return nums.size
    nums.sort()
    var ans = 1
    var cur = 1
    for (i in 1 until nums.size) {
        if (nums[i] == nums[i-1]) continue
        if (nums[i] == nums[i-1]+1) {
            cur++
            ans = maxOf(ans, cur)
        } else {
            cur = 1
        }
    }
    return ans
}

fun main() {
    repeat (readInt()) {
        println(longestConsecutive(readInts()))
    }
}

private fun readInt() = readLine()!!.toInt()

private fun readInts(): IntArray = readLine()!!.split(" ").map {it.toInt()}.toIntArray()