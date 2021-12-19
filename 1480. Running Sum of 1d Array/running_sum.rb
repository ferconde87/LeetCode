# @param {Integer[]} nums
# @return {Integer[]}
def running_sum(nums)
  ans = [nums[0]]
  for i in 1..nums.length-1
      ans[i] = ans[i-1] + nums[i]
  end
  ans
end

# Runtime: 44 ms, faster than 98.11% of Ruby online submissions for Running Sum of 1d Array.
# Memory Usage: 210.1 MB, less than 77.36% of Ruby online submissions for Running Sum of 1d Array.
def running_sum(nums)
  ans = []
  temp = 0
  for x in nums
      temp += x
      ans << temp
  end
  ans
end
