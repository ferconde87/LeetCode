def get_letters_from_phone_number(digits)
  dict = 
      {"2" => ["a","b","c"],
       "3" => ["d","e","f"],
       "4" => ["g","h","i"],
       "5" => ["j","k","l"],
       "6" => ["m","n","o"],
       "7" => ["p","q","r", "s"],
       "8" => ["t","u","v"],
       "9" => ["w","x","y", "z"]}
  digits.chars.map{|c| dict[c]}
end

def rec(letters, index, ans)
  (@ans << ans; return) if letters.length == index
  for d in letters[index]
      rec(letters, index+1, ans + d)
  end
end

# @param {String} digits
# @return {String[]}
def letter_combinations(digits)
  return [] if digits.empty?
  @ans = []
  letters = get_letters_from_phone_number(digits)
  rec(letters, 0, "")
  return @ans
end
