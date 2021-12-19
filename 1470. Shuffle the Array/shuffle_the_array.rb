# @param {Integer[]} nums
# @param {Integer} n
# @return {Integer[]}
def shuffle(nums, n)
  ans = []
  for i in 0..n-1
      ans << nums[i]
      ans << nums[i+n]
  end
  ans
end
