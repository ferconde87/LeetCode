# Runtime: 256 ms, faster than 54.55% of Ruby online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
# Memory Usage: 224 MB, less than 45.45% of Ruby online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
# @param {String} n
# @return {Integer}
def min_partitions(n)
  ans = 0
  for x in n.split("")
      ans = x.to_i > ans ? x.to_i : ans
  end
  ans
end

# Runtime: 168 ms, faster than 86.36% of Ruby online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
# Memory Usage: 221.1 MB, less than 81.82% of Ruby online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
def min_partitions(n)
  n.chars.max.to_i
end

