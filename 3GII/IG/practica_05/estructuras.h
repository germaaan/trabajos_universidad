//**************************************************************************
// Estructuras para crear gruas
// 
// GPL
//**************************************************************************

#ifndef _ESTRUCTURAS
#define _ESTRUCTURAS

#include <vector>

#include <stdlib.h>
#include <GL/glut.h>

#define seccion 0.1 

//***********************************************************
//* PRIMITIVAS
//***********************************************************

void caja( float a, float b, float m);
/* 
	Construye un paralelepipedo alineado con los ejes de
	dimension a x b x m. El objeto se construye en el semiespacio y>=0, con el origen en el
    centro de la base. 
*/

void cilindro(float x0, float y0, float z0, 
		      float x1, float y1, float z1, 
		      float a);
/*
	Crea un cilindro con centro de las bases en
	x0,y0,z0 y x1,y1,z1, y radio de la base a.
*/

void cilindrof(float x0, float y0, float z0,
		       float x1, float y1, float z1,
		       float a, int n);
/**
	Crea un cilindro con centro de las bases en
	x0,y0,z0 y x1,y1,z1, y radio de la base a, 
	aproximado por n caras
**/


void cono(float x0, float y0, float z0, 
		  float x1, float y1, float z1, 
		  float a);
/*
	Crea un cono con centro de las bases en
	x0,y0,z0 y x1,y1,z1, y radio de la base a.
*/

void conof(float x0, float y0, float z0,
		   float x1, float y1, float z1,
		   float a, int n);
/**
	Crea un cono con centro de las bases en
	x0,y0,z0 y x1,y1,z1, y radio de la base a, 
	aproximado por n caras
**/

void paralelepipedo(float x0, float y0, float z0, 
	                float x1, float y1, float z1, 
					float a, float b);
/*
	Crea un paralelepipedo con centro de las bases en
	x0,y0,z0 y x1,y1,z1, y tamaño de la base axb.
*/


//***********************************************************
//* ELEMENTOS PARA CREAR GRUAS
//***********************************************************


void creaEstructura(float x0, float y0, float z0, 
		            float x1, float y1, float z1,
                    float a, float b, int n);
/*
	Crea un fragmento de estructura de una grua, con centro de las bases en
	x0,y0,z0 y x1,y1,z1. Las secciones de las bases tienen tamaño axb
	n es el numero de niveles que tiene la estructura.

	Los perfiles tienen seccion cuadrada, dada por el parametro seccion.
	Para crear la estructura se utiliza el procedimiento paralelepipedo.
*/

void creaBrazo(float x0, float y0, float z0, 
		       float x1, float y1, float z1, 
               float a, int n);
/*
	Crea un fragmento del brazo de una grua, con centro una de las aristas 
	de cada extremos en
	x0,y0,z0 y x1,y1,z1. Los lados de las bases tienen tamaño a,
	n es el numero de tramos.

	Los perfiles tienen seccion triangular
	Para crear la estructura se utiliza el procedimiento paralelepipedo.
*/

void creaTorre(float h, float a, float b, int n);
/**	
	Crea un fragmento de la terminacion de la estructura de una grua, 
	con centro de las bases en 0,0,0 y 0,h,0. Las secciones de las bases 
	tienen tamanyo axb y n es el numero de niveles que tiene la estructura.

	Los perfiles tienen seccion cuadrada, dada por el parametro seccion.
	Para crear la estructura se utiliza el procedimiento paralelepipedo.
**/

void creaGancho(float alto);
/**	
	Crea un gancho colgando del punto (0,0,0) de tamanyo alto
	El gancho siempre esta vertical
**/
	
#endif


