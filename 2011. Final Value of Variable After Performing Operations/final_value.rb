# @param {String[]} operations
# @return {Integer}
def final_value_after_operations(operations)
  ans = 0
  operations.each { |op| 
      ans += if op == "++X" or op == "X++" then 1 else -1 end
  }
  ans
end

def final_value_after_operations2(operations)
  ans = 0
  operations.each do |word|
      if word.include?("-")
          ans -= 1
      else
          ans += 1
      end
  end
  ans
end

def final_value_after_operations3(operations)
  ans = 0
  operations.each do |op| 
      if op[1] == "+"
          ans += 1
      else
          ans -= 1
      end
  end
  ans
end


def final_value_after_operations4(operations)
  operations.reduce(0) {|sum, op| if op[1] == "+" then sum+1 else sum-1 end}    
end

def final_value_after_operations(operations)
  operations.reduce(0) {|sum, op| op[1] == "+" ? sum+1 : sum-1}
end
