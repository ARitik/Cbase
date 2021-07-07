set file1 "/Users/ambadiritik/Desktop/Repository/review/tcl/file1.txt"
set file2 "/Users/ambadiritik/Desktop/Repository/review/tcl/file2.txt"

set ans [expr [file mtime $file1] > [file mtime $file2]]

if ($ans==0) {
    puts "File 2 modified recently"
} else {
    puts "File 1 modified recently"
}