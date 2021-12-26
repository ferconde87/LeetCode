# Runtime: 76 ms, faster than 19.69% of Ruby online submissions for String to Integer (atoi).
# Memory Usage: 210.2 MB, less than 19.69% of Ruby online submissions for String to Integer (atoi).
# @param {String} s
# @return {Integer}

def numeric?(lookAhead)
  lookAhead =~ /[0-9]/
end

def my_atoi(s)
    s = s.strip
    return 0 if s.empty? 
    is_negative = (s[0] == "-")
    ans = ""
    for i in (0..s.length-1)
        c = s[i]
        next if (i==0 and (c == "-" or c == "+"))
        break if not numeric?(c)
        ans << c
    end
    (is_negative) ? [ans.to_i*-1, -2147483648].max  : [ans.to_i, 2147483647].min
end
