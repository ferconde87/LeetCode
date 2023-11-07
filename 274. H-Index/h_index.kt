class Solution {
    fun hIndex(citations: IntArray): Int {
        val map: TreeMap<Int, Int> = TreeMap() // key = citation amount / value = papers cited that amount
        var sum = 0
        for (citation_amount in citations) {
            if (citation_amount == 0) continue
            val amount = map.getOrDefault(citation_amount, 0)
            map.put(citation_amount, amount + 1)
        }
        for ((citation_amount, amount) in map.descendingMap()) {
            if (sum > citation_amount) return sum
            if ((sum + amount) >= citation_amount) return citation_amount
            sum += amount
        }
        return sum
    }
}
