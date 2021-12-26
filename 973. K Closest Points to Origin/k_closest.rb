# Runtime: 384 ms, faster than 34.69% of Ruby online submissions for K Closest Points to Origin.
# Memory Usage: 214.3 MB, less than 40.82% of Ruby online submissions for K Closest Points to Origin
# @param {Integer[][]} points
# @param {Integer} k
# @return {Integer[][]}
def k_closest(points, k)
  ans = []
  for p in points
      square_dist = p[0]*p[0] + p[1]*p[1]
      ans << [square_dist, p]
  end
  ans.sort!
  ans[..k-1].map{|x| x[1]}
end


# Runtime: 236 ms, faster than 93.88% of Ruby online submissions for K Closest Points to Origin.
# Memory Usage: 211.9 MB, less than 71.43% of Ruby online submissions for K Closest Points to Origin.
def k_closest(points, k)
  points.sort_by!{|p| p[0]*p[0] + p[1]*p[1]}[..k-1]
end

# Runtime: 232 ms, faster than 95.92% of Ruby online submissions for K Closest Points to Origin.
# Memory Usage: 211.9 MB, less than 69.39% of Ruby online submissions for K Closest Points to Origin.
def k_closest(points, k)
  points.sort_by!{|p| p[0]*p[0] + p[1]*p[1]}.first(k)
end
