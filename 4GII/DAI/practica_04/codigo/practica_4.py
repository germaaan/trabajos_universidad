#!/usr/bin/env python
# -*- coding: utf-8 -*-

import web
from web.contrib.template import render_mako
from web import form
import time
from datetime import date
import pymongo
import feedparser
import urllib
import tweepy
import sys
import traceback
from geopy.geocoders import GoogleV3

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
	'/modificar', 'modificar',
	'/RSS', 'rss',
	'/Charts', 'charts',
	'/Maps', 'maps',
	'/posicionamiento', 'posicionamiento',
	'/capas', 'capas',
	'/rutas', 'rutas',
	'/elevacion', 'elevacion',
	'/Twitter', 'twitter',
	'/usuario_twitter', 'usuario_twitter',
	'/palabra_twitter', 'palabra_twitter',
	'/lugar_twitter', 'lugar_twitter',
	'/prueba_tweet_geolocalizado', 'prueba_tweet_geolocalizado',
	'/maps_Twitter', 'maps_twitter'
)

app = web.application(urls, globals())

sesion = web.session.Session(app, web.session.DiskStore('sessions'), initializer={'usuario':'','link1':'','link2':'','link3':'','tuit':'','numero':''})

# Conexion a MongoDB
try:
    conn=pymongo.MongoClient()
    print "Conexión realizada con éxito."
except pymongo.errors.ConnectionFailure, e:
   print "No se pudo conectar a MongoDB: %s" % e 
conn

# Creamos la base de datos
db = conn.usuarios
db

# Creamos la colección para almacenar los documentos con los datos de los distintos usuarios
col = db.datos
col

print conn.database_names()
print db.collection_names()

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
vTexto = form.regexp(r"^[\w\s]+$", '* Campo vacío.')
vEmail = form.regexp(r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$", '* Correo electrónico no válido.')
vVISA = form.regexp(r"^([0-9]{4}) ([0-9]{4}) ([0-9]{4}) ([0-9]{4})$|^([0-9]{4})-([0-9]{4})-([0-9]{4})-([0-9]{4})$", '* Número tarjeta VISA no válido.')
vpass = form.regexp(r"\w{8,}$", '* Mínimo 8 caracteres.')

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

# Formulario de búsqueda de tweets de usuario
form_usuario = form.Form(
	form.Textbox("id", description = "Usuario:"),
	form.Dropdown("numero", range(1, 26), description = "Mostrar:"),
	form.Button("Buscar", type="submit"),
)

# Formulario de búsqueda de tweets por palabra
form_palabra = form.Form(
	form.Textbox("palabra", description = "Palabra:"),
	form.Dropdown("numero", range(1, 26), description = "Mostrar:"),
	form.Button("Buscar", type="submit"),
)

# Formulario de búsqueda de tweets por ubicacion
form_lugar = form.Form(
	form.Textbox("lugar", description = "Lugar:"),
	form.Dropdown("numero", range(1, 26), description = "Mostrar:"),
	form.Button("Buscar", type="submit"),
)

# Claves de consumo y tokens de acceso, utilizadas para OAuth
consumer_key = 'F2Tu7CwueK53njnwsw5RA'
consumer_secret = 'mGyAnHnoqzqy0wjyBIulOxNv0NFqFZsbNcq3crZaSso'
access_token = '527633518-oIjxGTGH2fKqIku6J2NJKzmFoL2cJMDBxUalMo6f'
access_token_secret = 'u3b8wOn6HdNpiZUsheLyDds8ZMr43QTIcZqb7fjbNIpxz'

# Proceso OAuth, utilizando las claves y tokens
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

# Creación de la interfaz, utilizando autenticación
api = tweepy.API(auth)


# Metodo que comprueba si existe un usuario en la base de datos
def existe_usuario(usuario):
	cursor = col.find({"usuario": usuario})
	return cursor.count()


# Metodo para obtener el password de un usuario
def comprueba_password(usuario):
	cursor = col.find({"usuario": usuario})
	password = cursor[0]["password"]
	return password           


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

			if existe > 1:
				form = form_acceso()
				return render.login(form = form, mensaje = "Registro fallido. Ya existe el usuario '"+usuario+"'")
			else:
				doc = { "usuario":form.d.usuario,
					"password":form.d.password,
					"nombre":form.d.nombre,
					"apellidos":form.d.apellidos,
					"correo":form.d.correo,
					"visa":form.d.visa,
					"dia":form.d.dia,
					"mes":form.d.mes,
					"anio":form.d.anio,
					"direccion":form.d.direccion,
					"pago":form.d.pago
				}

				visitas = { "clave":"visitas",
						"inicio":0,
						"nacional":0,
						"internacional":0,
						"tecnologia":0,
						"deportes":0,
						"rss":0,
						"charts":0,
						"maps":0,
						"twitter":0
				}

				col.insert(doc)
				col.insert(visitas)

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

		if existe == 0:
			return render.login(form = form, mensaje = "El usuario introducido no existe.")
		else:
			if password == comprueba_password(usuario):
				sesion.usuario = usuario
				return web.seeother('/')   # Redirige a inicio
			else:
				form = form_acceso()
				return render.login(form = form, mensaje = "Los datos introducidos no son correctos.")

# Clase para gestionar el logout de usuario                     
class logout:
	def GET(self):
		usuario = sesion.usuario
		sesion.kill()
		return render.logout(usuario = usuario)


# Clase para gestionar la página de visualización de los datos de usuarios                     
class datos_usuario:
	def GET(self):

		if sesion.usuario:
			cursor = col.find({"usuario": sesion.usuario})

			nombre = cursor[0]["nombre"]	
			apellidos = cursor[0]["apellidos"]
			correo = cursor[0]["correo"]	
			visa = cursor[0]["visa"]
			fecha_nacimiento = cursor[0]["dia"]+'/'+cursor[0]["mes"]+'/'+cursor[0]["anio"]
			direccion = cursor[0]["direccion"]
			pago = cursor[0]["pago"]

			return render.datos_usuario(nombre = nombre, apellidos = apellidos, correo = correo, visa = visa, fecha_nacimiento = fecha_nacimiento, direccion = direccion, pago = pago, sesion = sesion)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de edición de datos de usuario
class modificar:
	def GET(self):
		cursor = col.find({"usuario": sesion.usuario})

		nombre = cursor[0]["nombre"]	
		apellidos = cursor[0]["apellidos"]
		correo = cursor[0]["correo"]	
		visa = cursor[0]["visa"]
		dia = cursor[0]["dia"]
		mes = cursor[0]["mes"]
		anio = cursor[0]["anio"]
		direccion = cursor[0]["direccion"]
		pago = cursor[0]["pago"]

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

		return render.modificar(sesion = sesion, form = form)

	def POST(self): 
		form = form_modificar() 
        
		if not form.validates():
			return render.modificar(usuario = sesion.usuario, sesion = sesion, form = form)
		else:
			col.update({"usuario":usuario},{"$set":{
								"nombre":form.d.nombre,
								"apellidos":form.d.apellidos,
								"correo":form.d.correo,
								"visa":form.d.visa,
								"dia":form.d.dia,
								"mes":form.d.mes,
								"anio":form.d.anio,
								"fecha_nacimiento":form.d.dia+'/'+form.d.mes+'/'+form.d.anio,
								"direccion":form.d.direccion,
								"pago":form.d.pago,
								}})
			col.find_one({"usuario":sesion.usuario})

			return web.seeother('/')
			

# Clase para gestionar la página principal
class inicio:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Inicio"

			cursor = col.find({"clave":"visitas"})
			inicio = cursor[0]["inicio"]
			inicio += 1
			
			col.update({"clave":"visitas"},{"$set":{"inicio":inicio}})
			col.find_one({"clave":"visitas"})

			return render.inicio(sesion = sesion)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias nacionales
class nacional:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Nacional"

			cursor = col.find({"clave":"visitas"})
			nacional = cursor[0]["nacional"]
			nacional += 1
			
			col.update({"clave":"visitas"},{"$set":{"nacional":nacional}})
			col.find_one({"clave":"visitas"})

			return render.nacional(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias internacionales
class internacional:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Internacional"

			cursor = col.find({"clave":"visitas"})
			internacional = cursor[0]["internacional"]
			internacional += 1
			
			col.update({"clave":"visitas"},{"$set":{"internacional":internacional}})
			col.find_one({"clave":"visitas"})

			return render.internacional(sesion = sesion)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias tecnologicas
class tecnologia:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Tecnologia"

			cursor = col.find({"clave":"visitas"})
			tecnologia = cursor[0]["tecnologia"]
			tecnologia += 1
			
			col.update({"clave":"visitas"},{"$set":{"tecnologia":tecnologia}})
			col.find_one({"clave":"visitas"})

			return render.tecnologia(sesion = sesion)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de noticias deportivas
class deportes:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Deportes"

			cursor = col.find({"clave":"visitas"})
			deportes = cursor[0]["deportes"]
			deportes += 1
			
			col.update({"clave":"visitas"},{"$set":{"deportes":deportes}})
			col.find_one({"clave":"visitas"})

			return render.deportes(sesion = sesion)

		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de con las noticias obtenidas mediante RSS
class rss:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "RSS"

			cursor = col.find({"clave":"visitas"})
			rss = cursor[0]["rss"]
			rss += 1
			
			col.update({"clave":"visitas"},{"$set":{"rss":rss}})
			col.find_one({"clave":"visitas"})

			name = 'static/'+("http://ep00.epimg.net/rss/elpais/portada.xml").split('/')[-1]
			(filename, headers) = urllib.urlretrieve("http://ep00.epimg.net/rss/elpais/portada.xml", name)

			rss = feedparser.parse('static/portada.xml')
			return render.rss(sesion = sesion, rss = rss)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de Google Charts
class charts:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Charts"

			cursor = col.find({"clave":"visitas"})
			charts = cursor[0]["charts"]
			charts += 1
			
			col.update({"clave":"visitas"},{"$set":{"charts":charts}})
			col.find_one({"clave":"visitas"})

			return render.charts(sesion = sesion, cursor = cursor)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar las páginas de Google Maps
class maps:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Maps"

			cursor = col.find({"clave":"visitas"})
			maps = nombre = cursor[0]["maps"]
			maps += 1
			
			col.update({"clave":"visitas"},{"$set":{"maps":maps}})
			col.find_one({"clave":"visitas"})

			return render.maps(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar el mapa con el posicionamiento actual
class posicionamiento:
	def GET(self):
		if sesion.usuario:
			return render.posicionamiento(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar el mapa con diversas capas
class capas:
	def GET(self):
		if sesion.usuario:
			return render.capas(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar el mapa con uso del servicio de rutas
class rutas:
	def GET(self):
		if sesion.usuario:
			return render.rutas(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar el mapa con uso del servicio de elevacion
class elevacion:
	def GET(self):
		if sesion.usuario:
			return render.elevacion(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la página de Twitter
class twitter:
	def GET(self):
		if sesion.usuario:
			sesion.link3 = sesion.link2
			sesion.link2 = sesion.link1
			sesion.link1 = "Twitter"

			cursor = col.find({"clave":"visitas"})
			twitter = nombre = cursor[0]["twitter"]
			twitter += 1
			
			col.update({"clave":"visitas"},{"$set":{"twitter":twitter}})
			col.find_one({"clave":"visitas"})

			form = form_usuario()
			form2 = form_palabra()
			form3 = form_lugar()
			return render.twitter(mensaje = "", form = form, form2 = form2, form3 = form3, sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 
	

# Clase para gestionar la página de búsqueda de tweets por usuario
class usuario_twitter:
	def POST(self): 
		form = form_usuario()
		form2 = form_palabra()
		form3 = form_lugar()
        
		if not form.validates():
			return render.twitter(mensaje = "La busqueda solicitada de tweets de usuario no es correcta.", form = form, form2 = form2, form3 = form3, sesion = sesion)

		else:
			try:
				numero = form.d.numero
				timeline = api.user_timeline(screen_name = form.d.id, include_rts = True, result_type = "recent", count = numero)
				user = api.get_user(form.d.id)

				return render.usuario_twitter(sesion = sesion, timeline = timeline, user = user, numero = numero, api = api)				
			except:
				print "-" * 60
				print "Excepción en búsqueda de tweets por usuario: "
				traceback.print_exc(file=sys.stdout)
				print "-" * 60
				return render.twitter(mensaje = "No existen resultados para la busqueda solicitada de tweets de usuario.", form = form, form2 = form2, form3 = form3, sesion = sesion)	


# Clase para gestionar la página de búsqueda de tweets por usuario
class palabra_twitter:
	def POST(self): 
		form = form_usuario()
		form2 = form_palabra()
		form3 = form_lugar()
        
		if not form2.validates():
			return render.twitter(mensaje = "La busqueda solicitada de tweets por palabra no es correcta.", form = form, form2 = form2, form3 = form3, sesion = sesion)

		else:
			try:	
				palabra = form2.d.palabra
				numero = form2.d.numero
				timeline = api.search(q = palabra, result_type = "recent", count = numero)

				return render.palabra_twitter(sesion = sesion, timeline = timeline, palabra = palabra, numero = numero, api = api)				
			except:
				print "-" * 60
				print "Excepción en búsqueda de tweets por palabra: "
				traceback.print_exc(file=sys.stdout)
				print "-" * 60
				return render.twitter(mensaje = "No existen resultados para la busqueda solicitada de tweets por palabra.", form = form, form2 = form2, form3 = form3, sesion = sesion)	


# Clase para gestionar la página de búsqueda de tweets por lugar
class lugar_twitter:
	def POST(self): 
		form = form_usuario()
		form2 = form_palabra()
		form3 = form_lugar()
        
		if not form3.validates():
			return render.twitter(mensaje = "La busqueda solicitada de tweets por lugar no es correcta.", form = form, form2 = form2, form3 = form3, sesion = sesion)

		else:
			try:	
				lugar = form3.d.lugar
				numero = form3.d.numero
				geolocator = GoogleV3()

				address, (latitude, longitude) = geolocator.geocode(lugar)
				print address, latitude, longitude
				localizacion = str(latitude)+","+str(longitude)+",30km"
				print localizacion
				timeline = api.search(geocode = localizacion, count = numero)

				return render.lugar_twitter(sesion = sesion, timeline = timeline, lugar = lugar, numero = numero, api = api)				
			except:
				print "-" * 60
				print "Excepción en búsqueda de tweets por palabra: "
				traceback.print_exc(file=sys.stdout)
				print "-" * 60
				return render.twitter(mensaje = "No existen resultados para la busqueda solicitada de tweets por palabra.", form = form, form2 = form2, form3 = form3, sesion = sesion)	


# Clase para gestionar la página de prueba de tweet geolocalizado
class prueba_tweet_geolocalizado:
	def GET(self):
		if sesion.usuario:
			return render.prueba_tweet_geolocalizado(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


# Clase para gestionar la gestión de mapas personalizados para Twitter
class maps_twitter:
	def GET(self):
		if sesion.usuario:
			return render.maps_twitter(sesion = sesion)
		
		else:
			form = form_acceso()
			return render.login(form = form, mensaje = "Debe acceder con un usuario registrado.") 


if __name__ == "__main__":
    app.run()	
