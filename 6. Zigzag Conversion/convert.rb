# Runtime: 1944 ms, faster than 5.55% of Ruby online submissions for Zigzag Conversion.
# Memory Usage: 225.7 MB, less than 5.55% of Ruby online submissions for Zigzag Conversion.
# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
  k = 0
  j = 0
  n = s.length
  matrix = Array.new(num_rows){Array.new(s.length, "")}
  while k < n
      for i in (0..num_rows-1) do
          matrix[i][j] = s[k]    
          k += 1
      end
      for i in (num_rows-2).downto(1) do
          j += 1
          matrix[i][j] = s[k]
          k += 1
      end
      j += 1
  end
  ans = []
  for i in (0..num_rows-1) do
      for j  in (0..n-1) do
          if matrix[i][j] != ""
              ans << matrix[i][j]
          end
      end
  end
  ans.join("")
end


# Runtime: 92 ms, faster than 70.56% of Ruby online submissions for Zigzag Conversion.
# Memory Usage: 209.9 MB, less than 97.78% of Ruby online submissions for Zigzag Conversion.
# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
  k = 0
  matrix = Array.new(num_rows) { String.new }
  n = s.length
  while k < n
      for i in (0..num_rows-1) do
          matrix[i] << s[k].to_s
          k += 1
      end
      for i in (num_rows-2).downto(1) do
          matrix[i] << s[k].to_s
          k += 1
      end
  end
  matrix.join
end
