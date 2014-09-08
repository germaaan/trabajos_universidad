#!/usr/bin/env python
# -*- coding: utf-8 -*-

import web
from web.contrib.template import render_mako
from web import form
import time
from datetime import date
import anydbm

# Para poder usar sesiones con web.py
web.config.debug = False

urls = (
	'/', 'inicio',
	'/login', 'login',
	'/logout', 'logout',
	'/Nacional', 'nacional',
	'/Internacional', 'internacional',
	'/Tecnologia', 'tecnologia',
	'/Deportes', 'deportes',
	'/registro', 'registro',
	'/datos_usuario', 'datos_usuario',
	'/modificar', 'modificar'
)

app = web.application(urls, locals())

sesion = web.session.Session(app, web.session.DiskStore('sessions'), initializer={'usuario':'','link1':'','link2':'','link3':''})


# Templates de mako
render = render_mako(
	directories = ['templates'],
	input_encoding = 'utf-8',
	output_encoding = 'utf-8')

# Formulario de acceso
form_acceso = form.Form(
	form.Textbox("usuario", form.notnull, description="Usuario:"),
	form.Password("password", form.notnull, description="Contraseña:"),
	form.Button("Acceder", type="submit"),
)

# Expresiones regulares validación
vTexto = form.regexp(r"^[\w\s]+$", 'Ningún campo de texto puede estar vacío.')
vEmail = form.regexp(r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$", 'El correo electrónico introducido no es válido.')
vVISA = form.regexp(r"^([0-9]{4}) ([0-9]{4}) ([0-9]{4}) ([0-9]{4})$|^([0-9]{4})-([0-9]{4})-([0-9]{4})-([0-9]{4})$", 'El número de la tarjeta VISA introducido no es válido.')
vpass = form.regexp(r".{8,}$", 'La contraseña debe tener mínimo 8 o más caractéres.')

# Formulario de registro
form_datos = form.Form( 
	form.Textbox("usuario", vTexto, description = "Usuario:"),
	form.Password("password", vpass, description = "Contraseña:"),
	form.Password("verificacion", vpass, description = "Verificar contraseña:"),
	form.Textbox("nombre", vTexto, description = "Nombre:"),
	form.Textbox("apellidos", vTexto, description = "Apellidos:"),
	form.Textbox("correo", vEmail, description = "Correo electrónico:"),
	form.Textbox("visa", vVISA, description = "Número de VISA:"),
	form.Dropdown("dia", range(1, 32), description = "Día:"),
	form.Dropdown("mes", range(1, 13), description = "Mes:"),
	form.Dropdown("anio", range(date.today().year - 85, date.today().year + 1), description="Año:"),
	form.Textarea("direccion", vTexto, description = "Dirección:"),
	form.Radio("pago", ["Contrarembolso", "Transferencia bancaria", "Tarjeta de credito", "Paypal"], description="Formas de pago:", value = "Contrarembolso"),
	form.Checkbox("clausulas", description = "Aceptación clausulas:"),
	form.Button("Enviar datos", type="submit"),
	validators=[
		form.Validator("Es necesario aceptar las clausulas", lambda i: "clausulas" in i),
		form.Validator("Las contraseñas introducidas no coinciden.", lambda i: i.password == i.verificacion),
		form.Validator("Fecha de nacimiento no válida.", lambda i: (((int(i.mes) == 2) and 
			((int(i.dia) <= 28) and ((int(i.anio) % 4) != 0) or (int(i.dia) <= 29) and ((int(i.anio) % 4) == 0))) or
			((int(i.dia) <= 31) and	((int(i.mes) == 1) or (int(i.mes) == 3) or (int(i.mes) == 7) or (int(i.mes) == 8) 
			or (int(i.mes) == 10) or (int(i.mes) == 12))) or 			
			((int(i.dia) <= 30) and	((int(i.mes) == 4) or (int(i.mes) == 6) or (int(i.mes) == 9) or (int(i.mes) == 11)))))
	]
) 

# Formulario de modificacion
form_modificar = form.Form( 
	form.Textbox("nombre", vTexto, description = "Nombre:"),
	form.Textbox("apellidos", vTexto, description = "Apellidos:"),
	form.Textbox("correo", vEmail, description = "Correo electrónico:"),
	form.Textbox("visa", vVISA, description = "Número de VISA:"),
	form.Dropdown("dia", range(1, 32), description = "Día:"),
	form.Dropdown("mes", range(1, 13), description = "Mes:"),
	form.Dropdown("anio", range(date.today().year - 85, date.today().year + 1), description="Año:"),
	form.Textarea("direccion", vTexto, description = "Dirección:"),
	form.Radio("pago", ["Contrarembolso", "Transferencia bancaria", "Tarjeta de credito", "Paypal"], description="Formas de pago:", value = "Contrarembolso"),
	form.Button("Enviar datos", type="submit"),
	validators=[
		form.Validator("Fecha de nacimiento no válida.", lambda i: (((int(i.mes) == 2) and 
			((int(i.dia) <= 28) and ((int(i.anio) % 4) != 0) or (int(i.dia) <= 29) and ((int(i.anio) % 4) == 0))) or
			((int(i.dia) <= 31) and	((int(i.mes) == 1) or (int(i.mes) == 3) or (int(i.mes) == 7) or (int(i.mes) == 8) 
			or (int(i.mes) == 10) or (int(i.mes) == 12))) or 			
			((int(i.dia) <= 30) and	((int(i.mes) == 4) or (int(i.mes) == 6) or (int(i.mes) == 9) or (int(i.mes) == 11)))))
	]
) 

# Metodo que comprueba si existe un usuario en la base de datos
def existe_usuario(usuario):
	try:
		db = anydbm.open(usuario, 'r')
		usuario = db['usuario']
		db.close()
		return usuario
	except:
		return ""


# Metodo para obtener el password de un usuario
def comprueba_password(usuario):
	db = anydbm.open(usuario, 'r')
	password = db['password']
	db.close()
	return password

# Metodo para comprobar si hay un usuario logueado en la pagina ("" si no hay ninguno)
def comprueba_usuario(): 
	usuario = sesion.usuario
	return usuario              


# Clase para gestionar el formulario de registro
class registro:
	def GET(self):
		form = form_datos()
		return render.registro(form = form)
	
	def POST(self): 
		form = form_datos() 
        
		if not form.validates():
			return render.registro(form = form)
		else:
			existe = existe_usuario(form.d.usuario)
			usuario = form.d.usuario
	
			if existe:
				form = form_acceso()
				return render.login(form = form, mensaje = "Registro fallido. Ya existe el usuario '"+usuario+"'")
			else:			

				db = anydbm.open(form.d.usuario, 'c')
			
				db['usuario'] = form.d.usuario
				db['password'] = form.d.password
				db['nombre'] = form.d.nombre
				db['apellidos'] = form.d.apellidos
				db['correo'] = form.d.correo
				db['visa'] = form.d.visa
				db['dia'] = form.d.dia
				db['mes'] = form.d.mes
				db['anio'] = form.d.anio
				db['direccion'] = form.d.direccion
				db['pago'] = form.d.pago

				db.close()

				form = form_acceso()
				return render.login(form = form, mensaje = "Registro del usuario '"+usuario+"' realizado correctamente.")


# Clase para gestionar el login de usuario                     
class login:
	def POST(self):

		form = form_acceso()
		if not form.validates():
			return render.login(form = form)

		entrada = web.input()
		usuario = entrada.usuario
		password = entrada.password

		existe = existe_usuario(usuario)

		if existe:
			if password == comprueba_password(usuario):
				sesion.usuario = usuario
				return web.seeother('/')   # Redirige a inicio
			else:
				form = form_acceso()
				return render.login(form = form, mensaje = "Los datos introducidos no son correctos.")
		else:
			return render.login(form = form, mensaje = "El usuario introducido no existe.")

# Clase para gestionar el logout de usuario                     
class logout:
	def GET(self):
		usuario = sesion.usuario
		sesion.kill()
		return render.logout(usuario = usuario)


# Clase para gestionar la página de visualización de los datos de usuarios                     
class datos_usuario:
	def GET(self):
		usuario = comprueba_usuario() 

		if usuario:
			db = anydbm.open(usuario, 'r')

			nombre = db['nombre']
			apellidos = db['apellidos']
			correo = db['correo']
			visa = db['visa']
			fecha_nacimiento = db['dia']+'/'+db['mes']+'/'+db['anio']
			direccion = db['direccion']
			pago = db['pago']

			db.close()

			return render.datos_usuario(usuario = usuario, nombre = nombre, apellidos = apellidos, correo = correo, visa = visa, fecha_nacimiento = fecha_nacimiento, direccion = direccion, pago = pago, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de edición de datos de usuario
class modificar:
	def GET(self):
		usuario = comprueba_usuario() 

		db = anydbm.open(usuario, 'c')
			
		nombre = db['nombre']
		apellidos = db['apellidos']
		correo = db['correo']
		visa = db['visa']
		dia = db['dia']
		mes = db['mes']
		anio = db['anio']
		direccion = db['direccion']
		pago = db['pago']

		db.close()

		form = form_modificar()
		form.nombre.value = nombre
		form.apellidos.value = apellidos
		form.correo.value = correo
		form.visa.value = visa
		form.dia.value = dia
		form.mes.value = mes
		form.anio.value = anio
		form.direccion.value = direccion
		form.pago.value = pago

		return render.modificar(usuario = usuario, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3, form = form)

	def POST(self): 
		usuario = comprueba_usuario() 
		form = form_modificar() 
        
		if not form.validates():
			return render.modificar(usuario = usuario, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3, form = form)
		else:
			db = anydbm.open(usuario, 'w')
			
			db['nombre'] = form.d.nombre
			db['apellidos'] = form.d.apellidos
			db['correo'] = form.d.correo
			db['visa'] = form.d.visa
			db['dia'] = form.d.dia
			db['mes'] = form.d.mes
			db['anio'] = form.d.anio
			db['direccion'] = form.d.direccion
			db['pago'] = form.d.pago

			db.close()

			return web.seeother('/')


# Clase para gestionar la página principal
class inicio:
	def GET(self):
		usuario = comprueba_usuario() 

		if usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Inicio"
			return render.inicio(usuario = usuario, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias nacionales
class nacional:
	def GET(self):
		usuario = comprueba_usuario() 
		if usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Nacional"
			return render.nacional(usuario = usuario, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias internacionales
class internacional:
	def GET(self):
		usuario = comprueba_usuario() 
		if usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Internacional"
			return render.internacional(usuario = usuario, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias tecnologicas
class tecnologia:
	def GET(self):
		usuario = comprueba_usuario() 
		if usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Tecnologia"
			return render.tecnologia(usuario = usuario, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias deportivas
class deportes:
	def GET(self):
		usuario = comprueba_usuario() 
		if usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Deportes"
			return render.deportes(usuario = usuario, link1 = sesion.link1, link2 = sesion.link2, link3 = sesion.link3)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 



if __name__ == "__main__":
    app.run()	
