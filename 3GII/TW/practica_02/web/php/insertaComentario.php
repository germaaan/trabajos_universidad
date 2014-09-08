<?php
  
	ini_set('display_errors', true);
	error_reporting(E_ALL);
						
	require_once "Comentario.class.inc";
	
	if ((isset($_POST["nombreNoticia"])) and (isset($_POST["comentarioUsuario"])) and 
		(isset($_POST["textoComentario"])) and (isset($_POST["rutaNoticia"]))){
		
		$noticia=$_POST["nombreNoticia"];
		$usuario=$_POST["comentarioUsuario"];
		$texto=$_POST["textoComentario"];
		$ruta=$_POST["rutaNoticia"];
		
		Comentario::insertarComentario($noticia, $usuario, $texto);
	}
		
	header('Location: '.$ruta);
			
?>