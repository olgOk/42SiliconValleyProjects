#!/usr/bin/php
<?php
    date_default_timezone_set('America/Los_Angeles');
    $who = fopen("/var/run/utmpx", 'r');
    while ($line = fread($who, 628))
    {
        $arr = unpack("a256user/a4id/a32line/ipid/itype/Itime", $line);
        if ($arr["type"] == 7)
            echo $arr["user"]."     ".$arr["line"]."  ".date("M j H:i", $arr["time"])."\n";
    }
    fclose($who);
?>