fun main() {
    fun shuffle(nums: IntArray, n: Int): IntArray {
        val result = IntArray(n)
        val j = n
        for (i in 0 until n) {
            result[2*i] = nums[i]
            result[2*i+1] = nums[j]
            j++
        }
        return result
    }



}

