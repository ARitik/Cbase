puts "Enter first temperature: "
temp1=gets.chomp.to_i
puts "Enter second temperature: "
temp2=gets.chomp.to_i


def checktemp(temp1,temp2)
    if (temp1<0 and temp2>100) or (temp1>100 and temp2<0)      
        return true
    else
        return false
    end
end

puts checktemp(temp1,temp2)