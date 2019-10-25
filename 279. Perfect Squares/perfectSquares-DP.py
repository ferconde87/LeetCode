from math import sqrt
class Solution(object):
    def numSquares(self,n):
        dp = [0] * (n+1)
        for i in range(1,n+1):
            dp[i] = min([dp[i-j*j] for j in range(1,int(sqrt(i))+1)])+1
        return dp[n]
