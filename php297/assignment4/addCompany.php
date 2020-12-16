<!DOCTYPE HTML>
<html>
<head>
    <title>Generate Company</title>
</head>
<body>
    <?php
    ?>
       <form action="index.php" method="POST">
        <label>Company Name: <input type="text" name="compName"></input></label><br>
        <label>Company Phone: <input type="text" name="phone" pattern="[0-9]{1}-[0-9]{3}-[0-9]{3}-[0-9]{4}"></label>
        <input type="Submit">
    </form>
</body>
<html>