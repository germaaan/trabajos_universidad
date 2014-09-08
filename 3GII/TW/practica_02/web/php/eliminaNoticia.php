<?php
	session_start();  
  
	ini_set('display_errors', true);
	error_reporting(E_ALL);
						
	require_once "NoticiaUltimaHora.class.inc";
	
	if (isset($_SESSION['usuario'])){
		$admin = $_SESSION['usuario'];
					
		if ($admin == 'admin'){
			if (isset($_POST["idEliminar"])){
				$id=$_POST["idEliminar"];
				NoticiaUltimaHora::eliminarNoticia($id);
			}
		}
	}
	
	header('Location: ../index.php');
			
?>