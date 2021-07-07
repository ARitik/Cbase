Basheer = Hash("History" => 94,"Geography" => 72,"Civics" => 45)

sum = 0
Basheer.each do |key,value|
  puts "#{key} => #{value}"
  sum+=value
end

puts "Total marks: #{sum}"