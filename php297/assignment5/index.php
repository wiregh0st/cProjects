<?php

$callListResouce = fopen("callList.csv", "r");


if(!is_resource($callListResouce))
{
    echo "Could not open the file";
    exit();
}
while($line = fgets($callListResouce))
{
    $companies[] = explode(",", $line);
}


fclose($callListResouce);

$companyVisited = null;

?>

<!DOCTYPE html>
<html>
<head>
    <title>Companies</title>
</head>
<body> 
<h1>Company Listing</h1>
<ul>
<?php
    if(isset($_COOKIE["companyVisited"]))
    {
        $visited = explode("_", $_COOKIE["companyVisited"]);
    }
    foreach($companies as $key => $value)
    {
        if(isset($_COOKIE["companyVisited"]))
        {
          if(in_array($key, $visited))
          {
              echo "<li><a href='details.php?company=" . urlencode($key) . "'>" . $value[0] . "</a>" . "___Visited" . "</li>";
          }
          else
          {
            echo "<li><a href='details.php?company=" . urlencode($key) . "'>" . $value[0] . "</a></li>";
          }
        }
        else
        {
            echo "<li><a href='details.php?company=" . urlencode($key) . "'>" . $value[0] . "</a></li>";
        }
    }
?>
</ul>

    </body>
</html>