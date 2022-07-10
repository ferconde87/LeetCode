// Runtime: 755 ms, faster than 94.91% of Kotlin online submissions for K Closest Points to Origin.
// Memory Usage: 60.7 MB, less than 97.22% of Kotlin online submissions for K Closest Points to Origin.
fun kClosest(points: Array<IntArray>, k: Int): Array<IntArray> {
    val n = points.size
    val distances: Array<IntArray> = Array(n) {intArrayOf(0,0)}
    for (i in 0 until n) {
        var x = points[i][0]
        var y = points[i][1]
        var distance = x*x + y*y
        distances[i] = intArrayOf(distance, i)
    }

    distances.sortWith(compareBy({ it[0]}, { it[1]}))

    val result: Array<IntArray> = Array(k) {intArrayOf(0,0)}
    for (i in 0 until k) {
        result[i] = points[distances[i][1]]
    }

    return result
}


fun kClosest2(points: Array<IntArray>, k: Int): Array<IntArray> =
    points.sortedBy{it[0]*it[0]+it[1]*it[1]}.take(k).toTypedArray()


fun main() {

}