class Solution {
    fun occurrencies(nums: IntArray, elem: Int, startIndex: Int, n: Int): Int {
        var ans = 0
        for(i in startIndex..<n)
            if (nums[i] == elem)
                ans++
        return ans
    }

    fun shiftToLeft(nums: IntArray, offset: Int, startIndex: Int, n: Int): Unit {
        for (i in startIndex..<n-offset)
            nums[i] = nums[i+offset]
    }

    fun removeDuplicates(nums: IntArray): Int {
        var shift = 0
        for (i in 0..< nums.size-shift) {
            val times = occurrencies(nums, nums[i], i, nums.size-shift)
            if (times > 2) {
                shiftToLeft(nums, times-2, i, nums.size-shift)
                shift += times-2
            }
        }
        return nums.size - shift
    }
}
