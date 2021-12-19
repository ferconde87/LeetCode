# Runtime: 432 ms, faster than 6.06% of Ruby online submissions for How Many Numbers Are Smaller Than the Current Number.
# Memory Usage: 210.4 MB, less than 87.88% of Ruby online submissions for How Many Numbers Are Smaller Than the Current Number.
# @param {Integer[]} nums
# @return {Integer[]}
def smaller_numbers_than_current(nums)
  ans = []
  n = nums.length
  for i in 0..n-1
      count = 0
      for j in 0..n-1
          count += (i != j and nums[i] > nums[j]) ? 1 : 0
      end
      ans << count
  end
  ans         
end

# Runtime: 84 ms, faster than 66.67% of Ruby online submissions for How Many Numbers Are Smaller Than the Current Number.
# Memory Usage: 210.3 MB, less than 90.91% of Ruby online submissions for How Many Numbers Are Smaller Than the Current Number.

# Time complexity: O(N log N)
# Space complexity: N

# @param {Integer[]} nums
# @return {Integer[]}
def smaller_numbers_than_current(nums)
  n = nums.length
  ans = Array.new(n)
  nums_with_index = []
  nums.each_with_index do |value, index|
      nums_with_index << [value,index]
  end
  nums_with_index.sort!
  ans[nums_with_index[0][1]] = 0
  for i in 1..n-1
      if nums_with_index[i][0] == nums_with_index[i-1][0]
          ans[nums_with_index[i][1]] = ans[nums_with_index[i-1][1]]
      else
          ans[nums_with_index[i][1]] = i 
      end
  end
  ans 
end

# Runtime: 64 ms, faster than 81.82% of Ruby online submissions for How Many Numbers Are Smaller Than the Current Number.
# Memory Usage: 210.7 MB, less than 9.09% of Ruby online submissions for How Many Numbers Are Smaller Than the Current Number.
# @param {Integer[]} nums
# @return {Integer[]}
def smaller_numbers_than_current(nums)
  n = nums.length
  ans = Array.new(n)
  sorted = nums.sort
  dict = {}
  sorted.each_with_index do |value, index|
      if !dict.key? value
          dict[value] = index
      end
  end
  nums.each_with_index do |value, index|
     ans[index] = dict[value]
  end
  ans 
end
