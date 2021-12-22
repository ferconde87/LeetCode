# Runtime: 88 ms, faster than 56.52% of Ruby online submissions for Reorder List.
# Memory Usage: 212.8 MB, less than 82.61% of Ruby online submissions for Reorder List.

# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @return {Void} Do not return anything, modify head in-place instead.
def reorder_list(head)
  stack = []
  node = head
  n = 0
  while node != nil
      stack << node
      node = node.next
      n += 1
  end
  
  left = head
  while !stack.empty?
      right = stack.pop
      break if left == right
      next_left = left.next
      left.next = right
      if right != next_left
          right.next = next_left
          left = next_left
      else
          right.next = nil
          break
      end
  end
  if n % 2 == 1
      left.next = nil
  end
  head
end
