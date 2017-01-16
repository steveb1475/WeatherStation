<?php

  $tempf = $_GET['tempf'];
  $press = $_GET['press'];
  $humid = $_GET['humid'];
  $windv = $_GET['windv'];
  $windd = $_GET['windd'];

  $servername = "localhost";
  $username = "YourDbUser";
  $password = "YourDbUserPassword";
  $dbname = "YourDb";

  // Create connection
  $conn = new mysqli($servername, $username, $password, $dbname);
  // Check connection
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }

  $sql = "INSERT INTO data ( temperature , pressure  , humidity , windvelocity , winddirection) VALUES ( $tempf , $press , $humid , $windv , $windd)";

  if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
  } else {
    echo "no data error: " . $sql . "<br>" . $conn->error;
  }

  $conn->close();
?>
