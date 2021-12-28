# Runtime: 56 ms, faster than 61.29% of Ruby online submissions for Remove Element.
# Memory Usage: 209.9 MB, less than 62.90% of Ruby online submissions for Remove Element.
# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}
def remove_element(nums, val)
  i = 0
  k = nums.length
  j = k-1
  while i <= j
      if nums[i] == val
          if nums[j] != val
              nums[i], nums[j] = nums[j], nums[i]
              i += 1
          end
          j -= 1
          k -= 1
      else
          i += 1
      end 
  end
  k
end
