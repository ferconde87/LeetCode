class SeatManager(n: Int) {
    val tree : TreeSet<Int>

    init {
        tree = sortedSetOf()
        for (i in 1..n) {
            tree.add(i)
        }
    }

    fun reserve(): Int {
        val first = tree.first()
        tree.remove(first)
        return first
    }

    fun unreserve(seatNumber: Int) {
        tree.add(seatNumber)
    }
}
