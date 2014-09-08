//**************************************************************************
// Práctica 3
// Visualización de modelos poligonales 
// Modelos PLY
//
// German Martinez Maldonado
//
//**************************************************************************

#ifndef _OBJETOS
#define _OBJETOS

#include <GL/glut.h>
#include <vector>
#include "vertex.h"

using namespace std;

typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID_NON_ILLUMINATED,SOLID_ILLUMINATED,SOLID_ILLUMINATED_GOURAUD,POINTS_EDGES_SOLID_NON_ILLUMINATED} _draw_type;

const float POINT_COLOR[4] 			= {1,0,0,1};	// ROJO
const float LINE_COLOR[4] 			= {0,1,0,1};	// VERDE
const float SOLID_COLOR[4] 			= {0,0,1,1};	// AZUL
const float SOLID_CHESS_COLOR1[4] 	= {1,1,0,1};	// AMARILLO
const float SOLID_CHESS_COLOR2[4] 	= {.5,.5,.5,1};	// GRIS

const float POINT_SIZE=2;
const float LINE_WIDTH=1;

//*************************************************************************
// OBJECT
//*************************************************************************

class _object3D
{
public:
			_object3D();
void 		_draw_points();

vector<_vertex3f> 	Vertices;

float		Point_size;
float 		Line_width;
};


//*************************************************************************
// TRIANGLE
//*************************************************************************

class _triangles_object3D: public _object3D
{
public:
			_triangles_object3D();
void		draw_edges();
void		draw_solid_chess();
void		draw_solid_non_illuminated();
void		draw_solid_illuminated();
void		draw_solid_illuminated_gouraud();
void		draw_points_edges_solid_non_illuminated();
void		draw(_draw_type Draw_type);

void		compute_faces_normals();
void 		compute_vertices_normals();

int 		create(vector<float> Vertices1,vector<int> Faces1);

vector<_vertex3i>	Faces_vertices;
vector<_vertex3f> 	Faces_normals;
vector<_vertex3f> 	Vertices_normals;

bool 		Faces_normals_computed;
bool 		Vertices_normals_computed;
};

//*************************************************************************
// PLY
//*************************************************************************

class _ply_triangles_object3D: public _triangles_object3D
{
public:
		_ply_triangles_object3D();
};

#endif
