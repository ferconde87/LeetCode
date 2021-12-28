# Runtime: 56 ms, faster than 52.94% of Ruby online submissions for Middle of the Linked List.
# Memory Usage: 209.7 MB, less than 52.94% of Ruby online submissions for Middle of the Linked List.
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @return {ListNode}
def middle_node(head)
  slow = head
  fast = head
  while fast.next != nil
      slow = slow.next
      fast = fast.next
      break if fast.next == nil
      fast = fast.next
  end
  slow
end
