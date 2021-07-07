@nums = (1,2,3,4);

print "Initially list is @nums \n";

push(@nums , 'five');

print "\n After push operation , list is @nums \n";

print "\n Value returned after shift : ",shift(@nums);

print "\n After shift operation , list is @nums \n";

unshift(@nums,'minusone',0);

print "\n After unshift operation , list is @nums \n";