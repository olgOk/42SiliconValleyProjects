<?php
    $exist = 0;
    if ($_POST['submit'] === "OK" && !empty($_POST['login']) && !empty($_POST['oldpw']) && !empty($_POST['newpw'])) {
        $arr = unserialize(file_get_contents('../private/passwd'));
        foreach($arr as $key => $user) {
            if ($user['login'] === $_POST['login'] && $user['passwd'] === hash('whirlpool', $_POST['oldpw'])) {
                $arr[$key]['passwd'] = hash('whirlpool', $_POST['newpw']);
                $exist = 1;
            }
        }
        if ($exist == 1) {
            file_put_contents('../private/passwd', serialize($arr));
            echo "OK\n";
        } else {
            echo "ERROR\n";
            exit ();
        }
    } else {
        echo "ERROR\n";
        exit ();
    }
?>