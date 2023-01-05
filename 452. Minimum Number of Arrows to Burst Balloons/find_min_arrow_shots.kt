//Constraints:
//1 <= points.length <= 105
//points[i].length == 2
//-231 <= xstart < xend <= 231 - 1

fun findMinArrowShots(points: Array<IntArray>): Int {
    points.sortWith(compareBy({it[0]}, {it[1]}))
    var lastEnd = points[0][1]
    var arrowCounter = 1
    for (point in points) {
        val currentStart = point[0]
        if (currentStart > lastEnd) {
            arrowCounter++
            lastEnd = point[1]
        } else {
            lastEnd = minOf(point[1], lastEnd)
        }
    }
    return arrowCounter
}