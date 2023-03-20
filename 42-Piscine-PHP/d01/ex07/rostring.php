#!/usr/bin/php
<?php
    if ($argc > 1)
    {
        $arr = array();
        $arr = array_values(array_filter(explode(' ', $argv[1])));
		$arr[count($arr)] = $arr[0];
        unset($arr[0]);
        $i = 1;
        $ret = "";
        while($i <= count($arr))
        {
            $ret .= $arr[$i]." ";
            $i++;
        }
        $ret = trim($ret);
        $ret = ltrim($ret);
        echo $ret."\n";
    }
?>