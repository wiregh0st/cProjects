<?php
//if file already exists, open and read from file so contents can be retained.
if(file_exists("emailList.csv"))
{
    try {
        $emailIO = fopen("emailList.csv", "a+");
        fwrite($emailIO, $fileOut);
        header("Location: subscribe.php");
    }
    catch (Exception $e)
    {
        echo "Message: " . "$e";
    }
}
else
{
    //if file doesn't exist, input first entry
    try {
        $emailIO = fopen("emailList.csv", "w");
        fwrite($emailIO, $fileOut);
        header("Location: subscribe.php");
    }
    catch (Exception $e)
    {
        echo "Message: " . "$e";
    }
}
?>