#!/usr/bin/php
<?php
    if ($argc != 2)
        exit();
    $str = preg_replace("/[\s]+/", ' ', $argv[1]);
    $str = ltrim($str);
    $str = trim($str);
    echo $str."\n";
?>