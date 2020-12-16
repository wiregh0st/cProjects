<?php
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
<h1>Company Listing</h1>
<ul>
<?php
    if(isset($_POST['compName']) && isset($_POST['phone']) && $_POST['compName'] != "" && $_POST['phone'] != ""){
        $compName = $_POST['compName'];
        $phone = $_POST['phone'];
        foreach ($companies as $a)
        {
            $compNameArray[] = $a[0];
            $phoneArray[] = $a[1];
        }
        if(in_array($compName, $compNameArray) || in_array($phone, $phoneArray)){
            echo "Company already in records. Please try again.";
        }
        else
        {
            $callListResource = fopen("callList.csv", "a");
            $compInsert = "\n".$compName.",".$phone;
            fwrite($callListResource, $compInsert);
            fclose($callListResource);
        }
    }
    foreach($companies as $key => $value)
    {
        echo "<li><a href='details.php?company=" . urlencode($key) . "'>" . $value[0] . "</a></li>";
    }
?>
</ul>
    </body>
    <a href="addCompany.php">Add a Company</a>
</html>