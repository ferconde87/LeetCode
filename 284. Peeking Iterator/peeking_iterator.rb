# Runtime: 132 ms, faster than 27.27% of Ruby online submissions for Peeking Iterator.
# Memory Usage: 211 MB, less than 18.18% of Ruby online submissions for Peeking Iterator.


# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator
# 	def initialize(v)
#   
#   end
#
#   def hasNext()
#		Returns true if the iteration has more elements.
#   end
#
#   def next()
#   	Returns the next element in the iteration.
#   end
# end

class PeekingIterator
  # @param {Iterator} iter
  def initialize(iter)
      @index = 0
    @arr = []
      while iter.hasNext() do
          #item = iter.next()
          #if item.class == Integer
          #    @arr << item
          #end
          @arr << iter.next()
      end
  end
  
  # Returns true if the iteration has more elements.
  # @return {boolean}
  def hasNext()
    #@index < @arr.size
      @arr.size > 0
  end
  
  # Returns the next element in the iteration.
  # @return {integer}
  def next()
    item = @arr[@index]
      #@index += 1
      @arr.delete_at(0)
  end
  
  # Returns the next element in the iteration without advancing the iterator.
  # @return {integer}
  def peek()
    @arr[@index]
  end
end
