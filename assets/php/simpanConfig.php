<?php

include 'koneksi.php';

$batas = $_POST['batas'];
$sql = "UPDATE config SET batas='$batas'";
if (mysqli_query($conn, $sql)){
	
}

?>