#!/usr/bin/php
<?php
    if ($argc != 2)
        exit();
    if (!file_exists($argv[1]))
        exit();
    $str = file_get_contents($argv[1]);
    preg_match_all('/(<a).*(title="(.*)").*(<\/a>)/', $str, $title);
    preg_match_all("/(<a.*>)(.*)<\/a>/", $str, $tag);
    foreach ($tag[2] as $val)
        $str = str_replace($val, strtoupper($val), $str);
    foreach ($title[3] as $val)
        $str = str_replace($val, strtoupper($val), $str);
    if (preg_match_all("/(<a[^<]*>)([^<]*<)/", $str, $tag))
    {
        foreach ($tag[2] as $val)
            $str = str_replace($val, strtoupper($val), $str);
    }
    file_put_contents("new_page.html", $str);
?>