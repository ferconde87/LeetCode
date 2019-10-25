class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        last_step = 2
        two_last_steps = 1
        for i in range(3,n+1):
            current = last_step + two_last_steps
            two_last_steps = last_step
            last_step = current
        return last_step
