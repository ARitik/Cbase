<?php

$str1 = "this is wt lab";
echo strlen($str1);
echo '<br/>';

$str2 = "welcome to wt lab";
echo "Numbers of words in $str2 is: ".str_word_count($str2)."</br>";

$str3 = "mango";
echo "Reverse of $str3 is ".strrev($str3)."</br>";

$str4 = "Some text here to search from";
$search = "text";

if(strpos($str4,$search)==false) {
    echo "String not found!</br>";
} else {
    echo "String found $search in $str4</br>";
}



?>