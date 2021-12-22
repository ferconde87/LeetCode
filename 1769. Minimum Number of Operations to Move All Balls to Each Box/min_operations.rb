#Time complexity O(N^2)
# @param {String} boxes
# @return {Integer[]}
def min_operations(boxes)
  n = boxes.length
  ans = Array.new(n)
  arr = boxes.split("").map {|x| x.to_i }
 for i in 0..n-1
     count = 0
     for j in 0..n-1
         count += ((i-j).abs * arr[j])
     end
     ans[i] = count
  end
  ans
end

#Time complexity O(N)
# Runtime: 88 ms, faster than 77.78% of Ruby online submissions for Minimum Number of Operations to Move All Balls to Each Box.
# Memory Usage: 210.6 MB, less than 11.11% of Ruby online submissions for Minimum Number of Operations to Move All Balls to Each Box.
# @param {String} boxes
# @return {Integer[]}
def min_operations(boxes)
  n = boxes.length
  ans = Array.new(n)
  arr = boxes.split("").map {|x| x.to_i }
  front = Array.new(n)
  back = Array.new(n)
  
  ones = arr.reduce(0) {|count, num| (num==1) ? count+1 : count }
  
  at_front = ones
  at_back = 0
  (0..n-1).each do |i|
      at_front -= (arr[i] == 1) ? 1 : 0
      front[i] = at_front
      back[i] = at_back
      at_back += (arr[i] == 1) ? 1 : 0
  end
  
  count = 0
  for j in 1..n-1
     count += j * arr[j]
  end
  ans[0] = count
  
  for i in 1..n-1
      count -= front[i]
      count += back[i]
      count -= 1 if arr[i] == 1
      ans[i] = count
  end

  ans
end
