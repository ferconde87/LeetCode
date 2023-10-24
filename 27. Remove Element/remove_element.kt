class Solution {
    fun removeElement(nums: IntArray, `val`: Int): Int {
        var i = 0
        var j = nums.size - 1
        var ans = 0
        while (i < j) {
            while (i < j && nums[i] != `val`)
                i++
            while (i < j && nums[j] == `val`)
                j--
            nums[i] = nums[j].also { nums[j] = nums[i] }
        }
        for (i in 0..nums.size - 1)
            if (nums[i] != `val`)
                ans++
        return ans
    }
}
