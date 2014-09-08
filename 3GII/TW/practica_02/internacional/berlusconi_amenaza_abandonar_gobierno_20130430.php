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
    <title>PlaceHolder - INTERNACIONAL. Berlusconi amenaza con abandonar el Gobierno si no quitan la tasa sobre la casa</title>
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
				<img class="img_noticia_destacada" src="./berlusconi_amenaza_abandonar_gobierno_20130430/imagen_01.jpg"  
					 alt="berlusconi_amenaza_abandonar_gobierno_20130430"/>
				<figcaption> El Gobierno de Letta logra la investidura definitiva en el Parlamento italiano </figcaption>
			</figure>
			<hgroup>
				<h2 onmouseover="ventanaNoticiasRelacionadas(2)"> INTERNACIONAL. Berlusconi amenaza con abandonar el Gobierno si no quitan la tasa sobre la casa </h2>
				<h3> Autor: EFE </h3>
			</hgroup>
			<p class="cont_noticia"> El expresidente del Gobierno italiano y líder del conservador Pueblo de la Libertad (PDL), Silvio 
				Berlusconi, amenazó hoy con salir del Gobierno de unidad nacional de Enrico Letta si no se elimina el 
				impuesto sobre la primera casa (IMU, en italiano).<br/><br/>
				<cite>"No podemos formar parte de un Gobierno que no aplique las medidas sobre el IMU, <strong>(es decir la restitución 
				de lo que ya han pagado los italianos y su abolición definitiva)</strong>"</cite>, afirmó Berlusconi a los medios de 
				comunicación italianos antes de entrar a votar en el Senado la confianza al Gobierno de Letta.<br/><br/>
				La formación de Berlusconi, el PDL, junto con el Partido Demócrata (PD), al que pertenece Letta, y 
				Elección Cívica, del expresidente del Gobierno Mario Monti, han dado vida a un Gobierno de unidad nacional 
				ante la imposibilidad de crear un Ejecutivo tras los resultados de las pasadas elecciones del 24 y 25 de 
				febrero.<br/><br/>
				Para la formación del Gobierno, el PDL había puesto sus cláusulas y una de ellas era la abolición del 
				impuesto sobre la primera casa, la gran promesa de Berlusconi durante la campaña electoral.<br/><br/>
				Letta explicó ayer en la Cámara de los Diputados en el discurso en el que se detallaba el programa de 
				este Gobierno, que una de las primeras medidas será la <cite>"congelación"</cite> en junio del pago del segundo trimestre 
				de este impuesto.<br/><br/>
				El ministro de Asuntos Regionales de este nuevo Ejecutivo, Graziano Delrio, puntualizó hoy que la 
				suspensión de este plazo "es para ganar tiempo mientras se estudia una reforma para reducir la tasa para 
				las familias con menos ingresos".<br/><br/>
				<cite>"No podremos formar parte de un Gobierno, ni apoyarlo externamente <strong>(si no se cumplen las medidas del IMU)</strong>. 
				Pues tenemos este compromiso con nuestros electores y queremos mantenerlos"</cite>, agregó Berlusconi, quien se 
				mostró <cite>"confiado"</cite> en que el Ejecutivo cumpla con la abolición de la tasa.<br/><br/>
				El IMU se prevé que será uno de los temas más conflictivos en el camino de este Ejecutivo, ya que con 
				el impuesto sobre la primera casa se esperaban recoger en este segundo semestre cerca 2.000 millones de 
				euros que van a las arcas de los municipios que ya han advertido de los problemas que esto conllevará.<br/><br/>
				<cite>"Existe un problema de liquidez para los ayuntamientos que intentaremos afrontar"</cite>, aseguró Delrio.<br/><br/>
				Tanto el Partido Demócrata como Elección Cívica habían previsto en sus programas electorales una 
				eliminación del IMU sobre la primera casa de manera gradual y no contemplaban la devolución de los 3.900 
				millones de euros recogidos en 2012 con la reintroducción de este impuesto por parte de Monti y que había 
				abolido Berlusconi.<br/><br/>
        </article>
	</section>

	<section id="bloque_lateral">
		<article class="internacional">
			<h1> NOTICIAS RELACIONADAS </h1>
		</article>
			
		<article class="internacional">
			<a href="./canada_frustra_ataque_terrorista_20130422.php">
				<figure id="figura_noticia_destacada">
					<img class="img_noticia_relacionada" src="./canada_frustra_ataque_terrorista_20130422/imagen_01.jpg"  
						 alt="canada_frustra_ataque_terrorista_20130422"/>
					<figcaption> Canadá frustra un ataque dirigido por Al Qaeda en Irán en Toronto </figcaption>
				</figure>
				<h2> INTERNACIONAL. Canadá frustra un "gran ataque terrorista apoyado por Al Qaeda" contra un tren de 
					pasajeros </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> <strong>Chiheb Esseghaier</strong> y <strong>Raed Jasern</strong> sido acusados por la policía 
				canadiense como supuestos terroristas vinculados a <strong>Al Qaeda</strong>. Su objetivo 
				era, según la misma fuente. </p>
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
		
		<aside class="publi_interior">
			<a href="http://www.nintendo.com/wiiu/es">
				<img class="img_publicidad_interior" src="../publicidad/publicidad_nintendo.jpg" 
					 alt="publicidad_nintendo"/>
			</a>
		</aside>
		
		<aside class="publi_interior">
			<a href="http://es.uefa.com/uefachampionsleague/index.php">
				<img class="img_publicidad_interior" src="../publicidad/publicidad_champions.jpg" 
					 alt="publicidad_champions"/>
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
