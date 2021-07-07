set colors {red green blue yellow}

lappend colors orange

foreach x $colors {
    puts $x
}

set food {bread rice roti}
set combinedlist [concat $colors $food]

foreach x $combinedlist {
    puts $x
}