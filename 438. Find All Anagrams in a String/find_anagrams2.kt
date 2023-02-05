fun findAnagrams(s: String, p: String): List<Int> {
    val pc = IntArray(26)
    for (i in p) pc[i - 'a']++
    val result = mutableListOf<Int>()

    for (i in p.length until s.length) {
        pc[s[i] - 'a']--
        pc[s[i - p.length] - 'a']++
        if (pc.all { it == 0 }) result.add(i - p.length + 1)
    }
    return result
}