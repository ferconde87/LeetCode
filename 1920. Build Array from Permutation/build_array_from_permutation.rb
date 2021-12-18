# Runtime: 130 ms, faster than 13.25% of Ruby online submissions for Build Array from Permutation.
# Memory Usage: 210.8 MB, less than 75.90% of Ruby online submissions for Build Array from Permutation.

# @param {Integer[]} nums
# @return {Integer[]}
def build_array(nums)
  ans = []
  nums.each_with_index { |val, index| 
      ans[index] = nums[val]
  }
  ans
end


# Runtime: 68 ms, faster than 96.39% of Ruby online submissions for Build Array from Permutation.
# Memory Usage: 210.8 MB, less than 46.99% of Ruby online submissions for Build Array from Permutation.

# @param {Integer[]} nums
# @return {Integer[]}
def build_array2(nums)
  nums.map {|x| nums[x]}
end
