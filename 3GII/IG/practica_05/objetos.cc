//**************************************************************************
// Práctica 2
// Primitivas básicas para construir elementos sencillos que sirvan como 
// base para construir objetos más complejos por instanciación y jerarquías.
//
// Domingo Martin Perandres 2005-2012
// Pedro Cano Olivares 2012-2013
//          - Incluido estructuras y ejemplo de creacion de objeto jerárquico 
//          - Incluido control de animación
//
// GPL
//**************************************************************************

#include "objetos.h"
#include "estructuras.h"
#include "math.h"

#define amarillo 0
#define gris 1
#define rojo 2
#define	marron 3
#define celeste 4
#define marron2 5
#define verde 6
#define azul 7

/** Definicion de los colores usados.**/
float color[8][4]={{1,.8,.3,1.},{0.7,0.7,0.7,1},{1.0,0.0,0.0,1},
   		   {0.7,0.6,0.2,1},{0.2,1.0,1.0,1},{1.0,0.86,0.3,1},
		   {0.0,1.0,0.0,1.0}, {0.0,0.0,1.0,1.0}};


//*************************************************************************
// _object3D
//*************************************************************************
//*************************************************************************
//
//*************************************************************************

_object3D::_object3D()
{


Point_size=POINT_SIZE;
Line_width=LINE_WIDTH;
}

//*************************************************************************
//
//*************************************************************************

void _object3D::draw()
{

}


//*************************************************************************
// car
//*************************************************************************
//*************************************************************************
//
//*************************************************************************

_car::_car()
{
	giro_ruedas=0;
}

//*************************************************************************
//
//*************************************************************************

void _car::draw()
{
GLfloat Light_position[4]={5.0, 5.0, 10.0, 0.0};
GLfloat Ambient_component[4]={0.4,0.4,0.4,1};

glEnable(GL_CULL_FACE);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambient_component);
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);

glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();
glLightfv(GL_LIGHT0,GL_POSITION,Light_position);
glPopMatrix();
glShadeModel(GL_FLAT);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

glPushMatrix(); 
	glScalef(2,2,2);

	glPushMatrix();
	glScalef(1,.5,2);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[rojo]);
	caja(1,1,1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,.5,-.2);
	glScalef(.8,.5,.8);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[verde]);
	caja(1,1,1);
	glPopMatrix();

	// ahora las ruedas
	// delantera izquierda
	glPushMatrix();
	glTranslatef(.4,0,.65);
	glRotatef(giro_ruedas,0,1,0);
	glColor3f(0,0,1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[azul]);
	glRotatef(-90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// delantera derecha
	glPushMatrix();
	glTranslatef(-.4,0,.65);
	glRotatef(giro_ruedas,0,1,0);
	glColor3f(0,0,1);
	glRotatef(90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// trasera izquierda
	glPushMatrix();
	glTranslatef(.4,0,-.65);
	glColor3f(0,0,1);
	glRotatef(-90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// trasera derecha
	glPushMatrix();
	glTranslatef(-.4,0,-.65);
	glColor3f(0,0,1);
	glRotatef(90,0,0,1);
	cilindrof(0,0,0,0,.15,0,.2,10); 
	glPopMatrix();

	// ahora los focos
	glPushMatrix();
	glTranslatef(.35,.25,1.1);
	glRotatef(-90,1,0,0);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[amarillo]);
	conof(0,0,0,0,.25,0,.1,10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.35,.25,1.1);
	glRotatef(-90,1,0,0);
	glColor3f(0,1,1);
	conof(0,0,0,0,.25,0,.1,10);
	glPopMatrix();

glPopMatrix();
}

//*************************************************************************

void _car::ruedas_right()
{
	giro_ruedas-=1;
}

//*************************************************************************

void _car::ruedas_left()
{
	giro_ruedas+=1;
}

//*************************************************************************

void _car::ruedas_stop()
{
	giro_ruedas=0;
}

//*************************************************************************

void _car::control_animacion()
{
    if(giro_ruedas>30) giro_ruedas =30;
    if(giro_ruedas<-30) giro_ruedas = -30;
}




//*************************************************************************
// grua
//*************************************************************************
//*************************************************************************
//
//*************************************************************************

_grua::_grua()
{
	giro_estructura=0;
	movimiento_enganche=8.25;
	longitud_cable=1;
}

//*************************************************************************
//
//*************************************************************************

void _grua::draw()
{
GLfloat Light_position[4]={5.0, 5.0, 10.0, 0.0};
GLfloat Ambient_component[4]={0.4,0.4,0.4,1};

glEnable(GL_CULL_FACE);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,Ambient_component);
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);

glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glLoadIdentity();
glLightfv(GL_LIGHT0,GL_POSITION,Light_position);
glPopMatrix();
glShadeModel(GL_FLAT);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

glPushMatrix();
	glTranslatef(0,0,0);
	glScalef(1,1,1);

	// base
	glPushMatrix();
	glLoadName(1);
	glScalef(2,1,2);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[rojo]);
	caja(1,1,1);
	glPopMatrix();

	// estructura
	glPushMatrix();
	glLoadName(2);
	glTranslatef(0,1,0);
	glRotatef(giro_estructura,0,1,0);
	glScalef(0.75,1,0.75);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron]);
	creaEstructura(0,0,0,0,10,0,1,1,10);

		// apoyo_torre
		glPushMatrix();
		glLoadName(3);
		glTranslatef(0,10.05,0);
		glScalef(1.1,0.25,1.1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[azul]);
		caja(1,1,1);
		glPopMatrix();

		// torre
		glPushMatrix();
		glLoadName(4);
		glTranslatef(0,10.35,0);
		glScalef(1,0.25,1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron]);
		creaTorre(10,1,1,10);
		glPopMatrix();

		// soporte_contrapeso
		glPushMatrix();
		glLoadName(5);
		glTranslatef(-3.35,10.2,0);
		glRotatef(-90,0,0,1);
		glScalef(0.1,0.275,1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron]);
		creaEstructura(0,0,0,0,10,0,1,1,10);
		glPopMatrix();

		// contrapeso
		glPushMatrix();
		glLoadName(6);
		glTranslatef(-2.65,9.65,0);
		glScalef(1.25,0.5,1);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[gris]);
		caja(1,1,1);
		glPopMatrix();

		// brazo_gancho
		glPushMatrix();		
		glLoadName(7);
		glTranslatef(8.6,10,0);
		glRotatef(-90,0,0,1);
		glRotatef(180,1,0,0);
		glScalef(0.5,1,0.5);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[marron]);
		creaBrazo(0,0,0,0,8,0,1,8);
		glPopMatrix();

		// enganche
		glPushMatrix();
		glLoadName(8);
		glTranslatef(movimiento_enganche,9.85,0);
		glScalef(0.75,0.25,0.75);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[azul]);
		caja(1,0.5,1);

			// cable
			glPushMatrix();
			glLoadName(9);
			glRotatef(180,1,0,0);
			glScalef(0.5,longitud_cable,0.5);
			glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[rojo]);
			cilindro(0,0,0,0,5,0,0.1);
			glPopMatrix();
			
			// gancho
			glPushMatrix();
			glLoadName(10);
			glTranslatef(0,longitud_cable-(6*longitud_cable),0);
			glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[gris]);
			creaGancho(2.0);
			glPopMatrix();

		glPopMatrix();
		
		// cable_enganche_1
		glPushMatrix();
		glLoadName(11);
		glTranslatef(6.5,10.4,0);
		glRotatef(70,0,0,1);
		glScalef(0.5,1,0.5);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[rojo]);
		cilindro(0,0,0,0,7,0,0.1);
		glPopMatrix();
		
		// cable_enganche_2
		glPushMatrix();
		glLoadName(12);
		glTranslatef(-2.5,10.3,0);
		glRotatef(-45,0,0,1);
		glScalef(0.5,1,0.5);
		glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,color[rojo]);
		cilindro(0,0,0,0,3.6,0,0.1);
		glPopMatrix();

	glPopMatrix();

glPopMatrix();
}

//*************************************************************************

void _grua::control_animacion(int velocidad_estructura, int velocidad_enganche, int velocidad_cable)
{
	if (velocidad_estructura>5)
		giro_estructura-=1*5;
	else if (velocidad_estructura<-5)
		giro_estructura-=1*-5;
	else
		giro_estructura-=1*velocidad_estructura;
	
	if (movimiento_enganche<8.25 || movimiento_enganche>1){
		if (velocidad_enganche>5)
			movimiento_enganche-=0.05*5;
		else if (velocidad_enganche<-5)
			movimiento_enganche-=0.05*-5;
		else
			movimiento_enganche-=0.05*velocidad_enganche;
	}

	if (movimiento_enganche<=1)
		movimiento_enganche=1.001;
	else if (movimiento_enganche>=8.25)
		movimiento_enganche=8.249;

	if (longitud_cable<8 || longitud_cable>1){
		if (velocidad_cable>5)
			longitud_cable-=0.05*5;
		else if (velocidad_cable<-5)
			longitud_cable-=0.05*-5;
		else
			longitud_cable-=0.05*velocidad_cable;
	}

	if (longitud_cable<=1)
		longitud_cable=1.001;
	else if (longitud_cable>=8)
		longitud_cable=7.999;
}
