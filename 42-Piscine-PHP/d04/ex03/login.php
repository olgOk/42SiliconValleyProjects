<?php
    include('auth.php');

    if ($_GET["login"] == FALSE || $_GET["passwd"] == FALSE) {
        echo "ERROR\n";
        exit();
    }
    if (auth($_GET['login'], $_GET['passwd']) === TRUE) {
        session_start();
        $_SESSION['loggued_on_user'] = $_GET['login'];
        echo "OK\n";
        exit();
    } else {
        echo "ERROR\n";
        exit();
    }
?>