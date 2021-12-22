# Runtime: 128 ms, faster than 12.50% of Ruby online submissions for Decode XORed Array.
# Memory Usage: 211.2 MB, less than 75.00% of Ruby online submissions for Decode XORed Array.

# @param {Integer[]} encoded
# @param {Integer} first
# @return {Integer[]}
def decode(encoded, first)
  ans = [first]
  temp = first
  for e in encoded
      xor = (temp ^ e)
      ans << xor
      temp = xor
  end
  ans
end

# Runtime: 120 ms, faster than 37.50% of Ruby online submissions for Decode XORed Array.
# Memory Usage: 211.3 MB, less than 75.00% of Ruby online submissions for Decode XORed Array.
# @param {Integer[]} encoded
# @param {Integer} first
# @return {Integer[]}
def decode(encoded, first)
  ans = Array(encoded.length-+1)
  ans[0] = first
  encoded.each_with_index do |value, index|
      ans[index+1] = ans[index] ^ value
  end
  ans
end
