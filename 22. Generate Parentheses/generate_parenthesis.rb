# Runtime: 64 ms, faster than 64.84% of Ruby online submissions for Generate Parentheses.
# Memory Usage: 210.5 MB, less than 74.73% of Ruby online submissions for Generate Parentheses.
# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)
  ans = []
  backtracking(ans, 0, 0, "", n)
  ans
end

def backtracking(ans, open, close, current, max)
  if current.length == 2*max
      ans << current
  end
  backtracking(ans, open+1, close, current + "(", max) if open < max
  backtracking(ans, open, close+1, current + ")", max) if close < open
end
