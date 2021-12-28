# Runtime: 60 ms, faster than 96.64% of Ruby online submissions for Valid Sudoku.
# Memory Usage: 210 MB, less than 84.03% of Ruby online submissions for Valid Sudoku.
def valid_rows(board)
  for row in board
      seen_before = Array.new(10) { false }
      for pos in row
          next if pos == "."
          return false if seen_before[pos.to_i]
          seen_before[pos.to_i] = true
      end
  end
  true
end

def valid_columns(board)
  for col in 0..8
      seen_before = Array.new(10) { false }
      for row in 0..8
          pos = board[row][col]
          next if pos == "."
          return false if seen_before[pos.to_i]
          seen_before[pos.to_i] = true
      end
  end
  true    
end

def valid_box(board, row, col)
  seen_before = Array.new(10) { false }
  for i in 0..2
      for j in 0..2
          pos = board[row+i][col+j]
          next if pos == "."
          return false if seen_before[pos.to_i]
          seen_before[pos.to_i] = true
      end
  end
  true
end

def valid_boxes(board)
  (0..8).step(3).each do |i|
      (0..8).step(3).each do |j|
          return false if not valid_box(board, i, j)
      end
  end
  true
end

# @param {Character[][]} board
# @return {Boolean}
def is_valid_sudoku(board)  
  valid_rows(board) and valid_columns(board) and valid_boxes(board)
end
