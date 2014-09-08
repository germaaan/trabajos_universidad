<?php
	session_start();  
  
	ini_set('display_errors', true);
	error_reporting(E_ALL);
						
	require_once "NoticiaUltimaHora.class.inc";
	
	if (isset($_SESSION['usuario'])){
		$admin = $_SESSION['usuario'];
					
		if ($admin == 'admin'){
			if (isset($_POST["textoInsertar"])){
				$texto=$_POST["textoInsertar"];
				NoticiaUltimaHora::insertarNoticia($texto);
			}
		}
	}	
		
	header('Location: ../index.php');
			
?>