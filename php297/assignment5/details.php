<?php
if(isset($_GET["company"]))
{
    if(isset($_COOKIE["companyVisited"]))
    {
        $visited = explode("_", $_COOKIE["companyVisited"]);
        if(!in_array($_GET["company"], $visited))
        {
            header("Set-Cookie: companyVisited=" . $_COOKIE["companyVisited"] . "_" . $_GET["company"]);
        }
    }
    else
    {
        header("Set-Cookie: companyVisited=" . $_GET["company"]);
    }
}
$callListResouce = fopen("callList.csv", "r");
$companies = array();

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
?>
<!DOCTYPE html>
<html>
<head>
    <title>Companies</title>
</head>
<body> 
<h1>Company Details</h1>
<?php

    if(isset($_GET["company"]))
    {
        if(isset($companies[$_GET["company"]]))
        {
            //render the company info
            echo "<h2>" . $companies[$_GET["company"]][0] . "</h2>";
            echo "<p>Company Phone: " . $companies[$_GET["company"]][1] . "</p>";
        }
        else
        {
            //Default text
             echo "The company was not found.";
        }
    }
    else
    {
        //Default text
        echo "The company was not found.";
    }

?>

<a href="/">Back to list</a>

    </body>
</html>