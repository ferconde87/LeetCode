    def isIsomorphic(self, s: str, t: str) -> bool:
        cs = Counter(s)
        ct = Counter(t)
        if list(cs.values()) != list(ct.values()):
            return False
        d = {}
        n = len(s)
        for i in range(n):
            c = s[i]
            if c in d:
                if d[c] != t[i]:
                    return False
            else:
                d[c] = t[i]
        return True   
