fun gifting_groups(matrix: Array<IntArray>): Int {
    val n = matrix.size
    val parent = IntArray(n) {it}

    var groups = n

    fun root(i: Int): Int {
        var child = i
        var p = child
        while(child != parent[child]) {
            p = parent[child]
            parent[child] = parent[p]
            child = p
        }
        return p
    }

    fun union(i: Int, p: Int) {
        var child = i
        while(child != parent[child]) {
            var temp = parent[child]
            parent[child] = p
            child = temp
        }
        parent[i] = p
    }

    for(i in 0 until n) {
        for(j in i+1 until n) {
            if(i == j) continue
            if (matrix[i][j] == 0) continue
            var root_i = root(i)
            var root_j = root(j)
            if (root_i == root_j) continue
            union(j, root(i))
            groups--
        }
    }

    return groups
}

fun main() {
    repeat(readInt()) {
        var n = readInt()
        var matrix = Array<IntArray>(n) { readInts() }
        println(gifting_groups(matrix))
    }
}

private fun readInt() = readLine()!!.toInt()

private fun readInts(): IntArray = readLine()!!.split(" ").map {it.toInt()}.toIntArray()