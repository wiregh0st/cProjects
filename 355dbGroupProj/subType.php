<?php require("connDB.php")?><br><br>
<?php

//Subscription_type
$table = "Subscription_type";

$show = "SELECT * FROM Subscription_Type;";

echo "Current " . $table . " table: <br>";

?>

<form action="submit.php?create=2" method="POST">
To execute a create statement on this table, fill in the values and select create (name is a required field for proper execution):<br>
Name: <input type="text" name="name"> Screens: <input type="number" name="screens"><br>
Price: <input type="number" name="price"> Description: <input type="text" name="description"> <button>Create</button><br><br>
</form>
<form action="submit.php?read=2" method="POST">
To execute a read statement on this table, fill in the id you would like to view:
Id: <input type="number" name="id"> <button>Read</button><br><br>
</form>
<form action="submit.php?update=2" method="POST">
To execute an update on this table, fill in the price you would like to set and the id you would like to apply it to:
Price: <input type="number" name="price"> Id: <input type="number" name="id"> <button>Update</button><br><br>
</form>
<form action="submit.php?delete=2" method="POST">
To execute a delete on this table, fill in the id for the entry you want to delete:
Id: <input type="number" name="id"> <button>Delete</button>
</form>