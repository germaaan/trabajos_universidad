<!--
var usuarioCorrecto = 0;
var passCorrecto = 0;
var nombreCorrecto = 0;
var apellidosCorrecto = 0;
var correoCorrecto = 0;
var direccionCorrecto = 0;
var codPostalCorrecto = 0;
var ciudadCorrecto = 0;
var telefonoCorrecto = 0;
var edadCorrecto = 0;

function validarCampos(){
	if (usuarioCorrecto == 0){
		alert("No se puede enviar. El usuario introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (passCorrecto == 0){
		alert("No se puede enviar. El password introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (nombreCorrecto == 0){
		alert("No se puede enviar. El nombre introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (apellidosCorrecto == 0){
		alert("No se puede enviar. Los apellidos introducidos no son validos.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (correoCorrecto == 0){
		alert("No se puede enviar. La direccion de correo electronico introducida no es valida.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (direccionCorrecto == 0){
		alert("No se puede enviar. La direccion postal introducida no es valida.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (codPostalCorrecto == 0){
		alert("No se puede enviar. El codigo postal introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (ciudadCorrecto == 0){
		alert("No se puede enviar. La ciudad introducida no es valida.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (telefonoCorrecto == 0){
		alert("No se puede enviar. El numero de telefono movil introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	} else if (edadCorrecto == 0){
		alert("No se puede enviar. La edad introducida no es valida.");
		document.getElementById("botonEnviar").disabled = true;
	} else {
		alert("Todos los datos introducidos son correctos.");
		document.getElementById("botonEnviar").disabled = false;
	}
}
		
function reactivaCampos(){
	usuarioCorrecto = 0;
	passCorrecto = 0;
	nombreCorrecto = 0;
	apellidosCorrecto = 0;
	correoCorrecto = 0;
	direccionCorrecto = 0;
	codPostalCorrecto = 0;
	ciudadCorrecto = 0;
	telefonoCorrecto = 0;
	edadCorrecto = 0;
	document.getElementById("botonEnviar").disabled = true;
}
		
function validaUsuario(){
	var usuario = document.getElementById("campoUsuario").value;
	var erUsuario = /^\b[A-Za-z]([\w]{4,20})\b$/g;
	
	if (erUsuario.test(usuario)){
		usuarioCorrecto=1;
	} else {
		usuarioCorrecto=0;
		alert("El nombre de usuario introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	}
}

function validaPass(){
	var pass = document.getElementById("campoPass").value;
	var erPass = /^\b[A-Za-z]([\w]{5,20})\b$/g;
			
	if (erPass.test(pass)){
		passCorrecto=1;
	} else {
		passCorrecto=0;
		alert("El password introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	}
}

function validaNombre(){
	var nombre = document.getElementById("campoNombre").value;
	var erNombre = /^\b[A-Z][a-z]+\b(\s\b[A-Z][a-z]+\b)?$/g;
	
	if (erNombre.test(nombre)){
		nombreCorrecto=1;
	} else {
		nombreCorrecto=0;
		alert("El nombre introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	}
}
	
function validaApellidos(){
	var apellidos = document.getElementById("campoApellidos").value;
	var erApellidos = /^\b[A-Z][a-z]+\b(\s\b[A-Z][a-z]+\b)?$/g;
	
	if (erApellidos.test(apellidos)){
		apellidosCorrecto=1;
	} else {
		apellidosCorrecto=0;
		alert("Los apellidos introducidos no son validos.");
		document.getElementById("botonEnviar").disabled = true;
	}
}
		
function validaCorreo(){
	var correo = document.getElementById("campoCorreo").value;
	var erCorreo = /^\b[a-z][\w\._]*[\w]+@[a-z]+(\.[a-z]+)*\.[a-z]{2,3}\b$/g;
	
	if (erCorreo.test(correo)){
		correoCorrecto=1;
	} else {
		correoCorrecto=0;
		alert("La direccion de correo electronico introducida no es valida.");
		document.getElementById("botonEnviar").disabled = true;
	}
}
		
function validaDireccion(){
	var direccion = document.getElementById("campoDireccion").value;
	var erDireccion = /["Calle""Avenida""Plaza""Carretera"](\s\b[A-Z][a-z]+\b){1,4},\s[1-9]\d{0,3}/g;
	
	if (erDireccion.test(direccion)){
		direccionCorrecto=1;
	} else {
		direccionCorrecto=0;
		alert("La direccion postal introducida no es valida.");
		document.getElementById("botonEnviar").disabled = true;
	}
}

function validaCodPostal(){
	var codPostal = document.getElementById("campoCodPostal").value;
	var erCodPostal = /^[0-5]\d{4}$/g;
			
	if (erCodPostal.test(codPostal)){
		codPostalCorrecto=1;
	} else {
		codPostalCorrecto=0;
		alert("El codigo postal introducido no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	}
}

function validaCiudad(){
	var ciudad = document.getElementById("campoCiudad").value;
	var erCiudad  = /^\b[A-Z][a-z]*\b(\s\b[A-Z][a-z]+\b){0,3}$/g;
	
	if (erCiudad.test(ciudad)){
		ciudadCorrecto=1;
	} else {
		ciudadCorrecto=0;
		alert("La ciudad introducida no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	}
}
		
function validaTelefono(){
	var telefono = document.getElementById("campoTelefono").value;
	var erTelefono = /^[67]\d{2}([\.-\s]?\d{2}){3}$/g;
	
	if (erTelefono.test(telefono)){
			telefonoCorrecto=1;
	} else {
		telefonoCorrecto=0;
		alert("El numero de telefono movil introducio no es valido.");
		document.getElementById("botonEnviar").disabled = true;
	}
}

function validaEdad(){
	var edad = document.getElementById("campoEdad").value;
	
	if ((edad>16) && (edad<100)){
		edadCorrecto=1;
	} else {
		edadCorrecto=0;
		alert("La edad introducida no es valida.");
		document.getElementById("botonEnviar").disabled = true;
	}
}
-->