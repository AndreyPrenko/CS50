<?php
    // configuration
    require("../includes/config.php"); 
    
     if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
        render("password_form.php", ["title" => "Reset Password"]);
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if ($_POST["confirmation"] != $_POST["password"])
        {
            apologize("Passwords do not match");
        }
        else
        {
          $query = CS50::query("UPDATE users SET hash = ? where id = ?", password_hash($_POST["password"], PASSWORD_DEFAULT), $_SESSION["id"]);
          

          
            if ($query === false)
            {
               apologize("Error while reseting password.");
            }
         
            // Redirect to home
            redirect("/");
        }
    }
    
?>