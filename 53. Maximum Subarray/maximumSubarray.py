class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return float('-inf')
        if all([x < 0 for x in nums]):
            return max(nums)
        current = 0
        result = 0
        for x in nums:
            current = max(0, current+x)
            if current > result:
                result = current
        return result
