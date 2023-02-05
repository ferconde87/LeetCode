fun main() {
    fun isAnagram(pCounter: IntArray, sCounter:IntArray): Boolean {
        for (i in 0...26) {
            if (pCounter[i] != sCounter[i]) {
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

        return result
    }

    findAnagrams("cbaebabacd", "abc")
    findAnagrams("abab", "ab")
    findAnagrams("cbaebabacd", "bacd")
    findAnagrams("qwertyxdcabx", "bacd")
    findAnagrams("qwertyxdcabxcad", "bacd")
    findAnagrams("qwertyxdcabxcadb", "bacd")
    findAnagrams("a", "b")
    findAnagrams("aa", "a")
}


