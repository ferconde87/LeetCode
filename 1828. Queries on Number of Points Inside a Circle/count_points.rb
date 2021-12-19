# Runtime: 608 ms, faster than 25.00% of Ruby online submissions for Queries on Number of Points Inside a Circle.
# Memory Usage: 210.5 MB, less than 25.00% of Ruby online submissions for Queries on Number of Points Inside a Circle.
# @param {Integer[][]} points
# @param {Integer[][]} queries
# @return {Integer[]}
def count_points(points, queries)
  ans = []
  for q in queries
      count = 0
      for p in points
          distance = Math.sqrt((q[0]-p[0])**2+(q[1]-p[1])**2)
          if distance <= q[2]
              count += 1
          end
      end
      ans << count
  end
  ans
end

# Runtime: 488 ms, faster than 100.00% of Ruby online submissions for Queries on Number of Points Inside a Circle.
# Memory Usage: 210.3 MB, less than 25.00% of Ruby online submissions for Queries on Number of Points Inside a Circle.
# @param {Integer[][]} points
# @param {Integer[][]} queries
# @return {Integer[]}
def count_points(points, queries)
  ans = []
  for q in queries
      count = 0
      for p in points
          distance_square = (q[0]-p[0])**2+(q[1]-p[1])**2
          if distance_square <= q[2]*q[2]
              count += 1
          end
      end
      ans << count
  end
  ans
end
