fun fib(n: Int): Int {
    if (n <= 1) return n
    var last = 0
    var current = 1
    for (i in 2..n) {
        var temp = last + current
        last = current
        current = temp
    }
    return current
}

fun main() {
    for (n in 0..30) {
        println(fib(n))
    }
}