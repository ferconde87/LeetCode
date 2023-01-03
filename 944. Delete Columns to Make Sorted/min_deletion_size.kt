fun minDeletionSize(strs: Array<String>): Int {
    val n = strs.size
    if (n == 0) return 0
    val wordLength = strs[0].length
    var columnToDelete = 0

    for (i in 0 until wordLength) {
        var orderOk = true
        for (j in 0 until n-1) {
            if (strs[j][i] > strs[j+1][i]) {
                orderOk = false
                break
            }
        }
        if (!orderOk) columnToDelete++
    }

    return columnToDelete
}