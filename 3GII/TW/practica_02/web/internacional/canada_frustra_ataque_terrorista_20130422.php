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
    <title>PlaceHolder - INTERNACIONAL. Canadá frustra un "gran ataque terrorista apoyado por Al Qaeda" contra un tren de pasajeros</title>
    <meta name="description" content="Noticia internacional del portal PlaceHolder">
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
		<img id="img_cabecera_secciones" src="../index/internacional.jpg" alt="internacional"/>
	</section>
   
	<section id="noticia_destacada">
		<article class="internacional">
			<figure id="figura_noticia_destacada">
				<img class="img_noticia_destacada" src="./canada_frustra_ataque_terrorista_20130422/imagen_01.jpg"  
					 alt="canada_frustra_ataque_terrorista_20130422"/>
				<figcaption> Canadá frustra un ataque dirigido por Al Qaeda en Irán contra un tren en Toronto </figcaption>
			</figure>
				<hgroup>
					<h2 onmouseover="ventanaNoticiasRelacionadas(2)"> INTERNACIONAL. Canadá frustra un "gran ataque terrorista apoyado por Al Qaeda" contra un tren de 
						 pasajeros </h2>
					<h3> Autor: Reuters </h3>
				</hgroup>
			<p class="cont_noticia"> La policía canadiense ha acusado a dos residentes de un complot con vinculación con Al Qaeda para 
				<cite>"llevar adelante un ataque terrorista"</cite> contra un tren de pasajeros.<br/><br/>
				La Real Policía Montada de Canadá identificó a los dos acusados como Chiheb Esseghaier y Raed Jaser, 
				de las zonas de Montreal y Toronto, respectivamente.<br/>
				<cite>"Mientras la policía creyó que estos individuos tenían la capacidad y la intención de llevar adelante 
				estos actos criminales, no había una amenaza inmediata para el público general, los empleados, 
				pasajeros o infraestructura del tren"</cite>, destacó la fuerza en una declaración.<br/><br/>
        </article>
	</section>

	<section id="bloque_lateral">
		<article class="internacional">
			<h1> NOTICIAS RELACIONADAS </h1>
		</article>
			
        <article class="internacional">
			<a href="./sospechoso_atentados_boston_juzgado_20130422.php">
				<figure>
					<img class="img_noticia_relacionada" src="./sospechoso_atentados_boston_juzgado_20130422/imagen_01.jpg"
						 alt="sospechoso_atentados_boston_juzgado_20130422"/>
					<figcaption> El sospechoso del atentado de Boston está consciente y se comunica por escrito </figcaption>
				</figure>
				<h2> INTERNACIONAL. El sospechoso vivo de los atentados de Boston no será juzgado como combatiente enemigo </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> El <strong>presunto coautor</strong> de los atentados será juzgado ante un tribunal civil. Los dos hermanos 
				<strong>Tsarnaev</strong> son considerados los presuntos autores de los atentados de hace una semana. </p>
        </article>
			
        <article class="internacional">
			<a href="./letta_continente_unido_moneda_20130430.php">
				<h2> INTERNACIONAL. Letta: "Un continente como el nuestro no puede estar solo unido por la moneda" </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> El nuevo primer ministro italiano, Enrico Letta, afirmó hoy que un continente como Europa "no puede estar 
				unido solo por la moneda", en un claro mensaje europeísta sobre la política que llevará a cabo su Ejecutivo 
				de coalición. </p>
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
			$ruta = "../internacional/".basename($_SERVER['PHP_SELF'])."#final";
			 
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
