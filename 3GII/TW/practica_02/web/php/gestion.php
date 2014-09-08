<?php
	session_start();  
  
	ini_set('display_errors', true);
	error_reporting(E_ALL);
						
	require_once "NoticiaUltimaHora.class.inc";
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="../css/formulario.css">
    <title>PlaceHolder - Gesti&oacuten de noticias de &uacuteltima hora</title>
    <meta name="description" content="Formulario de suscripción a PlaceHolder">
    <meta name="author" content="German Martinez Maldonado">
</head>

<body>
    
<aside id="publi_sup">
    <a href="http://www.pnsd.msc.es/">
        <img class="img_publicidad_superior" src="../publicidad/publicidad_antidrogas.jpg" alt="publicidad_antidrogas"/>
    </a>
</aside>

<aside id="publi_izq">
    <a href="http://www.samsung.com/es/#home-appliances-home">
        <img class="img_publicidad_lateral" src="../publicidad/publicidad_samsung.jpg" alt="publicidad_samsung"/>
    </a>
</aside>

<aside id="publi_der">
    <a href="http://www.donuts.es/">
        <img class="img_publicidad_lateral" src="../publicidad/publicidad_donuts.jpg" alt="publicidad_donuts"/>
    </a>
</aside>

<section id="cuerpo">
    <header>
        <a href="../index.php">
            <img id="img_cabecera" src="../index/cabecera.jpg" alt="cabecera"/>
        </a>
    </header>
    
    <nav>
        <a href="../nacional.html">
            <img src="../index/nacional.jpg" alt="nacional"/>
        </a>
        
        <a href="../internacional.html">
            <img src="../index/internacional.jpg" alt="internacional"/>
        </a>
        
        <a href="../economia.html">
            <img src="../index/economia.jpg" alt="economia"/>
        </a>
        
        <a href="../deportes.html">
            <img src="../index/deportes.jpg" alt="deportes"/>
        </a>
    </nav>
	
	<section id="formulario">
		<?php
		
			if (isset($_SESSION['usuario'])){
				$admin = $_SESSION['usuario'];
					
				if ($admin == 'admin'){
		
					if (isset($_POST["accion"])){
						if ($_POST["accion"] == "aniadir"){
							echo "<p><h1> P&AacuteGINA DE ADICI&OacuteN DE NOTICIAS DE &UacuteLTIMA HORA </h1></p>";
							echo "<form action='insertaNoticia.php' method=post accept-charset='UTF-8'>";
								echo "<label for='textoInsertar'> <h3> Introduzca el titular de la noticia: </h3> </label><br>";				
								echo "<textarea id='textoInsertar' name='textoInsertar' cols='40' rows='6' maxlength='255'></textarea>";
								echo "<br><br>";
								echo "<input type='submit' id='insertarNoticia' value='Introducir noticia'/>";
							echo "</form>";
						} else if ($_POST["accion"] == "actualizar"){
							echo "<p><h1> P&AacuteGINA DE ACTUALIZACI&OacuteN DE NOTICIAS DE &UacuteLTIMA HORA </h1></p>";
							NoticiaUltimaHora::mostrarNoticiasAvanzado(NoticiaUltimaHora::getNoticiasUltimaHora());
							echo "<form action='actualizaNoticia.php' method=post accept-charset='UTF-8'>";
								echo "<label for='idActualizar'> <h3> Introduzca el id de la noticia a modificar: </h3> </label><br>";				
								echo "<input type='text' id='idActualizar' name='idActualizar' maxlength='11'/>";
								echo "<label for='textoActualizar'> <h3> Introduzca el titular de la noticia: </h3> </label><br>";				
								echo "<textarea id='textoActualizar' name='textoActualizar' cols='40' rows='6' maxlength='255'></textarea>";
								echo "<br><br>";
								echo "<input type='submit' id='actualizarNoticia' value='Actualizar noticia'/>";
							echo "</form>";
						} else if ($_POST["accion"] == "borrar"){
							echo "<p><h1> P&AacuteGINA DE BORRADO DE NOTICIAS DE &UacuteLTIMA HORA </h1></p>";
							NoticiaUltimaHora::mostrarNoticiasAvanzado(NoticiaUltimaHora::getNoticiasUltimaHora());
							echo "<form action='eliminaNoticia.php' method=post accept-charset='UTF-8'>";
								echo "<label for='idEliminar'> <h3> Introduzca el id de la noticia a borrar: </h3> </label><br>";				
								echo "<input type='text' id='idEliminar' name='idEliminar' maxlength='11'/>";
								echo "<br><br>";
								echo "<input type='submit' id='eliminarNoticia' value='Borrar noticia'/>";
							echo "</form>";
						}
					}
				} else{
					echo "<p><h1> ACCESO RESTRINGIDO </h1></p>";
				}
			} else{
				echo "<p><h1> ES NECESARIO TENER UNA SESI&ÓacuteN ABIERTA </h1></p>";
			}
			
			echo "<br><br><a href='../index.php'> <h3>Volver<h3> </a>";
		
		?>
		
	</section>
	
 <footer>
	 <h2> INFORMACI&OacuteN DE CONTACTO </h2>
	 <p> <address> C/ Periodista Daniel Saucedo Aranda, s/n, 18071, Granada </address> </br>
		 <strong> Tel&eacutefono: </strong> 958 24 28 02 </br>
		 <strong> Correo electr&oacutenico: </strong> <a href="mailto:contacto@placeholder.com"> contacto@placeholder.com </a> </br></br>
		 <strong> <a href="../descripcion.pdf"> C&oacutemo se hizo. </strong> </a>
	 </p>
 </footer>

</section>

</body>
</html>
