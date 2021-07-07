puts "Enter string: "
s = gets.chomp

puts "Enter number of copies: "
n=gets.chomp.to_i

def multiple_strings(str,m)
    return str*m
end

$i = 1

while $i <= n do
    puts multiple_strings(s,$i)
    $i+=1
end