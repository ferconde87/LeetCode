class RandomizedSet() {
    val hashSet = HashSet<Int>()

    fun insert(`val`: Int): Boolean {
        return hashSet.add(`val`)
    }

    fun remove(`val`: Int): Boolean {
        return hashSet.remove(`val`)
    }

    fun getRandom(): Int {
        val randomIndex = (0..hashSet.size-1).random()
        return hashSet.elementAt(randomIndex)
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = RandomizedSet()
 * var param_1 = obj.insert(`val`)
 * var param_2 = obj.remove(`val`)
 * var param_3 = obj.getRandom()
 */
