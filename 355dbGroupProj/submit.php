<?php require("connDB.php")?><br><br>
<?php

//if user landed on page without submitting form, send them to errorPage
if(!isset($_POST))
{
    header("Location: errorPage.php");
    exit;
}

$salt = '1234567890123456789012';

$User_account = array('email' => '', 'firstName' => '', 'lastName' => '', 'phone' => '', 'streetAddress' => '', 'city' => '', 'state' => '', 'zip' => '', 'salt' => $salt, 'hash' => '');
$Subscription_type = array('name', 'screens', 'price', 'description');
$Payment_method = array('creditCardNumber', 'cvv', 'expirationDate', 'acctID');
$Invoice = array('invoiceID', 'serviceStart', 'acctID', 'subID', 'paymentID', 'purchaseAmount');

if(isset($_GET))
{
    $code = array_keys($_GET);
    $dbName = 'User_account';
    //1
    if($_GET[$code[0]] == 1)
    {
        if($code[0] == "create")
        {
            if(isset($_POST))
            {

                if($_POST['email'] == "")
                {
                    header("Location: errorPage.php");              //if user didn't enter email, send them to errorPage
                    exit;
                }
                else
                {
                    $stmt = $conn->prepare("INSERT INTO $dbName (email, firstName, lastName, phone, streetAddress, city, state, zip, salt, hash) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

                    $stmt->bind_param("ssssssssss", $email, $firstName, $lastName, $phone, $streetAddress, $city, $state, $zip, $saltP, $hash);

                    //$stmt = $conn->prepare("INSERT INTO User_account (email, firstName, lastName, phone, streetAddress, city, state, zip, salt, hash) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
                    //$stmt->bind_param("ssssssssss", $email, $firstName, $lastName, $phone, $streetAddress, $city, $state, $zip, $saltP, $hash);

                        foreach($User_account as $key => $value)
                        {
                            if(isset($_POST[$key]))
                            {
                                $User_account[$key] = $_POST[$key];        //retrieve data from post and store in array
                            }
                        }

                        if(isset($_POST['password']))
                        {
                            $password = $_POST['password'];
                            $hash = substr(password_hash($password, PASSWORD_BCRYPT, ['salt' => $salt]), strlen($salt) + 6);
                            $saltP = $salt;
                            $User_account['hash'] = $hash;
                        }
                        $email = $_POST['email'];
                        if(isset($_POST['firstName']))
                        {
                            $firstName = $_POST['firstName'];
                        }
                        if(isset($_POST['lastName']))
                        {
                            $lastName = $_POST['lastName'];
                        }
                        if(isset($_POST['phone']))
                        {
                            $phone = $_POST['phone'];
                        }
                        if(isset($_POST['streetAddress']))
                        {
                            $streetAddress = $_POST['streetAddress'];
                        }
                        if(isset($_POST['city']))
                        {
                            $city = $_POST['city'];
                        }
                        if(isset($_POST['state']))
                        {
                            $state = $_POST['state'];
                        }
                        if(isset($_POST['zip']))
                        {
                            $zip = $_POST['zip'];
                        }
                    $stmt->execute();

                    if($conn->affected_rows != -1)
                    {
                        header("Location: success.php");
                        exit;
                    }
                    else
                    {
                        header("Location: errorPage.php");
                        exit;
                    }
                }   

            }
        }
        else if($code[0] == "read")
        {
            readDB($dbName, $conn);
        }
        else if($code[0] == "update")
        {
            $stmt = $conn->prepare("UPDATE $dbName SET email=? WHERE id=?");
            $stmt->bind_param("si", $email, $Pid);
            if(isset($_POST['id']))
            {
                $Pid = $_POST['id'];
            }
            $email = $_POST['email'];
            $stmt->execute();
            $result = $stmt->affected_rows;
            if($result == 0)                            
            {
                header("location: errorPage.php");
                exit;
            }
            else if($result > 0)
            {
                header("location: success.php");
            }
        }
        else if($code[0] == "delete")
        {
            deleteDB($dbName, $conn);
        }

    }
    //2
    else if($_GET[$code[0]] == 2)
    {
        $dbName = 'Subscription_type';
        if($code[0] == "create")
        {
            if($_POST['name'] == "")
            {
                header("location: errorPage.php");          //if user submits form without name, direct to errorPage
                exit;
            }
            $stmt = $conn->prepare("INSERT INTO $dbName (name, screens, price, description) VALUES (?, ?, ?, ?)");
            $stmt->bind_param("siss", $name, $screens, $price, $description);
            $name = $_POST['name'];
            if(isset($_POST['screens']))
            {
                $screens = $_POST['screens'];
            }
            if(isset($_POST['price']))
            {
                $price = $_POST['price'];
            }
            if(isset($_POST['description']))
            {
                $description = $_POST['description'];
            }
            $stmt->execute();

            if($conn->affected_rows != -1)
            {
                header("Location: success.php");
                exit;
            }
            else
            {
                header("Location: errorPage.php");
                exit;
            }

        }
        else if($code[0] == "read")
        {
            readDB($dbName, $conn);
        }
        else if($code[0] == "update")
        {
            $stmt = $conn->prepare("UPDATE $dbName SET price=? WHERE id=?");
            $stmt->bind_param("ii", $price, $Pid);
            if(isset($_POST['id']))
            {
                $Pid = $_POST['id'];
            }
            if(isset($_POST['price']))
            {
                $price = $_POST['price'];
            }
            $stmt->execute();
            $result = $stmt->affected_rows;
            if($result == 0)                            
            {
                header("location: errorPage.php");
                exit;
            }
            else if($result > 0)
            {
                header("location: success.php");
            }
        }
        else if($code[0] == "delete")
        {
            deleteDB($dbName, $conn);
        }
    }
     //3
    else if($_GET[$code[0]] == 3)
    {
        $dbName = 'Payment_method';
        if($code[0] == "create")
        {
            
            if($_POST['acctID'] == "")
           {  
               header("location: errorPage.php");          //if user submits form without acctID, direct to errorPage
               exit;
           }
           $stmt = $conn->prepare("INSERT INTO $dbName (creditCardNumber, cvv, expirationDate, acctID) VALUES (?, ?, ?, ?)");
           $stmt->bind_param("sssi", $creditCardNumber, $cvv, $expirationDate, $acctID);
           $acctID = $_POST['acctID'];
           if(isset($_POST['cvv']))
           {
               $cvv = $_POST['cvv'];
           }
           if(isset($_POST['expirationDate']))
           {
               $expirationDate = $_POST['expirationDate'];
           }
           if(isset($_POST['creditCardNumber']))
           {
               $creditCardNumber = $_POST['creditCardNumber'];
           }
           $stmt->execute();
           echo ($conn->affected_rows);
           if($conn->affected_rows != -1)
           {
              header("Location: success.php");
               exit;
           }
           else
           {
               header("Location: errorPage.php");
               exit;
           }

        }
        else if($code[0] == "read")
        {
            readDb($dbName, $conn);
        }
        else if($code[0] == "update")
        {
            $stmt = $conn->prepare("UPDATE $dbName SET acctID=? WHERE id=?");
            $stmt->bind_param("ii", $acctID, $Pid);
            if(isset($_POST['acctID']))
            {
                $acctID = $_POST['acctID'];
            }
            if(isset($_POST['id']))
            {
                $Pid = $_POST['id'];
            }
            $stmt->execute();
            $result = $stmt->affected_rows;
            if($result == 0)                            
            {
                header("location: errorPage.php");
                exit;
            }
            else if($result > 0)
            {
                header("location: success.php");
            };
        }
        else if($code[0] == "delete")
        {
            deleteDb($dbName, $conn);
        }
    }        //4
    else if($_GET[$code[0]] == 4)
    {
        $dbName = 'Invoice';
        if($code[0] == "create")
        {
            
            if($_POST['invoiceID'] == "" || $_POST['acctID'] == "" || $_POST['subID'] == "" || $_POST['paymentID'] =="")
           {
               header("location: errorPage.php");          //if user submits form without invoiceID, acctID, subID, or paymentID, direct to errorPage
               exit;
           }
           $stmt = $conn->prepare("INSERT INTO $dbName (invoiceID, serviceStart, acctID, subID, paymentID, purchaseAmount) VALUES (?, ?, ?, ?, ?, ?)");
           $stmt->bind_param("ssiiis", $invoiceID, $serviceStart, $acctID, $subID, $paymentID, $purchaseAmount);
           $invoiceID = $_POST['invoiceID'];
           $acctID = $_POST['acctID'];
           $subID = $_POST['subID'];
           $paymentID = $_POST['paymentID'];

           if(isset($_POST['serviceStart']))
           {
               $serviceStart = $_POST['serviceStart'];
           }
           if(isset($_POST['purchaseAmount']))
           {
               $purchaseAmount = $_POST['purchaseAmount'];
           }
           $stmt->execute();
           echo $conn->affected_rows;
           if($conn->affected_rows != -1)
           {
               //header("Location: success.php");
               exit;
           }
           else
           {
               //header("Location: errorPage.php");
               exit;
           }
        }
        else if($code[0] == "read")
        {
            readDB($dbName, $conn);
        }
        else if($code[0] == "update")
        {
            $stmt = $conn->prepare("UPDATE $dbName SET invoiceID=? WHERE id=?");
            $stmt->bind_param("si", $invoiceID, $Pid);
            $invoiceID = $_POST['invoiceID'];
            if(isset($_POST['id']))
            {
                $Pid = $_POST['id'];
            }
            $stmt->execute();
            $result = $stmt->affected_rows;
            if($result == 0)                            
            {
                header("location: errorPage.php");
                exit;
            }
            else if($result > 0)
            {
                header("location: success.php");
            };
        }
        else if($code[0] == "delete")
        {
            deleteDB($dbName, $conn);
        }
    }
}
else
{
    header("location: errorPage.php");
    exit;
}

function readDB($dbName, $conn)
{
    if(isset($_POST))
    {
        $stmt = $conn->prepare("SELECT * FROM $dbName WHERE id=?");
        $stmt->bind_param("i", $Pid);
        if(isset($_POST['id']))
        {
            $Pid = $_POST['id'];
        }
        $stmt->execute();
        $result = $stmt->get_result();
        if($result->num_rows == 0)
        {
            header("location: errorPage.php");
            exit;
        }
        else
        {
            header("location: success.php");
            exit;
        }
    }
}


function deleteDB($dbName, $conn)
{
    $stmt = $conn->prepare("DELETE FROM $dbName WHERE id=?");
    $stmt->bind_param("i", $Pid);
    if(isset($_POST['id']))
    {
        $Pid = $_POST['id'];
    }
    $stmt->execute();
    $result = $stmt->affected_rows;
    if($result == 0)                            
    {
        header("location: errorPage.php");
        exit;
    }
    else if($result > 0)
    {
        header("location: success.php");
    }
}


?>