//**************************************************************************
// Práctica 4
// Texturas e iluminación con OpenGL. 
//
// German Martinez Maldonado
//
//**************************************************************************

#ifndef _OBJETOS
#define _OBJETOS

#include <stdlib.h>
#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include "materiales.hpp"

using namespace std;

typedef enum
{
   POINTS,
   EDGES,
   SOLID_CHESS,
   SOLID_NON_ILLUMINATED,
   POINTS_EDGES_SOLID_NON_ILLUMINATED,
   SOLID_MATERIAL_FLAT,     // prac. 4
   SOLID_MATERIAL_GOUROUD   // prac. 4
} 
   _draw_type ;


//*************************************************************************
//
// clase _object3D :
// ---------------------------- 
// objetos representados en memoria como una serie de puntos
//
//*************************************************************************

class _object3D
{
public:
			_object3D();
void 		_draw_points();

vector<_vertex3f> 	Vertices;

_vertex4f	Point_color;
float		Point_size;
};


//*************************************************************************
//
// clase _triangles_object3D :
// ---------------------------- 
// objetos representados en memoria como mallas de triangulos
//
//*************************************************************************

class _triangles_object3D: public _object3D
{
public:
		_triangles_object3D();
void		draw_edges();
void		draw_solid_chess();
void		draw_solid_non_illuminated();
void		draw_points_edges_solid_non_illuminated();
void  		draw_solid_material_flat(); // prac.4
void  		draw_solid_material_gouroud() ; // prac.4
void		draw(_draw_type Draw_type);

void		compute_faces_normals();
void 		compute_vertices_normals();

int 		create(vector<float> Vertices1,vector<int> Faces1);

vector<_vertex3i>	Faces_vertices;
vector<_vertex3f> 	Faces_normals;
vector<_vertex3f> 	Vertices_normals;
vector<_vertex2f> 	Vertices_tex_coords ; // prac.4
   
Material 		*material ; // prac.4
   
bool 		Faces_normals_computed;
bool 		Vertices_normals_computed;
bool		Vertices_tex_coords_computed; // prac.4

float		Line_width;

_vertex4f 	Line_color;
_vertex4f 	Solid_color;
_vertex4f 	Solid_chess_color1;
_vertex4f 	Solid_chess_color2;
};

//*************************************************************************
// clase _ply_triangles_object3D
//*************************************************************************

class _ply_triangles_object3D : public _triangles_object3D
{
   public:
   _ply_triangles_object3D( const std::string & nombreArchivo ) ;
};


//*************************************************************************
// clase _cube_object3D
//*************************************************************************

class _cube_object3D : public _triangles_object3D
{
   public:
   _cube_object3D( const std::string & nombreArchivo ) ;
};

#endif

