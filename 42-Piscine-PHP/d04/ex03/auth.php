<?php
    function auth($login, $passwd) {
        $arr = file_get_contents('../private/passwd');
        if ($arr === FALSE) {
            return FALSE;
        }
        $arr = unserialize($arr);
        foreach ($arr as $key) {
            if ($key['login'] === $login && $key['passwd'] === hash('whirlpool', $passwd)) {
                return TRUE;
            }
        }
        return FALSE;
    }
?>