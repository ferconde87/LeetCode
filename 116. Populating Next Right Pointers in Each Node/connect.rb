# Definition for Node.
# class Node
#     attr_accessor :val, :left, :right, :next
#     def initialize(val)
#         @val = val
#         @left, @right, @next = nil, nil, nil
#     end
# end

# Runtime: 184 ms, faster than 20.45% of Ruby online submissions for Populating Next Right Pointers in Each Node.
# Memory Usage: 240.2 MB, less than 15.91% of Ruby online submissions for Populating Next Right Pointers in Each Node.
# @param {Node} root
# @return {Node}
def connect(root)
    depths = []
    return nil if root == nil
    get_depths(root, depths, 0)
    for nodes in depths
        (0..nodes.length-2).each do |i|
            nodes[i].next = nodes[i+1]
        end
    end
    root
end

def get_depths(node, depths, level)
    if depths.length <= level
        depths << []
    end
    depths[level] << node
    get_depths(node.left, depths, level+1) if node.left != nil
    get_depths(node.right, depths, level+1) if node.right != nil
end
