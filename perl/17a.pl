#!usr/bin/perl
print "Enter a number\n";
chomp($a=<stdin>);
print "Enter second number\n";
chomp($b=<stdin>);
print "Enter third number\n";
chomp($c=<stdin>);

$big=0;
$equal=0;

if($a eq $b && $b eq $c) {
    print "Numbers are equal\n";
} else {
    if($a>$b && $a>$c) {
        print "$a is greatest\n";
    } elsif($b>$a && $b>$c) {
        print "$b is greatest\n";
    } else {
        print "$c is greatest\n";
    }
}