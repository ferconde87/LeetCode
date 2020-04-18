class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        m = {0:-1}
        max_len = 0
        count = 0
        for i, x in enumerate(nums):
            count += 1 if x == 1 else -1
            if count in m:
                max_len = max(max_len, i - m[count])
            else:
                m[count] = i
        return max_len