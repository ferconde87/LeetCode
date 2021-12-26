# Runtime: 112 ms, faster than 92.04% of Ruby online submissions for Container With Most Water.
# Memory Usage: 216.5 MB, less than 42.79% of Ruby online submissions for Container With Most Water.
# @param {Integer[]} height
# @return {Integer}
def max_area(height)
  left = 0
  right = height.length - 1
  max = 0
  while left < right do
      cur = [height[left], height[right]].min * (right - left)
      max = cur if cur > max
      if height[left] > height[right]
          right -= 1
      else
          left += 1
      end
  end
  max
end
