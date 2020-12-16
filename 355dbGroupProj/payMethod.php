<?php require("connDB.php")?><br><br>
<?php

//Payment_method
$table = "Payment_method";

$show = "SELECT * FROM Payment_method;";

echo "Current " . $table . " table: <br>";
?>
<form action="submit.php?create=3" method="POST">
To execute a create statement on this table, fill in the values and select create (acctID is a required field for proper execution):<br>
CC Num: <input type="text" name="creditCardNumber"> CVV: <input type="text" name="cvv"> Expiry Date: <input type="text" name="expirationDate"><br>
acctID: <input type="number" name="acctID" min="1000000000" max="9999999999"> <button>Create</button><br><br>
</form>
<form action="submit.php?read=3" method="POST">
To execute a read statement on this table, fill in the id you would like to view:
Id: <input type="number" name="id"> <button>Read</button><br><br>
</form>
<form action="submit.php?update=3" method="POST">
To execute an update on this table, fill in the acctID you would like to set and the id you would like to apply it to:
AcctID: <input type="number" name="acctID" min="1000000000" max="9999999999"> Id: <input type="number"> <button>Update</button><br><br>
</form>
<form action="submit.php?delete=3" method="POST">
To execute a delete on this table, fill in the id for the entry you want to delete:
Id: <input type="number" name="id"> <button>Delete</button>
</form>