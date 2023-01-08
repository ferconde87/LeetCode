fun maxPoints(points: Array<IntArray>): Int {
    val pointsDouble = points.map { it.map { p -> p.toDouble() } }
    val n = points.size
    var ans = 1
    for (i in 0 until n) {
        var pointA = pointsDouble[i]
        for (j in i+1 until n) {
            var current = 2
            var pointB = pointsDouble[j]
            for (h in j+1 until n) {
                var pointC = pointsDouble[h]
                var slopeX = (pointB[1] - pointA[1]) * (pointC[0] - pointA[0]);
                var slopeY = (pointC[1] - pointA[1]) * (pointB[0] - pointA[0]);
                if (slopeX == slopeY) current++
            }
            if (current > ans) {
                ans = current
            }
        }
    }
    return ans
}