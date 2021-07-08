<?php
$file1 = "a.txt";
$file2 = "b.txt";

$fp1 = fopen($file1,'r');
$fc1 = fread($fp1,filesize($file1));

echo "File 1 contents: $fc1 </br>";

$file2 = "b.txt";

$fp2 = fopen($file2,'w');
fwrite($fp2,$fc1);

echo "Contents from File 1 written to File 2 </br>";
$fp3 = fopen($file2,'r');
$fc2 = fread($fp3,filesize($file2));
echo "File 2 contents: $fc2 </br>";


?>