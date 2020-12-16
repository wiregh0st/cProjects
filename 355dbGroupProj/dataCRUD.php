<?php require 'connDB.php'; ?>
<form action="userAccount.php">
<br>Click this button to interact with the User_account table:<button>User_account</button>
</form>

<form action="subType.php">
Click this button to interact with the Subscription_type table:<button>Subscription_type</button>
</form>

<form action="payMethod.php">
Click this button to interact with the Payment_method table:<button>Payment_method</button>
</form>

<form action="invoice.php">
Click this button to interact with the Invoice table:<button>Invoice</button>
</form>

<?php

// $stmt = $conn->prepare("INSERT INTO MyGuests (firstname, lastname, email) VALUES (?, ?, ?)");
// $stmt->bind_param("sss", $firstname, $lastname, $email); //s = string

// // set parameters and execute
// $firstname = "John";
// $lastname = "Doe";
// $email = "john@example.com";
//$stmt->execute();

//$stmt->close();

?>