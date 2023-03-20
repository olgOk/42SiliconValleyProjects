#!/usr/bin/php
<?php
    if ($argc != 4)
    {
        echo "error\n";
        exit();
    }
    $num1 = trim($argv[1]);
    $oper = trim($argv[2]);
    $num2 = trim($argv[3]);
    if ($oper == "+")
        echo $num1 + $num2;
    else if ($oper == "-")
        echo $num1 - $num2;
    else if ($oper == "*")
        echo $num1 * $num2;
    else if ($oper == "/")
        echo $num1 / $num2;
    else if ($oper == "%")
        echo $num1 % $num2;
    echo "\n";
?>