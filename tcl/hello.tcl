set file1 [open "file1.txt" w+]
set file2 [open "file2.txt" w+]
set res 2

 if ![file exists $file2] {
      return 1
   } else {
      # Assume file1 exists
      puts [expr[clock format [file mtime file1]]]
    
      
   }

puts $fm1