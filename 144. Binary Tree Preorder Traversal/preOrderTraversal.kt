/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class TreeNode(var `val`: Int) {
    val left: TreeNode? = null
    var right: TreeNode? = null
}
fun preorderTraversal(root: TreeNode?): List<Int> {
    if (root == null) return listOf<Int>()
    var deque = ArrayDeque<TreeNode>()
    var list = mutableListOf<Int>()
    deque.add(root)
    while (!deque.isEmpty()) {
        var node: TreeNode = deque.removeFirst()
        list.add(node.`val`)
        if (node.right != null) {
            node.right?.let { deque.addFirst(it) }
        }
        if (node.left != null) {
            node.left?.let { deque.addFirst(it ) }
        }
    }
    return list
}
