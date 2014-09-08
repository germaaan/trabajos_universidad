<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="./css/formulario.css">
    <title>PlaceHolder - Formulario de suscripción</title>
    <meta name="description" content="Formulario de suscripción a PlaceHolder">
    <meta name="author" content="German Martinez Maldonado">
</head>

<body>
    
<aside id="publi_sup">
    <a href="http://www.pnsd.msc.es/">
        <img class="img_publicidad_superior" src="./publicidad/publicidad_antidrogas.jpg" alt="publicidad_antidrogas"/>
    </a>
</aside>

<aside id="publi_izq">
    <a href="http://www.samsung.com/es/#home-appliances-home">
        <img class="img_publicidad_lateral" src="./publicidad/publicidad_samsung.jpg" alt="publicidad_samsung"/>
    </a>
</aside>

<aside id="publi_der">
    <a href="http://www.donuts.es/">
        <img class="img_publicidad_lateral" src="./publicidad/publicidad_donuts.jpg" alt="publicidad_donuts"/>
    </a>
</aside>

<section id="cuerpo">
    <header>
        <a href="index.html">
            <img id="img_cabecera" src="./index/cabecera.jpg" alt="cabecera"/>
        </a>
    </header>
    
    <nav>
        <a href="./nacional.html">
            <img src="./index/nacional.jpg" alt="nacional"/>
        </a>
        
        <a href="./internacional.html">
            <img src="./index/internacional.jpg" alt="internacional"/>
        </a>
        
        <a href="./economia.html">
            <img src="./index/economia.jpg" alt="economia"/>
        </a>
        
        <a href="./deportes.html">
            <img src="./index/deportes.jpg" alt="deportes"/>
        </a>
    </nav>
	
	<section id="formulario">
		<p><h1> FORMULARIO DE SUBSCRIPCIÓN A VERSIÓN IMPRESA </h1></p>
		
		<p><h2> Suscripción realizada correctamente con los siguientes datos: </h2><p>
		
		<?php			
			$campo1 = $_POST["campoNombre"];
			echo "<strong>Nombre</strong>: $campo1<br/><br/>";

			$campo2 = $_POST["campoApellidos"];
			echo "<strong>Apellidos</strong>: $campo2<br/><br/>";
			
			$campo3 = $_POST["campoCorreo"];
			echo "<strong>Correo electrónico</strong>: $campo3<br/><br/>";

			$campo4 = $_POST["campoDireccion"];
			echo "<strong>Dirección</strong>: $campo4<br/><br/>";

			$campo5 = $_POST["campoCP"];
			echo "<strong>Código Postar</strong>: $campo5<br/><br/>";

			$campo6 = $_POST["campoCiudad"];
			echo "<strong>Ciudad</strong>: $campo6<br/><br/>";

			$campo7 = $_POST["campoTelefono"];
			echo "<strong>Teléfono</strong>: $campo7<br/><br/>";

			$campo8 = $_POST["campoFecha"];
			echo "<strong>Fecha de nacimiento</strong>: $campo8<br/><br/>";

			$campo9 = $_POST["campoConocimiento"];
			echo "<strong>¿Cómo nos conoció?</strong>: $campo9<br/><br/>";
		?>
		
		<p><h3> ¡Gracias por su interes! Atentamente, el departamente de Atención al cliente de PlaceHolder </h3></p>
	</section>
	
 <footer>
	 <h2> INFORMACIÓN DE CONTACTO </h2>
	 <p> <address> C/ Periodista Daniel Saucedo Aranda, s/n, 18071, Granada </address> </br>
		 <strong> Teléfono: </strong> 958 24 28 02 </br>
		 <strong> Correo electrónico: </strong> <a href="mailto:contacto@placeholder.com"> contacto@placeholder.com </a> </br></br>
		 <strong> <a href="./descripcion.pdf"> Cómo se hizo. </strong> </a>
	 </p>
 </footer>

</section>

</body>
</html>
