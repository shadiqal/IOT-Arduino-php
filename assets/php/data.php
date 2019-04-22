<?php

include 'koneksi.php';


$output = '';

$search = "SELECT * FROM data ORDER BY id DESC LIMIT 1";
$sql = mysqli_query($conn, $search);
$row = mysqli_fetch_array($sql);
$berat = $row['data'];
$id = $row['id'];
$waktu = $row['waktu'];



$sql2 = "SELECT * FROM config";
$query = mysqli_query($conn, $sql2);
$data = mysqli_fetch_array($query);
$batas = $data['batas']; 

$output .= $berat.'|'.$waktu.'|'.$id.'|'.$batas;

echo $output;
mysqli_close($conn);
?>