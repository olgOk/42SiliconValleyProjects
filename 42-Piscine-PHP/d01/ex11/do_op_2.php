#!/usr/bin/php
<?php
    if ($argc =! 2)
    {
        echo "error\n";
        exit();
    }
    if (preg_match("/^[ \t]*([-+]?\d+)[ \t]*([\+\-\*\/\%])[ \t]*([-+]?\d+)[ \t]*$/", $argv[1], $match) === 0)
    {
        echo "Syntax Error\n";
        exit();
    }
    $num1 = $match[1];
    $oper = $match[2];
    $num2 = $match[3];
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