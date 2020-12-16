<?php require("connDB.php")?><br><br>
<?php



//User_account
$table = "User_account";

$show = "SELECT * FROM User_account;";

echo "Current " . $table . " table: <br><br>";

?>
<form action="submit.php?create=1" method="POST">
To execute a create statement on this table, fill in the values and select create (email is a required field for proper execution):<br>
Email: <input type="email" name="email"> First Name: <input type="text" name="firstName"> Last Name: <input type="text" name="lastName"><br>
Phone: <input type="text" name="phone"> Address: <input type="text" name="streetAddress">
City: <input type="text" name="city"><br>State: <input type="text" name="state"> Zip: <input type="text" name="zip"> Password: <input type="text" name="password"> <button>Create</button><br><br>
</form>
<form action="submit.php?read=1" method="POST">
To execute a read statement on this table, fill in the id you would like to view:
Id: <input type="number" name="id"> <button>Read</button><br><br>
</form>
<form action="submit.php?update=1" method="POST">
To execute an update on this table, fill in the email you would like to set and the id you would like to apply it to:
Email: <input type="email" name="email"> Id: <input type="number" name="id"> <button>Update</button><br><br>
</form>
<form action="submit.php?delete=1" method="POST">
To execute a delete on this table, fill in the id for the entry you want to delete:
Id: <input type="number" name="id"> <button>Delete</button>
</form>

<?php

?>