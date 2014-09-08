<?php	
	session_start();  
  
	ini_set('display_errors', true);
	error_reporting(E_ALL);
						
	require_once "../php/Comentario.class.inc";
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="../css/noticias.css">
    <title>PlaceHolder - NACIONAL. Rajoy explicará las nuevas medidas del Gobierno en el Congreso el 8 de mayo</title>
    <meta name="description" content="Noticia nacional del portal PlaceHolder">
    <meta name="author" content="German Martinez Maldonado">
	<script type="text/javascript" src="../js/scriptNoticias.js"></script>
	<noscript>
		Este navegador no es compatible con los scripts que se necesitan ejecutar para el correcto funcionamiento de la páginas, por favor actualice la versión de su navegador a una más reciente que sea compatible
		<br><br>
	</noscript>
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
    
	<section id="cabecera_secciones">
		<img id="img_cabecera_secciones" src="../index/nacional.jpg" alt="nacional"/>
	</section>
   
	<section id="noticia_destacada">
		<article class="nacional">
			<figure id="figura_noticia_destacada">
				<img class="img_noticia_destacada" src="./rajoy_explicara_nuevas_medidas_20130430/imagen_01.jpg"  
					 alt="rajoy_explicara_nuevas_medidas_20130430"/>
				<figcaption> Rajoy explicará el próximo 8 de mayo en el Congreso las medidas del Gobierno </figcaption>
			</figure>
			<hgroup>
				<h2 onmouseover="ventanaNoticiasRelacionadas(1)"> NACIONAL. Rajoy explicará las nuevas medidas del Gobierno en el Congreso el 8 de mayo </h2>
				<h3> Autor: EFE </h3>
			</hgroup>
			<p class="cont_noticia"> El presidente del Gobierno, Mariano Rajoy, comparecerá el próximo miércoles, 8 de mayo, ante el 
				pleno del Congreso para explicar las medidas anunciadas en el último Consejo de Ministros para impulsar 
				el crecimiento económico y la creación de empleo.<br/><br/>
				La Junta de Portavoces del Congreso ha fijado hoy la fecha de la comparecencia del presidente del 
				Gobierno a petición propia, que se acumulará a las solicitudes planteadas por varios grupos parlamentarios 
				de la oposición.<br/><br/>
				El pleno del próximo miércoles se iniciará con la comparecencia del jefe del Ejecutivo para explicar 
				los planes y previsiones económicas del Ejecutivo y continuará con la habitual sesión de control al 
				Gobierno.<br/><br/>
				El pasado domingo, Rajoy, en la rueda de prensa que ofreció en Granada junto al primer ministro 
				irlandés y presidente de turno de la UE, Enda Kenny, aseguró que <cite>"sabe lo que hace"</cite> y que las medidas 
				aprobadas por el Gobierno permitirán crear empleo al final de la legislatura.<br/><br/>
        </article>
	</section>

	<section id="bloque_lateral">
		<article class="nacional">
			<h1> NOTICIAS RELACIONADAS </h1>
		</article>
			
        <article class="nacional">
			<a href="./hermano_carcanio_libertad_imputado_20130430.php">
				<h2> NACIONAL. El hermano de Carcaño queda en libertad tras declarar como imputado </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> Delgado ha declarado de forma "breve" a las 08.15 horas de hoy ante el juez de instrucción 4 de 
				Sevilla La declaración se produce después de que Carcaño en su séptima versión de los hechos le 
				acusara de matar a Marta con la culata de una pistola. </p>
        </article>
			
        <article class="nacional">
			<a href="./marea_impulsa_consulta_sanidad_20130430.php">
				<figure>
					<img class="img_noticia_relacionada" src="./marea_impulsa_consulta_sanidad_20130430/imagen_01.jpg"
						 alt="marea_impulsa_consulta_sanidad_20130430"/>
					<figcaption> Impulsan una consulta en la Comunidad de Madrid para conocer la opinión ciudadana sobre la 
								 externalización sanitaria </figcaption>
				</figure>
				<h2> NACIONAL. La 'marea blanca' impulsa en Madrid una 'Consulta por la Sanidad Pública' </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> Tendrá lugar entre los días 5 y 10 de mayo La pregunta que se plantea es: ¿Está usted a favor de 
				una sanidad de gestión pública, de calidad y universal. </p>
        </article>
	</section>
		
	<section id="publicidad_interior">
		<aside class="publi_interior">
			<a href="http://es.playstation.com/ps3/">
				<img class="img_publicidad_interior" src="../publicidad/publicidad_sony.jpg" alt="publicidad_sony"/>
			</a>
		</aside>
		
		<aside class="publi_interior">
			<a href="http://www.xbox.com/es-ES">
				<img class="img_publicidad_interior" src="../publicidad/publicidad_xbox.jpg" 
					 alt="publicidad_xbox"/>
			</a>
		</aside>
	</section>
		    
    <section id="opinion_lectores">
		<h1> OPINIONES DE LOS LECTORES</h1>
		
		<?php
			if(isset($_SESSION['usuario']))
				$usuario = $_SESSION['usuario'];
			else
				$usuario = "USUARIO NO REGISTRADO";
				
			$noticia = basename($_SERVER['PHP_SELF'],'.php');
			$ruta = "../nacional/".basename($_SERVER['PHP_SELF'])."#final";
			 
		?>
		
		<form action='../php/insertaComentario.php' method=post >
			<fieldset>
				<legend> <h3> Introduzca un nuevo comentario: </h3> </legend>
						
				<label for='comentarioUsuario'> Sesión actual del usuario: <?php print($usuario) ?> </label>
				<input type='hidden' id='comentarioUsuario' name='comentarioUsuario' value='<?php print($usuario) ?>'/>
				<br><br>
				<label for='textoComentario'> Comentario (máximo 200 caracteres): </label><br>
				<textarea id='textoComentario' name='textoComentario' cols='65' rows='3' maxlength='255' onblur="validaComentario()"></textarea>
				<input type='hidden' id='nombreNoticia' name='nombreNoticia' value='<?php print($noticia) ?>' />
				<input type='hidden' id='rutaNoticia' name='rutaNoticia' value='<?php print($ruta) ?>' />
				<br><br>
				<input type="button" id="botonValidar" value="Validar datos" onclick="validarFormulario()"/>
				<input type="reset" id="botonReiniciar" value="Borrar datos" onclick="reactivaCampos()"/>
				<input type="submit" id="botonEnviar" value="Enviar datos" disabled="true"/>
				
			</fieldset>

		</form>
	
		<br><h3> Comentarios sobre las noticias: </h3>
		
		<?php Comentario::mostrarComentarios(Comentario::getComentarios($noticia)); ?>
		<p id="final"></p>
    </section>

 <footer>
	 <h2> INFORMACIÓN DE CONTACTO </h2>
	 <p> <address> C/ Periodista Daniel Saucedo Aranda, s/n, 18071, Granada </address> </br>
		 <strong> Teléfono: </strong> 958 24 28 02 </br>
		 <strong> Correo electrónico: </strong> <a href="mailto:contacto@placeholder.com"> contacto@placeholder.com </a> </br></br>
		 <strong> <a href="../formulario.html"> Suscribirse a la versión impresa de PlaceHolder </strong> </a> </br></br>
		 <strong> <a href="../descripcion.pdf"> Cómo se hizo. </strong> </a>
	 </p>
 </footer>

</section>

</body>
</html>
