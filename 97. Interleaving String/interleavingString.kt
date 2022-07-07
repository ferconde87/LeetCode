fun isInterleave(s1: String, s2: String, s3: String): Boolean {
    val n1 = s1.length
    val n2 = s2.length
    val n3 = s3.length
    if(n1 + n2 != n3) return false
    var result = false
    var seen = Array(n1+1) {IntArray(n2+1) {0} }
    fun isInterleaveRec(i: Int, j: Int, k: Int): Int {
        if(k == n3) { result = true; return 1 }
        if(i < n1 && k < n3 && s1[i] == s3[k] && seen[i+1][j] == 0) { seen[i+1][j] = isInterleaveRec(i+1, j,k+1) }
        if(j < n2 && k < n3 && s2[j] == s3[k] && seen[i][j+1] == 0) { seen[i][j+1] = isInterleaveRec(i, j+1, k+1) }
        return -1
    }
    isInterleaveRec(0,0,0)
    return result
}

fun main() {
    var s1 = "aabcc"
    var s2 = "dbbca"
    var s3 = "aadbbcbcac"
    println(isInterleave(s1,s2,s3))
    s1 = "aabcc"
    s2 = "dbbca"
    s3 = "aadbbbaccc"
    println(isInterleave(s1,s2,s3))
    s1 = ""
    s2 = ""
    s3 = ""
    println(isInterleave(s1,s2,s3))
    s1 = "a"
    println(isInterleave(s1,s2,s3))
    s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
    s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
    s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
    println(isInterleave(s1,s2,s3))
}