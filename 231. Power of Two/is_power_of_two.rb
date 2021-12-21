# Runtime: 60 ms, faster than 59.46% of Ruby online submissions for Power of Two.
# Memory Usage: 209.8 MB, less than 62.16% of Ruby online submissions for Power of Two.

# @param {Integer} n
# @return {Boolean}
def is_power_of_two(n)
  return false if n == 0
  (n & (n-1)) == 0
end
