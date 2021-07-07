puts "Enter first value: "
num1=gets.chomp.to_i
puts "Enter second value: "
num2=gets.chomp.to_i

def checknum(num1,num2)
    if num1==20 or num2==20
        return true

    else
        return num1+num2
    end
end

puts checknum(num1,num2)
