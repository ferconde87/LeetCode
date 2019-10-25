from math import sqrt
import sys

class Solution:
    def numSquares(self, n: int) -> int:
        nsqrt = int(sqrt(n))
        perfectSquares = [0]+[x**2 for x in range(1,nsqrt+1)]
        nps = len(perfectSquares)
        m = [[0]*(nps) for _ in range(n+1)]
        for i in range(n+1):
            m[i][0] = sys.maxsize
        for i in range(1,n+1):
            for j in range(1,nps):
                curPerfectSquare = perfectSquares[j]
                if curPerfectSquare > i:
                    m[i][j] = m[i][j-1]
                else:
                    m[i][j] = min(m[i][j-1],1+m[i-curPerfectSquare][j])
        return m[n][nps-1]
        
