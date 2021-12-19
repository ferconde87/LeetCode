# Runtime: 44 ms, faster than 97.44% of Ruby online submissions for Number of Good Pairs.
# Memory Usage: 209.9 MB, less than 20.51% of Ruby online submissions for Number of Good Pairs.
# @param {Integer[]} nums
# @return {Integer}
def num_identical_pairs(nums)
  ans = 0
  for i in 0..nums.length-1
      for j in i+1..nums.length-1
         ans += nums[i] == nums[j] ? 1 : 0
      end
  end
  ans
end

# Runtime: 52 ms, faster than 92.31% of Ruby online submissions for Number of Good Pairs.
# Memory Usage: 209.6 MB, less than 89.74% of Ruby online submissions for Number of Good Pairs.
# @param {Integer[]} nums
# @return {Integer}
def num_identical_pairs(nums)
  dict = {}
  ans = 0
  for x in nums
      dict[x] = (dict.key? x) ? dict[x]+1 : 0
      ans += dict[x]
  end
  ans
end

