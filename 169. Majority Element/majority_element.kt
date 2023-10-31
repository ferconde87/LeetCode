class Solution {
    fun majorityElement(nums: IntArray): Int {
        val map = mutableMapOf<Int, Int>()
        var count = 0
        var ans = 0
        for (num in nums) {
            var amount = map.getOrElse(num, {0})
            map.put(num, amount + 1)
        }
        for ((num, amount) in map) {
            if (amount > count) {
                count = amount
                ans = num
            }
        }
        return ans
    }
}
