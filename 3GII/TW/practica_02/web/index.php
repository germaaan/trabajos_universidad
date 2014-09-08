<?php
	session_start();  
  
	ini_set('display_errors', true);
	error_reporting(E_ALL);
						
	require_once "./php/Usuario.class.inc";
	require_once "./php/NoticiaUltimaHora.class.inc";
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="./css/index.css">
    <title>PlaceHolder - Portada</title>
    <meta name="description" content="Portada del portal PlaceHolder">
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
        <a href="index.php">
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
   
    <section id="noticias_uno">
        <article class="nacional">
			<a href="./nacional/interior_admite_final_eta_20130422.php">
				<figure>
					<img class="img_noticias_uno" src="./nacional/interior_admite_final_eta_20130422/imagen_01.jpg" 
						 alt="interior_admite_final_eta_20130422"/>	 
					<figcaption> Fernández Díaz admite que ya "se vislumbra el final" de ETA pero pide no cantar victoria
								 </figcaption>
				</figure>
				<h2> NACIONAL. Interior admite que ya "se vislumbra el final" de ETA pero pide no cantar victoria </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> Fernández Díaz señala que España cuenta con unidades policiales "preparadas para hacer
                frente" a atentados como el de Boston. "Hemos visto estos días en un país tan desarrollado
                como EEUU que hay que estar preparados ante contingencias de todo tipo". </p>
        </article>
        
        <article class="nacional">
			<a href="./nacional/juez_ordena_prision_gal_20130422.php">
				<h2> NACIONAL. El juez ordena el ingreso en prisión de Michel Domínguez, exmiembro de los GAL, por tráfico
					de droga </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> Prisión, comunicada y sin fianza, para el ex policía y antiguo miembro de los GAL Michel Domínguez. </p>
        </article>
        
        <article class="internacional">
			<a href="./internacional/canada_frustra_ataque_terrorista_20130422.php">
				<figure>
					<img class="img_noticias_uno" src="./internacional/canada_frustra_ataque_terrorista_20130422/imagen_01.jpg"
						 alt="canada_frustra_ataque_terrorista_20130422"/>
					<figcaption> Canadá frustra un ataque dirigido por Al Qaeda en Irán contra un tren en Toronto
								 </figcaption>
				</figure>
				<h2> INTERNACIONAL. Canadá frustra un "gran ataque terrorista apoyado por Al Qaeda" contra un tren de 
					pasajeros </h2>
			</a>
            <h3> Autor: lainformacion.com </h3>
            <p> Chiheb Esseghaier y Raed Jasern sido acusados por la policía canadiense como supuestos terroristas 
				vinculados a Al Qaeda. Su objetivo era, según la misma fuente. </p>
        </article>
        
        <article class="internacional">
			<a href="./internacional/sospechoso_atentados_boston_juzgado_20130422.php">
				<h2> INTERNACIONAL. El sospechoso vivo de los atentados de Boston no será juzgado como combatiente enemigo </h2>
			</a>
            <h3> Autor: lainformacion.com </h3>
            <p> El presunto coautor de los atentados será juzgado ante un tribunal civil. Los dos hermanos 
				Tsarnaev son considerados los presuntos autores de los atentados de hace una semana. </p>
        </article>
        
		<article class="economia">
			<a href="./economia/despedir_veinte_dias_comun_20130423.php">
				<figure>
					<img class="img_noticias_uno" src="./economia/despedir_veinte_dias_comun_20130423/imagen_01.jpg"  
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
    </section>

    <section id="noticias_dos">
        <article class="economia">
			<a href="./economia/familias_desconocen_gasto_mes_20130430.php">
				<figure>
					<img class="img_noticias_dos" src="./economia/familias_desconocen_gasto_mes_20130430/imagen_01.jpg"
						 alt="familias_desconocen_gasto_mes_20130430"/>
					<figcaption> Dos tercios de las familias desconocen cuánto gastan realmente cada mes </figcaption>
				</figure>
				<h2> ECONOMIA. Dos tercios de las familias desconocen cuánto gastan realmente cada mes </h2>
            </a>
            <h3> Autor: lainformacion.com </h3>
            <p> Tan sólo el 36 % de las familias conocen realmente cuánto gastan al mes y menos del 15 % saben 
				con precisión en qué partidas se les va el dinero, según un estudio del Observatorio de Consumo 
				de la escuela de negocios ESADE, presentado hoy. </p>
        </article>
        
        <article class="deportes">
			<a href="./deportes/real_madrid_gol_milagro_20130501.php">
				<figure>
					<img class="img_noticias_dos" src="./deportes/real_madrid_gol_milagro_20130501/imagen_01.jpg"  
						 alt="real_madrid_gol_milagro_20130501"/>
					<figcaption> Partido de vuelta de las semifinales de UEFA Champions League </figcaption>
				</figure>
				<h2> DEPORTES. El Real Madrid, a un gol de conseguir el milagro </h2>
			</a>
            <h3> Autor: sportyou </h3>
            <p> El Real Madrid se quedó a un palmo de escribir una de las páginas más asombrosas de su brillante 
				historia. No podía con un Borussia Dortmund firme durante ochenta minutos, pero en los diez finales 
				un gran arreón con los goles de Benzema y Sergio Ramos le dejaron a un solo tanto de la hazaña. </p>
        </article>
        
        <article class="deportes">
			<iframe class="youtube-player" type="text/html" width="208" height="172" src="http://www.youtube.com/embed/c4VyzDNicU0"
					frameborder="0"> </iframe>
			<a href="./deportes/vilanova_caemos_cabeza_alta_20130430.php">
				<h2> DEPORTES. Tito Vilanova: "Si caemos, debe ser con la cabeza bien alta" </h2>
			</a>
            <h3> Autor: EFE </h3>
            <p> El técnico del FC Barcelona, Tito Vilanova, ha dicho que su equipo "luchará" para remontar la 
				eliminatoria de semifinales de Liga de Campeones ante el Bayern, tras el 4-0 del partido de ida, 
				y ha apuntado que, si al final cae derrotado, deberá ser "con la cabeza bien alta". </p>
        </article>
    </section>


    <section id='ultimas_noticias'>
		
		<?php
		echo "<article id='acceso'>";
			
			if (isset($_SESSION['usuario'])){
				$usuario = $_SESSION['usuario'];
				echo "<p> <br><strong>Bienvenido:</strong> <br><br> ".Usuario::getNombreUsuario($usuario)."</p>";
				echo "<br><h3><a href='./php/exit.php'> Cerrar sesión </a></h3>";
			} else {
				echo "<form action='./php/login.php' method=post >";
					echo "<fieldset>";
						echo "<legend> <strong> Acceso de usuario: </strong> </legend>";
						echo "<label for='usuario'> Nombre: </label>";				
						echo "<input type='text' id='usuario' name='usuario' maxlength='20'/>";
						echo "<label for='pass'> Password: </label>";				
						echo "<input type='password' id='pass' name='pass' maxlength='20'/>";
						echo "<input type='submit' id='botonEnviar' value='Enviar datos'/>";
						echo "<a href='./formulario.html'> Registrarse </a>";
					echo "</fieldset>";
				echo "</form>";
			}
	
		echo "</article>";
		
		if (isset($_SESSION['usuario'])){
		$admin = $_SESSION['usuario'];
					
			if ($admin == 'admin'){
				echo "<article id='acceso'>";
					echo "<h2> GESTIÓN NOTICIAS ULTIMA HORA: </h2>";
					echo "<form action='./php/gestion.php' method=post >";
						echo "<input type='radio' name='accion' value='aniadir'>Añadir<br>";
						echo "<input type='radio' name='accion' value='actualizar'>Actualizar<br>";
						echo "<input type='radio' name='accion' value='borrar'>Borrar<br>";
						echo "<input type='submit' id='realizar' value='Realizar acción'/>";
					echo "</form>";
				echo "</article>";
			}
		}
		
        echo "<article id='ultima_hora'>";
			echo "<h2> NOTICIAS ULTIMA HORA: </h2>";
			NoticiaUltimaHora::mostrarNoticias(NoticiaUltimaHora::getNoticiasUltimaHora());
        echo "</article>";
		
	?>
        <section id="publicidad">
            <aside class="publi_interior">
                <a href="http://es.playstation.com/ps3/">
					<img class="img_publicidad_interior" src="./publicidad/publicidad_sony.jpg" 
						 alt="publicidad_sony"/>
				</a>
			</aside>
			
            <aside class="publi_interior">
                <a href="http://www.xbox.com/es-ES">
					<img class="img_publicidad_interior" src="./publicidad/publicidad_xbox.jpg" 
					     alt="publicidad_xbox"/>
				</a>
			</aside>
	     </section>
    </section>

 <footer>
	 <h2> INFORMACIÓN DE CONTACTO </h2>
	 <p> <address> C/ Periodista Daniel Saucedo Aranda, s/n, 18071, Granada </address> </br>
		 <strong> Teléfono: </strong> 958 24 28 02 </br>
		 <strong> Correo electrónico: </strong> <a href="mailto:contacto@placeholder.com"> contacto@placeholder.com </a> </br></br>
		 <strong> <a href="./formulario.html"> Suscribirse a la versión impresa de PlaceHolder </strong> </a> </br></br>
		 <strong> <a href="./descripcion.pdf"> Cómo se hizo. </strong> </a>
	 </p>
 </footer>

</section>

</body>
</html>
