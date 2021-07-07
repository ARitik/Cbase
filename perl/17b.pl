@array=(1..10);
$count=1;
while($count<11)
{
    foreach $mul (@array)
    {
        $multiply=$count*$mul;
        push(@multifinal,$multiply);
    }
    print"@multifinal\n";
    @multifinal =() ;
    $count++;
}