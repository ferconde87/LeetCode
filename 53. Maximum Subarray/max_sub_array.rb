# Runtime: 108 ms, faster than 96.03% of Ruby online submissions for Maximum Subarray.
# Memory Usage: 218 MB, less than 37.11% of Ruby online submissions for Maximum Subarray.
# @param {Integer[]} nums
# @return {Integer}
def max_sub_array(nums)
  max = -10000
  cur = 0
  for x in nums
      cur += x
      max = cur if cur > max
      cur = 0 if cur < 0
  end
  max
end
