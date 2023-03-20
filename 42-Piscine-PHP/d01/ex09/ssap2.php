#!/usr/bin/php
<?php
    function	is_chr($ch)
	{
		
		if ($ch >= 'a' && $ch <= 'z')
			return TRUE;
		else
			return FALSE;
	}
	function	is_num($ch)
	{
		if ($ch >= '0' && $ch <= '9')
			return TRUE;
		else
			return FALSE;
	}
	function	is_chrnum($ch)
	{
		if (is_chr($ch) || is_num($ch))
			return TRUE;
		else
			return FALSE;
	}
	function	is_notchrnum($ch)
	{
		if (!is_chr($ch) && !is_num($ch))
			return TRUE;
		else
			return FALSE;
	}
	function	ascii_sort($arg1, $arg2)
	{
		$str1 = strtolower($arg1);
		$str2 = strtolower($arg2);
		$len1 = strlen($arg1);
		$len2 = strlen($arg2);
		$i = 0;
		while ($i < $len1 && $i < $len2) 
		{
			if ($str1[$i] != $str2[$i]) 
			{
				if (is_chr($str1[$i]) && is_chr($str2[$i])) 
				{
					return ord($str1[$i]) - ord($str2[$i]);
				}
				else if (is_num($str1[$i]) && is_num($str2[$i])) 
				{
					return ord($str1[$i]) - ord($str2[$i]);
				}
				else if (is_chr($str1[$i]) && is_num($str2[$i])) 
				{
					return -1;
				}
				else if (is_num($str1[$i]) && is_chr($str2[$i])) 
				{
					return 1;
				}
				else if (is_chrnum($str1[$i]) && is_notchrnum($str2[$i])) 
				{
					return -1;
				}
				else if (is_notchrnum($str1[$i]) && is_chrnum($str2[$i])) 
				{
					return 1;
				}
				else if (is_notchrnum($str1[$i]) && is_notchrnum($str2[$i]))
				{
					return ord($str1[$i]) - ord($str2[$i]);
				}
			}
			$i++;
		}
		return $len1 - $len2;
    }

    if ($argc > 1)
    {
        unset($argv[0]);
	    $str = implode(" ", $argv);
	    $arr = explode(" ", $str);
	    usort($arr, 'ascii_sort');
	    foreach ($arr as $val) {
		    echo $val."\n";
        }
    }
?>