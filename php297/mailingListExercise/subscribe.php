<?php 
require("header.php");
?>
<!--form for user to input email-->
<form action="subscribed.php" method="POST">
<label>Your Email: <input type="email" name="userEmail"></label>
<input type="submit">
</form>
<?php
require("footer.php");
?>
