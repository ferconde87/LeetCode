def isCharByChar(w, s):
    for i in range(len(w)-1, 0, -1):
        if w[:i] not in s:
            return False
    return True

class Solution:
    
    def longestWord(self, words: List[str]) -> str:
        words = sorted(words, key = lambda x : (-len(x), x))
        s = set(words)
        for w in words:
            if isCharByChar(w,s):
                return w
        return words[len(words)-1]