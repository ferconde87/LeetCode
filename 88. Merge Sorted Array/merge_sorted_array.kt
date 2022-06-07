fun merge(nums1: IntArray, m: Int, nums2: IntArray, n: Int): Unit {
    var i = 0
    var j = 0
    var k = 0
    
    var last = n+m-1
  
    while (i < m && j < n) {
      while (i < m && nums1[i] <= nums2[j]) {
        result[k] = nums1[i]
        ++i
        ++k
      }
      while (j < n && nums2[j] <= nums1[i]) {
        result[k] = nums2[j]
        ++j
        ++k
      }
    }

    while (i < m) {
      result[k] = nums1[i]
      ++i
      ++k
    }

    while (j < n) {
      result[k] = nums2[j]
      ++j
      ++k
    }

    for (k in 0..result.size-1) {
      nums1[k] = result[k]
    }
}


fun merge2(nums1: IntArray, m: Int, nums2: IntArray, n: Int): Unit {
  var last = n + m - 1
  var last1 = m-1

  fun move() {
    for (k in last downTo n) {
      nums1[k] = nums1[last1--]
    }
  }
  move()

  var i = n
  var k = 0
  var j = 0
  while (i < m+n && j < n) {
    while (i < m+n && nums1[i] <= nums2[j]) nums1[k++] = nums1[i++]
    while (j < n && i < m+n && nums2[j] <= nums1[i]) nums1[k++] = nums2[j++]
  }

  while (i < m+n) nums1[k++] = nums1[i++]
  while (j < n) nums1[k++] = nums2[j++]
}
