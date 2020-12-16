<?php require("connDB.php")?><br><br>
<?php

//Invoice
$table = "Invoice";

$show = "SELECT * FROM Invoice;";

echo "Current " . $table . " table: <br>";
?>

<form action="submit.php?create=4" method="POST">
To execute a create statement on this table, fill in the values and select create (Invoice ID, Acct ID, Sub ID, and Payment ID are required fields for proper execution):<br>
Invoice ID: <input type="text" name="invoiceID"> Service Start: <input type="date" name="serviceStart"> Acct ID: <input type="number" name="acctID" min="1000000000" max="9999999999"><br>
Sub ID: <input type="text" name="subID"> Payment ID: <input type="text" name="paymentID"> Purchase Amount: <input type="number" name="purchaseAmount"> <button>Create</button><br><br>
</form>
<form action="submit.php?read=4" method="POST">
To execute a read statement on this table, fill in the id you would like to view:
Id: <input type="number" name="id"> <button>Read</button><br><br>
</form>
<form action="submit.php?update=4" method="POST">
To execute an update on this table, fill in the acctID you would like to set and the id you would like to apply it to:
Invoice ID: <input type="text" name="invoiceID"> Id: <input type="number" name="id"> <button>Update</button><br><br>
</form>
<form action="submit.php?delete=4" method="POST">
To execute a delete on this table, fill in the id for the entry you want to delete:
Id: <input type="number" name="id"> <button>Delete</button>
</form>