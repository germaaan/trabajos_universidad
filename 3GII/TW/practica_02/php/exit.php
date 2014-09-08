<?php
	
	session_start();
	
	ini_set('display_errors', true);
	error_reporting(E_ALL);
				
	unset($_SESSION['usuario']); 
	session_destroy();
	
	header("Location: ../index.php");
?>