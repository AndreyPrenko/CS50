<?php
    // configuration
    require("../includes/config.php"); 
    
     if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // Fill the array of user shares
        $rows = CS50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        render("sell_form.php", ["title" => "Sell", "symbols" => $rows]);
    }
    
    
    // if form was submitted
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Validate the name
        if (empty($_POST["code"]))
        {
            apologize("Please enter the stock symbol.");
        }
        
        // Query the Yahoo
        $stock = lookup($_POST["code"]);
        
        // Check if we returned nothing
        if ($stock === false)
        {
            apologize("Entered stock symbol was invalid.");
        }
        else
        {
            // Query the amount of user shares
            $rows = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["code"]));
            if (count($rows) == 1)
            {
                $shares = $rows[0]["shares"];
            }
            else
            {
                apologize("Shares for specified symbol not found.");
            }
        
            $value = $stock["price"] * $shares;
            
            // Delete the user stocks
            $query = CS50::query("DELETE FROM portfolios where user_id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["code"]));
            if ($query === false)
            {
                apologize("Error while selling shares.");
            }
            
            // Update users cash
            $query = CS50::query("UPDATE users SET cash = cash + ? where id = ?", $value, $_SESSION["id"]);
            if ($query === false)
            {
               apologize("Error while selling shares.");
            }
               
            $_SESSION["cash"] += $value;
            
            // Log the history
            $query = CS50::query("INSERT INTO history(user_id, action, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, Now())",
                $_SESSION["id"], "SELL", strtoupper($_POST["code"]), $shares, $stock["price"]);
            
            // Redirect to home
            redirect("/");
        }
    }
    
?>