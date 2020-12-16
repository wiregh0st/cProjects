<?php
require("header.php");
?>
<?php
if(file_exists("emailList.csv"))
{
    if($_SERVER["REQUEST_METHOD"] == "GET")
    {
        if(isset($_SERVER["QUERY_STRING"]))
        {   //store query string in queryOut
            parse_str(urldecode($_SERVER['QUERY_STRING']), $queryOut);
            try
            {
                $mailList = fopen("emailList.csv", "r");
                $contents = [];
                if(isset($queryOut["confirmation"]))
                {
                    while($line = fgets($mailList))
                    {   //if line from file found in queryOut, replace the false in the line with true in queryOut. send mail to user to confirm successful registration.
                        $found = strpos($line, $queryOut["confirmation"]);
                        if($found)
                        {
                            unset($contents[$line]);
                            $line = str_replace("false", "true", $line);
                            array_push($contents, $line);
                            mail("millerm30@winthrop.edu", "Account Confirmed", "Thanks for confirming!", "From: subscribetest@email.com");
                        }
                        else
                        {
                            array_push($contents, $line);
                        }
                    }
                }
                //if confirmation not present in query string, redirect user to email input.
                else
                {
                    header('Location: subscribe.php');
                }
                
                var_dump($contents);
                $mailList = fopen("emailList.csv", "w");
                foreach($contents as $value)
                {
                    fwrite($mailList, $value);
                }
            }
            catch (Exception $e)
            {
                echo "Message: " . $e;
            }
        }
    }
}
//if file doesn't exist, redirect back to subscribe page. this means confirm was being accessed without subscribe being accessed first and an email submitted.
else
{
    header('Location: subscribe.php');
}

?>
<?php
require("footer.php");
?>