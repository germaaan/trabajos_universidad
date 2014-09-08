//******************************************************************************
// class to read ply files of triangles
//
// Domingo Martín Perandres (c) 2003-2012
// Gnu Public Licence
//******************************************************************************

#ifndef _READ_PLY
#define _READ_PLY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <assert.h>

using namespace std;

namespace _file_ply
{


//**********************************************************************
//
// read: lee un archivo ply y lo carga en 'vertices' y 'faces'
//
// * 'nombreArchivo' no debe incluir la extensión .ply (se le añade antes de abrirlo)
// * si hay un error, aborta
// * elimina cualquier contenido previo en los vectores 'vertices' y 'faces'
// * lee el archivo .ply y lo carga en 'vertices' y 'faces'
// * solo admite plys con triángulos, 
// * no lee colores, coordenadas de textura, ni normales.

void read( const char * nombreArchivo, vector<float> &Vertices,vector<int> &Faces );
   
} ;

#endif // _READ_PLY
