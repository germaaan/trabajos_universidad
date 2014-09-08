<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="../css/formulario.css">
    <title>PlaceHolder - Formulario de alta/suscripción</title>
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
		<p><h1> FORMULARIO DE ALTA EN WEB / SUBSCRIPCIÓN A VERSIÓN IMPRESA </h1></p>
		
		<?php			
			
			ini_set('display_errors', true);
			error_reporting(E_ALL);
			
			require_once "Usuario.class.inc";
			
			if ((isset($_POST["campoUsuario"])) and (isset($_POST["campoPass"])) and (isset($_POST["campoNombre"])) 
				and (isset($_POST["campoApellidos"])) and (isset($_POST["campoCorreo"])) and (isset($_POST["campoDireccion"])) 
				and (isset($_POST["campoCodPostal"])) and (isset($_POST["campoCiudad"])) and (isset($_POST["campoTelefono"])) 
				and (isset($_POST["campoEdad"]))){
				
				$usuario = $_POST["campoUsuario"];
				$pass = $_POST["campoPass"];
				$nombre = $_POST["campoNombre"];
				$apellidos = $_POST["campoApellidos"];
				$correo = $_POST["campoCorreo"];
				$direccion = $_POST["campoDireccion"];
				$cod_postal = $_POST["campoCodPostal"];
				$ciudad = $_POST["campoCiudad"];
				$telefono = $_POST["campoTelefono"];
				$edad = $_POST["campoEdad"];
				
				if (isset($_POST["campoComoConoci"])){
					$como_conoci = $_POST["campoComoConoci"];
				} else {
					$como_conoci = "";
				}
				
				if(Usuario::existeUsuario($usuario,$correo)){
					echo "<p><h2> Alta/suscripción no realizada: </h2><p>";
					echo "<p><h3> Ya existe un usuario con el nombre de usuario \"$usuario\" o la dirección de correo electrónico \"$correo\". </h3></p>";
				}
				else {
					Usuario::insertarUsuario($usuario,$pass,$nombre,$apellidos,$correo,$direccion,$cod_postal,$ciudad,$telefono,$edad,$como_conoci);
					echo "<p><h2> Alta/suscripción realizada correctamente con los siguientes datos: </h2><p>";
					echo "<h3>Usuario: $usuario</h3>";
					echo "<h3>Nombre: $nombre</h3>";
					echo "<h3>Apellidos: $apellidos</h3>";
					echo "<h3>Correo electrónico: $correo</h3>";
					echo "<h3>Dirección: $direccion</h3>";
					echo "<h3>Código Postar: $cod_postal</h3>";
					echo "<h3>Ciudad: $ciudad</h3>";
					echo "<h3>Teléfono: $telefono</h3>";
					echo "<h3>Edad: $edad</h3>";
					echo "<h3>¿Cómo nos conoció?: $como_conoci</h3>";
				}
			}
			else {
				echo "<p><h2> Error al recibir los datos del formulario. Por favor, retroceda y vuelva a rellenarlo. </h2><p>";
			}

		?>
		
		<p><h3> ¡Gracias por su interes! Atentamente, el departamente de Atención al cliente de PlaceHolder </h3></p>
	</section>
	
 <footer>
	 <h2> INFORMACIÓN DE CONTACTO </h2>
	 <p> <address> C/ Periodista Daniel Saucedo Aranda, s/n, 18071, Granada </address> </br>
		 <strong> Teléfono: </strong> 958 24 28 02 </br>
		 <strong> Correo electrónico: </strong> <a href="mailto:contacto@placeholder.com"> contacto@placeholder.com </a> </br></br>
		 <strong> <a href="../descripcion.pdf"> Cómo se hizo. </strong> </a>
	 </p>
 </footer>

</section>

</body>
</html>
