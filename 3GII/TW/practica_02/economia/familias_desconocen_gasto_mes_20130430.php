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
    <title>PlaceHolder - ECONOMIA. Dos tercios de las familias desconocen cuánto gastan realmente cada mes</title>
    <meta name="description" content="Noticia económica del portal PlaceHolder">
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
		<img id="img_cabecera_secciones" src="../index/economia.jpg" alt="economia"/>
	</section>
   
	<section id="noticia_destacada">
		<article class="economia">
			<figure id="figura_noticia_destacada">
				<img class="img_noticia_destacada" src="./familias_desconocen_gasto_mes_20130430/imagen_01.jpg"  
					 alt="familias_desconocen_gasto_mes_20130430"/>
				<figcaption> Dos tercios de las familias desconocen cuánto gastan realmente cada mes </figcaption>
			</figure>
			<hgroup>
				<h2 onmouseover="ventanaNoticiasRelacionadas(3)"> ECONOMIA. Dos tercios de las familias desconocen cuánto gastan realmente cada mes </h2>
				<h3> Autor: lainformacion.com </h3>
			</hgroup>
			<p class="cont_noticia"> Tan sólo el 36 % de las familias conocen realmente cuánto gastan al mes y menos del 15 % saben con precisión 
				en qué partidas se les va el dinero, según un estudio del Observatorio de Consumo de la escuela de negocios 
				ESADE, presentado hoy.<br/><br/>
				Únicamente el 9 % de los hogares planifican mínimamente los gastos en función de los ingresos y son capaces 
				de corregir los resultados negativos, lo que les permite ahorrar entre un 10 y un 15 %.<br/><br/>
				Nueve de cada diez hogares desconocen con precisión en qué gastan, lo que este informe atribuye a una falta 
				de cultura de gestión de la economía.<br/><br/>
				La mayoría de los españoles tienen la contabilidad <cite>"en la cabeza"</cite>, lo que dificulta controlar con precisión 
				el gasto, según ha explicado el autor del estudio, el profesor de Márketing Gerard Costa.<br/><br/>
				Por ello, ha defendido que los alumnos reciban desde ESO una formación financiera sólida y mantenida a largo 
				plazo para modificar estas circunstancias.<br/><br/>
				No obstante, el 92 % asegura que ha modificado los gastos desde 2007, cuando empezó la crisis, y un 86 % se 
				ha puesto como prioridad controlar mejor la economía doméstica, pues es consciente de que la crisis se ha 
				convertido en la <cite>"nueva normalidad"</cite>, ya no creen en <cite>"brotes verdes"</cite> y es imprescindible adaptarse a la situación 
				con una <cite>"economía de guerra"</cite>.
				Ante la imposibilidad general de mayores ingresos, las familias han optado por reducir gastos puntuales 
				elevados <strong>(restaurantes, ocio, viajes, ropa)</strong> o han retrasado compras como automóviles o frigoríficos, pero no 
				logran reducir el importe de las facturas de los servicios como electricidad, agua y telefonía.<br/><br/>
				Pero las familias no saben, en el 85 % de los casos, cómo se reducen realmente los gastos, pues no 
				presupuestan.<br/><br/>
				Según los antecedentes, la tasa de ahorro familiar pasó del 11 % entre 2005 y 2008 al 17 % entre 2008 y 
				2010 para volver a caer al 9 % hasta 2012.<br/><br/>
				Un 39 % de los españoles no ahorra nada y el 46 % de manera esporádica.<br/><br/>
				El ama de casa ha dejado de ir al hipermercado, fragmenta la compra en muchas tiendas de cercanía, dedica 
				mucho más tiempo a comprar y adquiere marcas blancas, al menos para ella, según Costa.<br/><br/>
				El estudio se basa en los resultados de encuestas efectuadas entre más de 200 familias de Madrid, Barcelona, 
				Sevilla, Vigo, Zaragoza y Elche en el segundo semestre de 2012.<br/><br/>
        </article>
	</section>

	<section id="bloque_lateral">
		<article class="economia">
			<h1> NOTICIAS RELACIONADAS </h1>
		</article>
			
		<article class="economia">
			<a href="./despedir_veinte_dias_comun_20130423.php">
				<figure id="figura_noticia_destacada">
					<img class="img_noticia_relacionada" src="./despedir_veinte_dias_comun_20130423/imagen_01.jpg"  
						 alt="despedir_veinte_dias_comun_20130423"/>
					<figcaption> Protesta de trabajadores contra de un Expediente de Regulación de Empleo.
								 </figcaption>
				</figure>
				<h2> ECONOMIA. Despedir con 20 días ya es más común que hacerlo con 45 tras la reforma laboral </h2>
            </a>
            <h3> Autor: Bruno Pérez </h3>
            <p> Los despidos por causas objetivas o como consecuencia de un ERE superaron en 2012 por primera vez 
				en lustros los improcedentes con 45 días de indemnización. La compensación media por despido de los 
				trabajadores españoles ha caído un 20% desde la reforma laboral.</p>
        </article>
			
        <article class="economia">
			<a href="./economia/ugt_ccoo_organizan_manifestacion_20130430.php">
				<h2> ECONOMIA. UGT y CC.OO. organizan mañana una manifestación para reclamar una nueva política económica 
					 y decir 'no' a la austeridad </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> UGT y CC.OO. han organizado para mañana, Día Internacional del Trabajo, más de 80 manifestaciones 
				conjuntas en toda España, cuya marcha central tendrá lugar en Madrid, para reclamar una nueva política 
				económica, centrada en el crecimiento y el empleo, y decir 'no' a la austeridad y los recortes. </p>
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
			$ruta = "../economia/".basename($_SERVER['PHP_SELF'])."#final";
			 
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
