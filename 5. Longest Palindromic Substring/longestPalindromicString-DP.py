    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n <= 1:
            return s
        m = [[1] * n for i in range(n)]
        result = s[0]
        size = 1
        for i in range(1,n):
            for j in range(0,n-i):
                m[j][j+i] = m[j+1][j+i-1] and s[j] == s[j+i]
                if m[j][j+i] and i+1 > size:
                    result = s[j:j+i+1]
                    size = i+1
        return result
