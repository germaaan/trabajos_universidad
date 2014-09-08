//**************************************************************************
// Práctica 2
// Ejemplo de creacion de un coche a partir de objetos simples y transformaciones. 
// Ejemplo de creación de modelos jerárquicos
//
// Domingo Martin Perandres 2005-2012
// Pedro Cano Olivares 2012
// GPL
//**************************************************************************

#ifndef _OBJETOS
#define _OBJETOS


#include <stdlib.h>
#include <GL/glut.h>

using namespace std;


const float POINT_SIZE=3;
const float LINE_WIDTH=1;

//*************************************************************************
//
//*************************************************************************

class _object3D
{
public:

			_object3D();
void 	draw();

float Point_size;
float Line_width;
};


//*************************************************************************
// COCHE
//*************************************************************************

class _car: public _object3D
{
public:

	_car();
    void draw();

	void ruedas_right();
	void ruedas_left();
	void ruedas_stop();
    void control_animacion();
	
    // Parámetros de construcción
	float giro_ruedas;

};




//*************************************************************************
// GRUA
//*************************************************************************

class _grua: public _object3D
{
public:

	_grua();
    void draw();

    void control_animacion(int velocidad_estructura, int velocidad_enganche, int velocidad_cable); 	

    // Parámetros de construcción
	float giro_estructura;
	float movimiento_enganche;
	float longitud_cable;
};	
#endif


