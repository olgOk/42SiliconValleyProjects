#!/usr/bin/php
<?php
  	if ($argc != 2)
			exit();
		date_default_timezone_set("Europe/Paris");
		if (preg_match("/^([A-Za-z][a-z]+) (\d\d?) ([A-Za-z][a-z]+) (\d\d\d\d) (\d\d):(\d\d):(\d\d)$/", $argv[1], $time) === 0)
		{
				echo "Wrong Format\n";
				exit();
		}
    $day = strtolower($time[1]);
    if ($day == "lundi" || $day == "mardi" || $day == "mercredi" || $day == "jeudi" || $day == "vendredi" ||
				$day == "samedi" || $day == "dimanche");
		else {
			echo "Wrong Format\n";
			exit ();
		}
    $month = strtolower($time[3]);
    if ($month == "janvier")
			$mon = 1;
		elseif ($month == "fevrier")
			$mon = 2;
		elseif ($month == "mars")
			$mon = 3;
		elseif ($month == "avril")
			$mon = 4;
		elseif ($month == "mai")
			$mon = 5;
		elseif ($month == "juin")
			$mon = 6;
		elseif ($month == "juillet")
			$mon = 7;
		elseif ($month == "aout")
			$mon = 8;
		elseif ($month == "septembre")
			$mon = 9;
		elseif ($month == "octobre")
			$mon = 10;
		elseif ($month == "novembre")
			$mon = 11;
		elseif ($month == "decembre")
			$mon = 12;
		else {
			echo "Wrong Format\n";
			exit ();
		}
		$seconds = mktime($time[5], $time[6], $time[7], $mon, $time[2], $time[4]);
		if (!$seconds)
			echo "Wrong Format\n";
		else
			echo $seconds."\n";
?>