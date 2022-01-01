# Runtime: 117 ms, faster than 13.91% of Ruby online submissions for Remove Duplicates from Sorted List.
# Memory Usage: 210 MB, less than 83.48% of Ruby online submissions for Remove Duplicates from Sorted List.
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
def delete_duplicates(head)
  return nil if head == nil
  node = head
  last_ok = head
  while node.next != nil
      if last_ok.val == node.next.val
          node = node.next
          last_ok.next = nil
      else
          last_ok.next = node.next
          last_ok = node.next
          node = node.next
      end
  end
  head
end


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
def delete_duplicates(head)
  return nil if head == nil
  node = head
  while node.next
      if node.val == node.next.val
          node.next = node.next.next
      else
          node = node.next
      end
  end
  head
end
