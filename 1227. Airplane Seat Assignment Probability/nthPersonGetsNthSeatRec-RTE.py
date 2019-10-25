def nthPersonGetsNthSeatRec(n):
    if n == 1:
        return 1
    return 1/n + (n-2)/n * nthPersonGetsNthSeatRec(n-1)

class Solution:
    def nthPersonGetsNthSeat(self, n: int) -> float:
        if n == 1:
            return 1
        return nthPersonGetsNthSeatRec(n)
