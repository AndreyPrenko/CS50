<?php
    // configuration
    require("../includes/config.php");
    
    // Query current users shares
    $rows = CS50::query("SELECT  action, symbol, shares, price, date FROM history
        WHERE user_id = ? order by date desc", $_SESSION["id"]);
    
    if (count($rows) == 0)
    {
        apologize("No recorded transactions for this user exist.");
    }
    // render history
    render("history_form.php", ["title" => "History", "history" => $rows]);
?>