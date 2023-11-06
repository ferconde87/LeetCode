class Solution {
    fun jump(nums: IntArray): Int {
        if (nums.size == 1) return 0
        var ans = 0
        var maxJump = 0
        val dp = IntArray(nums.size)
        dp[0] = 0
        for ((index, value) in nums.withIndex()) {
            val curJump = index + value
            if (maxJump < curJump) {
                if (curJump >= nums.size - 1) return dp[index] + 1
                for (i in (maxJump+1)..curJump) {
                    dp[i] = dp[index] + 1
                }
                maxJump = curJump
            }
        }
        return dp[nums.size - 1]
    }
}
