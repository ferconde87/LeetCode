# Runtime: 44 ms, faster than 93.75% of Ruby online submissions for Subtract the Product and Sum of Digits of an Integer.
# Memory Usage: 209.8 MB, less than 37.50% of Ruby online submissions for Subtract the Product and Sum of Digits of an Integer.
# @param {Integer} n
# @return {Integer}
def subtract_product_and_sum(n)
  prod = 1
  sum = 0
  for c in n.to_s.split("")
      num = c.to_i
      prod *= num
      sum += num
  end
  prod - sum
end
