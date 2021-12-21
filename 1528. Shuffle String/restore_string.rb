# Runtime: 64 ms, faster than 67.74% of Ruby online submissions for Shuffle String.
# Memory Usage: 210.2 MB, less than 96.77% of Ruby online submissions for Shuffle String.
# @param {String} s
# @param {Integer[]} indices
# @return {String}
def restore_string(s, indices)
  n = s.length
  ans = Array.new(n)
  for i in 0..n-1
      ans[indices[i]] = s[i]
  end
  ans.join
end

# Runtime: 48 ms, faster than 96.77% of Ruby online submissions for Shuffle String.
# Memory Usage: 210.3 MB, less than 77.42% of Ruby online submissions for Shuffle String.
# @param {String} s
# @param {Integer[]} indices
# @return {String}
def restore_string(s, indices)
  ans = Array.new(s.length)
  indices.each_with_index do |value, index|
      ans[value] = s[index]
  end
  ans.join
end
