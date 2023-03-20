#!/usr/bin/php
<?php
    while(1)
    {
        echo "Enter a number: ";
        $num = trim(fgets(STDIN));
        if (feof(STDIN))
        {
            echo "\n";
            exit;
        }
        if (is_numeric($num))
        {
            $parity = ($num % 2 == 0) ? ("even") : ("odd");
            echo "The number ".$num." is ".$parity;
        }
        else
        {
            echo "'".$num."'"." is not a number";
        }
        echo "\n";
    }
?>