// Runtime: 496 ms, faster than 14.29% of Kotlin online submissions for Transpose Matrix.
// Memory Usage: 48.8 MB, less than 57.14% of Kotlin online submissions for Transpose Matrix.
fun transpose(matrix: Array<IntArray>): Array<IntArray> {
  val n = matrix.size
  val m = matrix[0].size
  val result: Array<IntArray> = Array(m) {IntArray(n){0} }
  for (i in 0.. n-1) {
    for (j in 0..m-1) {
      result[j][i] = matrix[i][j]
    }
  }
  return result
}
