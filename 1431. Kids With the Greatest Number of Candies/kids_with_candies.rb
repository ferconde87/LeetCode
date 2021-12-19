# Runtime: 60 ms, faster than 64.29% of Ruby online submissions for Kids With the Greatest Number of Candies.
# Memory Usage: 210.1 MB, less than 17.86% of Ruby online submissions for Kids With the Greatest Number of Candies.
# @param {Integer[]} candies
# @param {Integer} extra_candies
# @return {Boolean[]}
def kids_with_candies(candies, extra_candies)
  greatest = candies.max
  ans = []
  for c in candies
      ans << (c+extra_candies >= greatest) ? true : false
  end
  ans
end


# Runtime: 52 ms, faster than 82.14% of Ruby online submissions for Kids With the Greatest Number of Candies.
# Memory Usage: 210.1 MB, less than 17.86% of Ruby online submissions for Kids With the Greatest Number of Candies.
# @param {Integer[]} candies
# @param {Integer} extra_candies
# @return {Boolean[]}
def kids_with_candies(candies, extra_candies)
  max = candies.max
  candies.map{|c| c + extra_candies >= max}
end
