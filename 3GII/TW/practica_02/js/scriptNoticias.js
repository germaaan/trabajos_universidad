<!--
var ventanaAbierta = 0;
var comentarioCorrecto = 0;

function ventanaNoticiasRelacionadas(ind_seccion){
	var ruta;

	if (ventanaAbierta == 0){
		switch(ind_seccion){
			case 1:
				ruta = "../relacionadas/rel_nacional.html";
				break;
			case 2:
				ruta = "../relacionadas/rel_internacional.html";
				break;
			case 3:
				ruta = "../relacionadas/rel_economia.html";
				break;
			case 4:
				ruta = "../relacionadas/rel_deportes.html";
				break;
			default:
				ruta = "../index.php";
		}
		
		window.open(ruta,'','"channelmode=no,directories=no,fullscreen=no,height=482,width=539,location=no,menubar=no,resizable=no,scrollbars=no,status=no,left=600,top=80"');
		ventanaAbierta = 1;
	}
}

function abrirEnlace(enlace){
	window.opener.location.href = enlace;
	window.close();
}

function validarFormulario(){
	if (comentarioCorrecto == 0){
		alert("No se puede enviar. El comentario introducido no es valido. El campo de texto esta vacio o excede los 200 caracteres permitidos.");
		document.getElementById("botonEnviar").disabled = true;
	} else {
		alert("El comentario introducido es valido. Puede ser enviado.");
		document.getElementById("botonEnviar").disabled = false;
	}
}
		
function reactivaCampos(){
	comentarioCorrecto = 0;
	document.getElementById("botonEnviar").disabled = true;
}
		
function validaComentario(){
	var comentario = document.getElementById("textoComentario").value;
		
	if ((comentario.length > 0) && (comentario.length <= 200)){
		comentarioCorrecto=1;
	} else {
		comentarioCorrecto=0;
		alert("El comentario introducido no es valido. El campo de texto esta vacio o excede los 200 caracteres permitidos.");
		document.getElementById("botonEnviar").disabled = true;
	}
}
-->