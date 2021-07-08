<?php
$a = [2,3,1,5,4];
$b= [7,2,9,5,8];

$c = array_merge($a,$b);
rsort($c);

echo "Length of resultant array is ".count($c)."</br>";
foreach($c as $value) {
    echo "$value </br>";
}
?>