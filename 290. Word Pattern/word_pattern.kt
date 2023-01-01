fun wordPattern(pattern: String, s: String): Boolean {
    val map = hashMapOf<Char, String>()

    val words : List<String> = s.split(" ")

    val ps = pattern.length
    val ws = words.size

    if(ps != ws) return false

    var index = 0
    pattern.forEach { p ->
        if (map.containsKey(p)) {
            val value = map[p]
            if (value != words[index]) {
                return false
            }
        } else {
            map[p] = words[index]
        }
        index++
    }

    val uniquePatterns = map.keys.size
    val uniqueWords = words.toSet().size
    if (uniquePatterns != uniqueWords) {
        return false
    }

    return true
}
