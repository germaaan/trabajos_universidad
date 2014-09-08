//**************************************************************************
// Práctica 4
// Texturas e iluminación con OpenGL.
//
// German Martinez Maldonado
//
//**************************************************************************

#include "file_ply_stl.hpp"
#include "objetos-3.h" 


//*************************************************************************
// _object3D
//*************************************************************************
//*************************************************************************
//
//*************************************************************************

_object3D::_object3D()
{
	// Color de punto: rojo  
	Point_color.x = 1;
	Point_color.y = 0;
	Point_color.z = 0;
	Point_color.w = 1;
      
	Point_size = 2;
}



//*************************************************************************
//
//*************************************************************************

void _object3D::_draw_points()
{
unsigned int i;

	glDisable(GL_LIGHTING);
	glDisable(GL_NORMALIZE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glPointSize(Point_size);
	glColor4fv((GLfloat *) &Point_color);

	glBegin(GL_POINTS);
		for (i=0; i<Vertices.size(); i++)
			glVertex3fv((GLfloat *) &Vertices[i]);
	glEnd();
}

//*************************************************************************
// _triangles_object3D
//*************************************************************************
 

_triangles_object3D::_triangles_object3D()
{
	Faces_normals_computed=false;
	Vertices_normals_computed=false;
	Vertices_tex_coords_computed=false;
	material = NULL ;

	Line_width = 1;

	// Color de linea: verde  
	Line_color.x = 0;
	Line_color.y = 1;
	Line_color.z = 0;
	Line_color.w = 1;

	// Color de solido: azul
	Solid_color.x = 0;         
	Solid_color.y = 0;
	Solid_color.z = 1;
	Solid_color.w = 1;

	// Color de ajedrez 1: amarillo
	Solid_chess_color1.x = 1;         
	Solid_chess_color1.y = 1;
	Solid_chess_color1.z = 0;
	Solid_chess_color1.w = 1;

	// Color de ajedrez 2: gris
	Solid_chess_color2.x = 0.5;         
	Solid_chess_color2.y = 0.5;
	Solid_chess_color2.z = 0.5;
	Solid_chess_color2.w = 1;
}

//*************************************************************************
// Dibuja las aristas de los triangulos no iluminados
//*************************************************************************

void _triangles_object3D::draw_edges()
{
unsigned int i;

	glDisable(GL_LIGHTING);
    glDisable(GL_NORMALIZE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(Line_width);
	glColor4fv((GLfloat *) &Line_color);

	glBegin(GL_LINE_LOOP);
		for (i=0;i<Faces_vertices.size();i++){
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
		}
	glEnd();
}

//*************************************************************************
// Dibuja triangulos no iluminados con apariencia de ajedrez
//*************************************************************************

void _triangles_object3D::draw_solid_chess()
{
unsigned int i;

	glDisable(GL_LIGHTING);
    glDisable(GL_NORMALIZE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glBegin(GL_TRIANGLES);
		for (i=0;i<Faces_vertices.size();i++){
			if (i%2==0)
				glColor4fv((GLfloat *) &Solid_chess_color1);
			else
				glColor4fv((GLfloat *) &Solid_chess_color2);

			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
		}
	glEnd();
}

//*************************************************************************
// Dibuja triangulos no iluminados
//*************************************************************************

void _triangles_object3D::draw_solid_non_illuminated()
{
unsigned int i;

	glDisable(GL_LIGHTING);
    glDisable(GL_NORMALIZE);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor4fv((GLfloat *) &Solid_color);

	glBegin(GL_TRIANGLES);
		for (i=0;i<Faces_vertices.size();i++){
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
		}
	glEnd();
}



//*************************************************************************
// Dibuja puntos, aristas y caras a la vez
//*************************************************************************

void _triangles_object3D::draw_points_edges_solid_non_illuminated()
{
	_draw_points();
	draw_edges();
	draw_solid_non_illuminated();
}
//**********************************************************************





//**********************************************************************


void _triangles_object3D::draw_solid_material_gouroud(){
unsigned int i;

	compute_vertices_normals();

	glShadeModel(GL_SMOOTH);
	
	material->activar();
	
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_NORMALIZE);
	
	glBegin(GL_TRIANGLES);
	for (i=0;i<Faces_vertices.size();i++){
			glNormal3fv((GLfloat *) &Vertices_normals[Faces_vertices[i]._0]);
            glTexCoord2f(Vertices_tex_coords[Faces_vertices[i]._0]._0, Vertices_tex_coords[Faces_vertices[i]._0]._1);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
			
			glNormal3fv((GLfloat *) &Vertices_normals[Faces_vertices[i]._1]);
            glTexCoord2f(Vertices_tex_coords[Faces_vertices[i]._1]._0, Vertices_tex_coords[Faces_vertices[i]._1]._1);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
			
			glNormal3fv((GLfloat *) &Vertices_normals[Faces_vertices[i]._2]);
            glTexCoord2f(Vertices_tex_coords[Faces_vertices[i]._2]._0, Vertices_tex_coords[Faces_vertices[i]._2]._1);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
	}
	glEnd();
}

void _triangles_object3D::draw_solid_material_flat(){
unsigned int i;

	compute_faces_normals();

	glShadeModel(GL_FLAT);
	
	material->activar();
	
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glEnable(GL_NORMALIZE);
	
	glBegin(GL_TRIANGLES);
		for (i=0;i<Faces_vertices.size();i++){
			glNormal3fv((GLfloat *) &Faces_normals[i]);
			
            glTexCoord2f(Vertices_tex_coords[Faces_vertices[i]._0]._0, Vertices_tex_coords[Faces_vertices[i]._0]._1);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
			
            glTexCoord2f(Vertices_tex_coords[Faces_vertices[i]._1]._0, Vertices_tex_coords[Faces_vertices[i]._1]._1);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
			
            glTexCoord2f(Vertices_tex_coords[Faces_vertices[i]._2]._0, Vertices_tex_coords[Faces_vertices[i]._2]._1);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
		}
	glEnd();
}


//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::draw(_draw_type Draw_type)
{
	switch (Draw_type){
		case POINTS:_draw_points();break;
		case EDGES:draw_edges();break;
		case SOLID_CHESS:draw_solid_chess();break;
		case SOLID_NON_ILLUMINATED:draw_solid_non_illuminated();break;
		case POINTS_EDGES_SOLID_NON_ILLUMINATED:draw_points_edges_solid_non_illuminated();
		case SOLID_MATERIAL_FLAT:draw_solid_material_flat();break;
		case SOLID_MATERIAL_GOUROUD:draw_solid_material_gouroud();break;
	}
}

//*************************************************************************
// calcula las normales de las caras
//*************************************************************************

void _triangles_object3D::compute_faces_normals()
{
unsigned int i;
vector<_vertex3f> vertices1,vertices2;

	if (!Faces_normals_computed){

		vertices1.resize(Faces_vertices.size());
		vertices2.resize(Faces_vertices.size());
		Faces_normals.resize(Faces_vertices.size());

		// Calculo de vertices para la normal
		for (i=0; i<Faces_vertices.size();i++){
			vertices1[i].x = Vertices[Faces_vertices[i]._1].x - Vertices[Faces_vertices[i]._0].x;
			vertices1[i].y = Vertices[Faces_vertices[i]._1].y - Vertices[Faces_vertices[i]._0].y;
			vertices1[i].z = Vertices[Faces_vertices[i]._1].z - Vertices[Faces_vertices[i]._0].z; 

			vertices2[i].x = Vertices[Faces_vertices[i]._2].x - Vertices[Faces_vertices[i]._0].x;
			vertices2[i].y = Vertices[Faces_vertices[i]._2].y - Vertices[Faces_vertices[i]._0].y;
			vertices2[i].z = Vertices[Faces_vertices[i]._2].z - Vertices[Faces_vertices[i]._0].z; 
		}
		
		// Calculo de la normal del plano
		for(i=0;i<vertices1.size();i++)
			Faces_normals[i] = vertices1[i].cross_product(vertices2[i]);

		Faces_normals_computed=true;
	}
}


//*************************************************************************
// Calcular normales de vértices,
//
//*************************************************************************

void _triangles_object3D::compute_vertices_normals()
{
unsigned int i;
vector<int> contador;

Vertices_normals.resize(Faces_vertices.size());	
contador.resize(Faces_vertices.size());

	if (!Vertices_normals_computed){
	
		compute_faces_normals();

		for (i = 0; i < Vertices.size(); i++)
			contador[i]=0;

		for (i = 0; i < Faces_vertices.size(); i++){
			Vertices_normals[i].x = 0;
			Vertices_normals[i].y = 0;
			Vertices_normals[i].z = 0;
		}

		// Calculo de las caras adyacentes
		for (i = 0; i < Faces_normals.size(); i++){ 
			Vertices_normals[Faces_vertices[i]._0].x += Faces_normals[i].x;
			Vertices_normals[Faces_vertices[i]._0].y += Faces_normals[i].y;
			Vertices_normals[Faces_vertices[i]._0].z += Faces_normals[i].z;
			Vertices_normals[Faces_vertices[i]._1].x += Faces_normals[i].x;
			Vertices_normals[Faces_vertices[i]._1].y += Faces_normals[i].y;
			Vertices_normals[Faces_vertices[i]._1].z += Faces_normals[i].z;
			Vertices_normals[Faces_vertices[i]._2].x += Faces_normals[i].x;
			Vertices_normals[Faces_vertices[i]._2].y += Faces_normals[i].y;
			Vertices_normals[Faces_vertices[i]._2].z += Faces_normals[i].z;

			contador[Faces_vertices[i]._0]++;
			contador[Faces_vertices[i]._1]++;
			contador[Faces_vertices[i]._2]++;
		}

		// Promedio de las caras adyacentes
		for (i = 0; i < Vertices_normals.size(); i++){
			Vertices_normals[i] /= contador[i];
			Vertices_normals[i].normalize();
		}
	
		Vertices_normals_computed=true;
	}
}

//----------------------------------------------------------------------

int _triangles_object3D::create(vector<float> Vertices1, vector<int> Faces1)
{
unsigned int i, vertice;
_vertex2f coord;	

	// VERTICES
	Vertices.resize(Vertices1.size()/3);
	vertice=0;

	for (i=0;i<Vertices1.size();i+=3){
		Vertices[vertice].x=Vertices1[i];
		Vertices[vertice].y=Vertices1[i+1];
		Vertices[vertice].z=Vertices1[i+2];
		vertice++;
	}

	// TRIANGULOS
	Faces_vertices.resize(Faces1.size()/3);
	vertice=0;

	for (i=0;i<Faces1.size();i+=3){
		Faces_vertices[vertice]._0=Faces1[i];
		Faces_vertices[vertice]._1=Faces1[i+1];
		Faces_vertices[vertice]._2=Faces1[i+2];
		vertice++;
	}
	
	// COORDENADAS VERTICES
	for (i=0;i<Vertices.size();i+=4){
		coord.x=0;
		coord.y=1;
		Vertices_tex_coords.push_back(coord);

		coord.x=0;
		coord.y=0;
		Vertices_tex_coords.push_back(coord);

		coord.x=1;
		coord.y=0;
		Vertices_tex_coords.push_back(coord);

		coord.x=1;
		coord.y=1;
		Vertices_tex_coords.push_back(coord);
	}
	
	Vertices_tex_coords_computed = true;
	
	return 0;
}

//**********************************************************************
// clase _ply_triangles_object3D

_ply_triangles_object3D::_ply_triangles_object3D( const std::string & nombreArchivo ) 
{
   vector<float> vertices;
   vector<int> faces;

   _file_ply::read(nombreArchivo.c_str(),vertices,faces);
   create(vertices,faces);
}

//*************************************************************************
// clase _cube_object3D
//*************************************************************************

_cube_object3D::_cube_object3D( const std::string & nombreArchivo ) {
_vertex2f coord;	

	// VERTICES
	Vertices.resize(8);
	Vertices[0].x=-0.5;	Vertices[0].y=-0.5;	Vertices[0].z=-0.5;
	Vertices[1].x=0.5;	Vertices[1].y=-0.5;	Vertices[1].z=-0.5;
	Vertices[2].x=0.5;	Vertices[2].y=0.5;	Vertices[2].z=-0.5;
	Vertices[3].x=-0.5;	Vertices[3].y=0.5;	Vertices[3].z=-0.5;
	Vertices[4].x=-0.5;	Vertices[4].y=-0.5;	Vertices[4].z=0.5;
	Vertices[5].x=0.5;	Vertices[5].y=-0.5;	Vertices[5].z=0.5;
	Vertices[6].x=0.5;	Vertices[6].y=0.5;	Vertices[6].z=0.5;
	Vertices[7].x=-0.5;	Vertices[7].y=0.5;	Vertices[7].z=0.5;

	// TRIANGULOS
	Faces_vertices.resize(12);
	// TRASERA
	Faces_vertices[0]._0=0; Faces_vertices[0]._1=2; Faces_vertices[0]._2=1;
	Faces_vertices[1]._0=0;	Faces_vertices[1]._1=3;	Faces_vertices[1]._2=2;
	// DERECHA
	Faces_vertices[2]._0=1;	Faces_vertices[2]._1=2;	Faces_vertices[2]._2=6;
	Faces_vertices[3]._0=6;	Faces_vertices[3]._1=5;	Faces_vertices[3]._2=1;
	// FRONTAL
	Faces_vertices[4]._0=4; Faces_vertices[4]._1=5;	Faces_vertices[4]._2=6;
	Faces_vertices[5]._0=6;	Faces_vertices[5]._1=7;	Faces_vertices[5]._2=4;
	// SUPERIOR
	Faces_vertices[6]._0=2;	Faces_vertices[6]._1=3;	Faces_vertices[6]._2=6;
	Faces_vertices[7]._0=6;	Faces_vertices[7]._1=3;	Faces_vertices[7]._2=7;
	// IZQUIERDA
	Faces_vertices[8]._0=0;	Faces_vertices[8]._1=7;	Faces_vertices[8]._2=3;
	Faces_vertices[9]._0=0;	Faces_vertices[9]._1=4;	Faces_vertices[9]._2=7;
	// INFERIOR
	Faces_vertices[10]._0=0; Faces_vertices[10]._1=1; Faces_vertices[10]._2=5;
	Faces_vertices[11]._0=0; Faces_vertices[11]._1=5; Faces_vertices[11]._2=4;

	// COORDENADAS VERTICES
	// VERTICE 0
	coord.x=0;
	coord.y=1;
	Vertices_tex_coords.push_back(coord);
	// VERTICE 1
	coord.x=0;
	coord.y=0;
	Vertices_tex_coords.push_back(coord);
	// VERTICE 2
	coord.x=1;
	coord.y=0;
	Vertices_tex_coords.push_back(coord);
	// VERTICE 3
	coord.x=1;
	coord.y=1;
	Vertices_tex_coords.push_back(coord);
	// VERTICE 4
	coord.x=0;
	coord.y=1;
	Vertices_tex_coords.push_back(coord);
	// VERTICE 5
	coord.x=0;
	coord.y=0;
	Vertices_tex_coords.push_back(coord);
	// VERTICE 6
	coord.x=1;
	coord.y=0;
	Vertices_tex_coords.push_back(coord);
	// VERTICE 7
	coord.x=1;
	coord.y=1;
	Vertices_tex_coords.push_back(coord);
	
	Vertices_tex_coords_computed = true;
   
	material = new Material(nombreArchivo);
	material->iluminacion=true;
}
