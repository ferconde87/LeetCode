class ListNode(var `val`: Int) {
    val value = `val`
    var next: ListNode? = null
}

fun getIntersectionNode2(headA:ListNode?, headB:ListNode?):ListNode? {
    val set: MutableSet<ListNode> = mutableSetOf()
    var nodeA = headA
    var nodeB = headB

    while(nodeA != null && nodeB != null) {
        if(nodeA != null) {
            if (set.contains(nodeA)) {
                return nodeA
            }
            set.add(nodeA)
            nodeA = nodeA.next
        }
        if(nodeB != null) {
            if (set.contains(nodeB)) {
                return nodeB
            }
            set.add(nodeB)
            nodeB = nodeB.next
        }
    }

    return null
}

fun printAdHoc(nodeA:ListNode?, nodeB:ListNode?) {
    if(nodeA != null) print("${nodeA.value}")
    else print("null")
    print(" vs ")
    if(nodeB != null) println("${nodeB.value}")
    else println("null")
}

fun getIntersectionNode(headA:ListNode?, headB:ListNode?):ListNode? {
    val set: MutableSet<ListNode> = mutableSetOf()
    var nodeA = headA
    var nodeB = headB
    while(nodeA != nodeB) {
        if (nodeA == null) nodeA = headB
        else nodeA = nodeA.next
        if (nodeB == null) nodeB = headA
        else nodeB = nodeB.next
    }

    return nodeA
}

fun main() {
    val headA = ListNode(1)
    val headB = ListNode(3)
    val nodeA2 = ListNode(9)
    headA.next = nodeA2
    val nodeA3 = ListNode(1)
    nodeA2.next = nodeA3
    val nodeC1 = ListNode(2)
    nodeA3.next = nodeC1
    headB.next = nodeC1
    val nodeC2 = ListNode(4)
    nodeC1.next = nodeC2
    println(getIntersectionNode(headA, headB))
}
