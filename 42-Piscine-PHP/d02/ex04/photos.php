#!/usr/bin/php
<?php
    if ($argc != 2)
        exit ();
    
    $page = file_get_contents($argv[1]);
    if ($page)
    {
        preg_match_all("/<img.*src=\"([^\"]*)\"/i", $page, $img_tag);
        $dir = strchr($argv[1] , '/').PHP_EOL;
        $dir = trim($dir, "/\n");
        if (file_exists($dir) === FALSE)
            mkdir($dir, 0755);
        foreach ($img_tag[1] as $value)
        {
            $url = $argv[1].$value;
            $filename = basename($url);
            file_put_contents($dir."/".$filename, file_get_contents($url));
        }
    }

?>