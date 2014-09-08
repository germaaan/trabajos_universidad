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
    <title>PlaceHolder - NACIONAL. Interior admite que ya "se vislumbra el final" de ETA pero pide no cantar victoria</title>
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
				<img class="img_noticia_destacada" src="./interior_admite_final_eta_20130422/imagen_01.jpg"  
					 alt="interior_admite_final_eta_20130422"/>
				<figcaption> Fernández Díaz admite que ya <cite>"se vislumbra el final"</cite> de ETA </figcaption>
			</figure>
			<hgroup>
				<h2 onmouseover="ventanaNoticiasRelacionadas(1)"> NACIONAL. Interior admite que ya "se vislumbra el final" de ETA pero pide no cantar victoria </h2>
				<h3> Autor: Europa Press </h3>
			</hgroup>
            <p class="cont_noticia"> El ministro del Interior Jorge Fernández Díaz ha admitido que ya <cite>"se vislumbra el final"</cite> de ETA, 
				pero ha pedido <cite>"no cantar victoria"</cite> hasta que la banda se disuelva definitivamente. Además ha dicho 
				que España cuenta con unidades policiales <cite>"preparadas para hacer frente"</cite> a atentados como el de Boston. <br/><br/>
				<cite>"Cuando vislumbramos el final del terrorismo, aunque no cantamos victoria hasta el fin definitivo, vemos 
				que la Guardia Civil ha sido protagonista en la lucha por las libertades y la unidad de España"</cite>, ha dicho 
				el ministro durante su visita este lunes a las instalaciones del Grupo de Acción Rural (GAR) del Instituto 
				Armado en Logroño (La Rioja). <br/><br/>
				Según ha destacado, estas instalaciones <cite>"acogen a una parte de los mejores hijos de España"</cite>. <cite>"Para mi es 
				un orgullo esta unidad que siempre ha combatido en primera línea contra el terrorismo, por eso mi admiración 
				a quienes perdieron la vida. Allí donde otros no llegaban, llegaba el GAR"</cite>, ha dicho sobre esta unidad 
				especializada compuesta por cerca de 400 agentes. <br/><br/>
				Posteriormente en declaraciones a los medios ha hecho referencia al atentado de Boston, aunque sin citarlo 
				expresamente: <cite>"hemos visto estos días en un país tan desarrollado como EEUU que hay que estar preparados 
				ante contingencias de todo tipo y no me debo extender más porque saben lo que estamos pensando"</cite>. <cite>"Y en 
				España tenemos unidades preparadas muy profesionales para hacer frente a este tipo de estas 
				características"</cite>, ha añadido. <br/><br/>
				El ministro ha firmado un convenio de colaboración con la Consejería de Presidencia y Justicia del 
				Gobierno de La Rioja en materia de formación y sobre el proyecto de construcción de las instalaciones 
				del Polígono de Experiencias para Fuerzas Especiales de la Guardia Civil (PEFE-GC) situado en Logroño. <br/><br/>
				Previsiblemente el proyecto comenzará a construirse el año próximo y se desarrollará en cuatro fases. 
				La primera de ellas cuenta con un presupuesto de 4 millones de euros y el coste total del proyecto 
				asciende a 18 millones que asumirá por completo la Guardia Civil. <br/><br/>
        </article>
	</section>

	<section id="bloque_lateral">
		<article class="nacional">
			<h1> NOTICIAS RELACIONADAS </h1>
		</article>
			
		<article class="nacional">
			<a href="./juez_ordena_prision_gal_20130422.php">
				<h2> NACIONAL. El juez ordena el ingreso en prisión de Michel Domínguez, exmiembro de los GAL, por tráfico
					de droga </h2>
			</a>
			<h3> Autor: lainformacion.com </h3>
            <p> Prisión, comunicada y sin fianza, para el ex policía y antiguo miembro de los GAL Michel Domínguez. </p>
		</article>
			
		<article class="nacional">
			<a href="./rajoy_explicara_nuevas_medidas_20130430.php">
				<figure>
					<img class="img_noticia_relacionada" src="./rajoy_explicara_nuevas_medidas_20130430/imagen_01.jpg"
						 alt="rajoy_explicara_nuevas_medidas_20130430"/>
					<figcaption> Rajoy explicará el próximo 8 de mayo en el Congreso las medidas del Gobierno
								 </figcaption>
				</figure>
				<h2> NACIONAL. Rajoy explicará las nuevas medidas del Gobierno en el Congreso el 8 de mayo </h2>
			</a>
			<h3> Autor: lainformacion.com </h3>
			<p> El pleno del próximo miércoles se iniciará con la comparecencia del jefe del Ejecutivo. Se acumulará 
				a las solicitudes planteadas por varios grupos parlamentarios de la oposición. </p>
		</article>
	</section>
		
	<section id="publicidad_interior">
		<aside class="publi_interior">
			<a href="http://es.playstation.com/ps3/">
				<img class="img_publicidad_interior" src="../publicidad/publicidad_sony.jpg" 
					 alt="publicidad_sony"/>
			</a>
		</aside>
		
		<aside class="publi_interior">
			<a href="http://www.xbox.com/es-ES">
				<img class="img_publicidad_interior" src="../publicidad/publicidad_xbox.jpg" 
					 alt="publicidad_xbox"/>
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
