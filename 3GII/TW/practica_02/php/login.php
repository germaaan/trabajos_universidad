<?php
			
	ini_set('display_errors', true);
	error_reporting(E_ALL);
				
	require_once "Usuario.class.inc";

	if ((isset($_POST['usuario'])) and (isset($_POST['pass']))){
		$usuario = $_POST['usuario'];
		$pass = $_POST['pass'];

		Usuario::accesoLogueo($usuario, $pass);
	}
	
	header('Location: ../index.php');
	
?>