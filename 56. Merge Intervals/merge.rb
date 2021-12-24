# Runtime: 76 ms, faster than 60.38% of Ruby online submissions for Merge Intervals.
# Memory Usage: 210.4 MB, less than 89.31% of Ruby online submissions for Merge Intervals.
# @param {Integer[][]} intervals
# @return {Integer[][]}
def merge(intervals)
  intervals.sort!
  ans = []
  i = 0
  n = intervals.length
  while i <= n-1 do
      cur = intervals[i]
      upper = cur[1]
      while i < n-1 and upper >= intervals[i+1][0] do
          upper = [upper, intervals[i+1][1]].max
          i = i+1
      end
      ans << [cur[0], upper]
      i = i+1
  end
  ans 
end
