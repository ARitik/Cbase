
proc fac {n} {
    set result 1
    for {set i 1} {$i <= $n} {incr i} {
        set result [expr {$result*$i}]
    }
    return $result
}

puts "Enter a num: "
gets stdin num
puts "You entered: $num\nFactorial is: " 
puts [fac $num] 
