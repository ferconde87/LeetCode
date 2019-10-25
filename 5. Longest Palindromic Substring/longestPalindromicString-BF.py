def isPalindrom(s):
    return s[::-1] == s

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        for k in range(n-1,-1,-1):
            for i in range(0, n-k):
                if isPalindrom(s[i:i+k+1]):
                    return s[i:i+k+1]
        return ""
