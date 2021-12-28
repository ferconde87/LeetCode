# Runtime: 76 ms, faster than 38.94% of Ruby online submissions for Remove Duplicates from Sorted Array.
# Memory Usage: 211.5 MB, less than 6.93% of Ruby online submissions for Remove Duplicates from Sorted Array.
# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
  n = nums.length
  i = 0
  j = n - 1
  count = 0
  for c in (0..n-2)
      count += 1 if nums[c] == nums[c+1]
  end
  i = 0
  while i < j
      while i < j and nums[j] == nums[j-1]
          j -= 1
      end
      while i < j and nums[i] != nums[i+1]
          i += 1
      end
      nums[i], nums[j] = nums[j], nums[i] if i < j
      i += 1
      j -= 1
  end
  nums[..(n-count-1)] = nums[..(n-count-1)].sort!
  n-count
end

# Runtime: 60 ms, faster than 81.85% of Ruby online submissions for Remove Duplicates from Sorted Array.
# Memory Usage: 210.7 MB, less than 99.67% of Ruby online submissions for Remove Duplicates from Sorted Array.
# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
  n = nums.length
  return 0 if n == 0
  uniq_index = 0
  for i in (0..n-1)
      if nums[uniq_index] != nums[i]
          uniq_index += 1
          nums[uniq_index], nums[i] = nums[i], nums[uniq_index]
      end
  end
  uniq_index+1
end
