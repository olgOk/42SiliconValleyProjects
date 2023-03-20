#!/usr/bin/php
<?php
    function ft_is_sort(array $arr)
    {
        $sort_arr = sort($arr);
        if ($sort_arr === $arr)
        {
            return TRUE;
        }
        return FALSE;
    }
?>