# Runtime: 52 ms, faster than 75.61% of Ruby online submissions for Richest Customer Wealth.
# Memory Usage: 210 MB, less than 56.10% of Ruby online submissions for Richest Customer Wealth.

# @param {Integer[][]} accounts
# @return {Integer}
def maximum_wealth(accounts)
  ans = 0
  for a in accounts
      cur = a.reduce(0) {|sum, x| sum+x}
      ans = cur > ans ? cur : ans
  end
  ans     
end
