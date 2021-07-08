<html>
<head></head>
<body>
    <?php
    //Print prime numbers
    for($i=1;$i<=50;$i++) {
        $c=0;
        for($j=1;$j<=$i;$j++) {
            if($i%$j==0) {
                $c++;
            }
        }

    
    if($c==2) {
        echo "prime number $i </br>";
    }
}

    ?>
</body>
</html>