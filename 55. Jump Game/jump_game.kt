class Solution {
    fun canJump(nums: IntArray): Boolean {
        var ans = 0
        for ((index, value) in nums.withIndex()) {
            if (ans < index) return false
            ans = maxOf(ans, index + value)
        }
        return (ans >= nums.size - 1)
    }
}
