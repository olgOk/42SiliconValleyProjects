#!/usr/bin/php
<?php

    function    ft_split(string $str):array
    {
        $arr = explode(" ", $str);
        $arr = array_filter($arr);
        sort($arr);
        return $arr;
    }

    if ($argc > 1)
    {
        $arr = array();
        $i = 1;
        while ($i < $argc)
        {
            $arr =  array_merge($arr, ft_split($argv[$i]));
            $i++;
        }
        sort($arr);
        $i = 0;
        while ($i < count($arr))
        {
            echo $arr[$i]."\n";
            $i++;
        }
    }
?>