fun main() {
    fun isAnagram(p: String, pCounter: IntArray, sCounter:IntArray): Boolean {
        for (char in p) {
            if (pCounter[char-'a'] != sCounter[char-'a']) {
                return false
            }
        }
        return true
    }

    fun findAnagrams(s: String, p: String): List<Int> {
        if (p.length > s.length) return listOf()

        val result = mutableListOf<Int>()

        val sCounter = IntArray(26) { 0 }
        val pCounter = IntArray(26) { 0 }
        for ((index, char) in p.withIndex()) {
            sCounter[s[index]-'a']++
            pCounter[char - 'a']++
        }

        if (isAnagram(p, pCounter, sCounter)) {
            result.add(0)
        }

        var oldIndex = 0
        for (index in p.length until s.length) {
            sCounter[s[oldIndex]-'a']--
            oldIndex++
            sCounter[s[index]-'a']++
            if (isAnagram(p, pCounter, sCounter)) {
                result.add(oldIndex)
            }
        }

        for (elem in result) {
            print(elem)
            print(" ")
        }
        println()
        return result
    }

    findAnagrams("cbaebabacd", "abc")
    findAnagrams("abab", "ab")
}


