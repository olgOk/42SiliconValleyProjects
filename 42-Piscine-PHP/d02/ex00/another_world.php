#!/usr/bin/php
<?php
    if ($argc > 1)
    {
        $res = preg_replace("/\s+/", " ", trim($argv[1]));
        echo $res."\n";
    }
?>