    <?php
    include ('koneksi.php');
    
    // session_start();
    // printf("GET variables\n");
    // print_r($_GET);
    // session_destroy();

    // if (isset($_GET['berat'])){
    // $berat=$_GET['berat'];
    // }
    // else{
    // echo "Data not received";
    // }

    $sql= "INSERT INTO data (data) VALUES ('".$_GET['berat']."')";
    
    if(mysqli_query($conn,$sql))
    {
    echo "Ok!";
    mysqli_close($conn);
    }
    else
    {
    echo "error is ".mysqli_error($conn);
    }
    ?>