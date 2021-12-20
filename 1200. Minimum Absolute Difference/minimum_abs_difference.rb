# Time complexity: O(N^2)

# @param {Integer[]} arr
# @return {Integer[][]}
def minimum_abs_difference(arr)
  ans = []
  n = arr.length
  min_diff = 2000000
  for i in 0..n-1
      for j in i+1..n-1
          diff = (arr[i]-arr[j]).abs
          if diff == min_diff
              if (arr[i] < arr[j])
                  ans << [arr[i], arr[j]]
              else
                  ans << [arr[j], arr[i]]
              end
          else 
              if diff < min_diff
                  min_diff = diff
                  ans = (arr[i] < arr[j]) ? [[arr[i], arr[j]]] : [[arr[j], arr[i]]]
              end
          end
      end
  end
  ans.sort!
end

# Runtime: 152 ms, faster than 27.27% of Ruby online submissions for Minimum Absolute Difference.
# Memory Usage: 214.8 MB, less than 90.91% of Ruby online submissions for Minimum Absolute Difference.
# @param {Integer[]} arr
# @return {Integer[][]}
def minimum_abs_difference(arr)
  ans = []
  arr.sort!
  n = arr.length
  min_diff = 2000000
  for i in 1..n-1
      diff = arr[i]-arr[i-1]
      if diff < min_diff
          min_diff = diff
      end
  end
  for i in 1..n-1
      diff = arr[i]-arr[i-1]
      if diff == min_diff
          ans << [arr[i-1], arr[i]]
      end
  end
  ans
end


# Runtime: 124 ms, faster than 90.91% of Ruby online submissions for Minimum Absolute Difference.
# Memory Usage: 215 MB, less than 54.55% of Ruby online submissions for Minimum Absolute Difference.
# @param {Integer[]} arr
# @return {Integer[][]}
def minimum_abs_difference(arr)
  ans = []
  arr.sort!
  n = arr.length
  min_diff = 2000000
  for i in 1..n-1
      diff = arr[i]-arr[i-1]
      if diff < min_diff
          min_diff = diff
          ans = [[arr[i-1], arr[i]]]
      else
          if diff == min_diff
              ans << [arr[i-1], arr[i]]
          end
      end
  end
  ans
end
