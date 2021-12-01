class Solution {
    fun rob(nums: IntArray): Int {
        val n = nums.size
        if(n <= 2) return maxOf(nums[0], nums[n-1])
        var last_3 = nums[0]
        var last_2 = nums[1]
        var last = nums[0] + nums[2]
        for(i in 3..n-1){
            var temp = maxOf(last_2, last_3) + nums[i]
            last_3 = last_2
            last_2 = last
            last = temp
        }
        return maxOf(last, last_2)
    }
}
