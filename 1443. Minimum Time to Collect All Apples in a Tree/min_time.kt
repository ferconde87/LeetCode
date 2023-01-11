class TreeNode(val value: Int, var hasApplesBelow: Boolean) {
    val left: TreeNode? = null
    val right: TreeNode? = null
}

fun minTime(n: Int, edges: Array<IntArray>, hasApple: List<Boolean>): Int {
    val map = hashMapOf<Int, MutableList<Int>>()
    val seen = List<Boolean>(n) { false }

    for (edge in edges) {
        var list0 = map.getOrElse(edge[0], { mutableListOf<Int>() })
        list0.add(edge[1])
        var list1 = map.getOrElse(edge[1], { mutableListOf<Int>() })
        list0.add(edge[0])
    }

    // 1) build tree starting with map[0]

    // 2) add hasApplesBelow info

    // 3)
    // counter = count node where hasApplesBelow is true
    // if (root.hasApplesBelow) return 2 * counter - 2 (the 2 extra from root)
    // else 0
    return 0
}