fun detectCapitalUse(word: String): Boolean {
    val size = word.length
    if (size <= 1) return true
    var uppercaseCounter = 0
    word.forEach { ch ->
        if (ch.isUpperCase()) {
            uppercaseCounter++
        }
    }

    if (uppercaseCounter == 0 || uppercaseCounter == size) return true

    if (uppercaseCounter == 1 && word[0].isUpperCase()) return true

    return false
}