set prod 1 
set i 1

while {$i<=10} {
    set prod [expr {$prod*$i}]
    incr i
}

puts $prod