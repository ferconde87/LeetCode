//Runtime: 314 ms, faster than 100.00% of Kotlin online submissions for Check If a String Contains All Binary Codes of Size K.
//Memory Usage: 42.6 MB, less than 100.00% of Kotlin online submissions for Check If a String Contains All Binary Codes of Size K.

import kotlin.math.pow

class Solution {
  fun hasAllCodes(s: String, k: Int): Boolean {
    if(k >= 19) return false
    val total = 2.0.pow(k).toInt()
    if(total > s.length) return false
    val seen = BooleanArray(total){ false }
    var current: String = s.substring(0, k)
    var counter = 0

    fun toBinary(str: String) : Int {
      var mult = 1
      var result = 0
      for(i in k-1 downTo 0) {
        var x = str[i] - '0'
        result += x*mult
        mult*=2
      }
      return result
    }

    var num = toBinary(current)

    seen[num] = true
    counter++
    val mask = 2.0.pow(k-1).toInt() - 1
    for (i in (k..s.length-1)) {
      num = num.and(mask)
      num = num shl 1
      num += (s[i] - '0')
      if(!seen[num]) {
        counter++
        seen[num] = true
        if(counter == total)
          return true
      }
    }
    return false
  }
}

fun main() {
    println(hasAllCodes("00110101101011",3))
    println(hasAllCodes("00110110",2))
    println(hasAllCodes("00",1))
    println(hasAllCodes("01",1))
    println(hasAllCodes("10",1))
    println(hasAllCodes("11",1))
    println(hasAllCodes("0",1))
    println(hasAllCodes("1",1))
    println(hasAllCodes("0",2))
}
