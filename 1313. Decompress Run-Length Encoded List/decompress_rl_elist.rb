# Runtime: 84 ms, faster than 36.36% of Ruby online submissions for Decompress Run-Length Encoded List.
# Memory Usage: 210.7 MB, less than 50.00% of Ruby online submissions for Decompress Run-Length Encoded List.
# @param {Integer[]} nums
# @return {Integer[]}
def decompress_rl_elist(nums)
  ans = []
  (0..nums.length-1).step(2) do |i|
      ans << Array.new(nums[i], nums[i+1])
  end
  ans.flatten
end

# Runtime: 76 ms, faster than 86.36% of Ruby online submissions for Decompress Run-Length Encoded List.
# Memory Usage: 210.6 MB, less than 50.00% of Ruby online submissions for Decompress Run-Length Encoded List.
# @param {Integer[]} nums
# @return {Integer[]}
def decompress_rl_elist(nums)
  n = nums.length
  ans = []
  i = 0
  while i < n do
      1.upto(nums[i]) do
          ans.append(nums[i+1])
      end
      i += 2
  end
  ans
end
