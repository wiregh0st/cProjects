<?php 
require("header.php");
?>

<?php
if(isset($_POST["userEmail"]))
{
    //store and sanitize user input email
    $userEmail = $_POST["userEmail"];
    $userEmail = filter_var($userEmail, FILTER_SANITIZE_EMAIL);
    if (filter_var($userEmail, FILTER_VALIDATE_EMAIL)) 
    {
        //if email good, write email to file with random value and a false
        $confirmedACC = "false";
        $randValue =  bin2hex(random_bytes(10));
        $fileOut = $userEmail . "," . $randValue . "," . $confirmedACC . "\n";
        require_once("emailIO.php");
	    $urlARGS = urlencode("email=" . $userEmail . "&" . "confirmation=" . $randValue);
        $message = "Confirm email at: http://localhost:8080/confirm.php?" . $urlARGS;
        mail("millerm30@winthrop.edu", "Confirm Your Account", $message, "From: subscribetest@email.com");
    } 
    else 
    {   
        //if email bad
        echo("$userEmail is not a valid email address");
    }   
}
?>



<?php
require("footer.php");
?>
