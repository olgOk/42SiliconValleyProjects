#!/usr/bin/php
<?php
    function    ft_split(string $str):array
    {
        $arr = explode(" ", $str);
        $arr = array_filter($arr);
        sort($arr);
        return $arr;
    }
?>