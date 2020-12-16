<?php
$servername = "deltona.birdnest.org";
$username = "my.millerm30";
$password = "rune1";

// Create connection
$conn = new mysqli($servername, $username, $password);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error . "\n");
}
echo "Connected successfully... ";

$db = "my_millerm30_proj";
$sql = "USE " . $db . ";";

if ($conn->query($sql) === TRUE) {
  echo "Using database: " . $db;
} 
else 
{
  echo "Error: " . $conn->error;
}
?>