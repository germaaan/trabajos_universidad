//**************************************************************************
// Práctica 3
// Visualización de modelos poligonales 
// Modelos PLY
//
// German Martinez Maldonado
//
//**************************************************************************

#include "objetos.h"
#include "file_ply_stl.h"

//*************************************************************************
// _object3D
//*************************************************************************

_object3D::_object3D()
{
	//Point_color=POINT_COLOR;
	Point_size=POINT_SIZE;
}

//*************************************************************************
//
//*************************************************************************

void _object3D::_draw_points()
{
int i;

	glDisable(GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	glPointSize(Point_size);
	glColor4fv(POINT_COLOR);

	for (i=0; i<Vertices.size(); i++){
		glBegin(GL_POINTS);
			glVertex3fv((GLfloat *) &Vertices[i]);
		glEnd();
	}
}

//*************************************************************************
// triangles
//*************************************************************************

_triangles_object3D::_triangles_object3D()
{
	Faces_normals_computed=false;
	Vertices_normals_computed=false;

	/*
	Line_color=LINE_COLOR;
	Solid_color=SOLID_COLOR;
	Solid_chess_color1=SOLID_CHESS_COLOR1;
	Solid_chess_color2=SOLID_CHESS_COLOR2;
	*/
}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::draw_edges()
{
int i;

	glDisable(GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(LINE_WIDTH);
	glColor4fv(LINE_COLOR);

	for (i=0;i<Faces_vertices.size();i++){
		glBegin(GL_LINE_LOOP);
				glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
				glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
				glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
		glEnd();
	}
}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::draw_solid_chess()
{
int i;

	glDisable(GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	for (i=0;i<Faces_vertices.size();i++){
		glBegin(GL_TRIANGLES);
			if (i%2==0)
				glColor4fv(SOLID_CHESS_COLOR1);
			else
				glColor4fv(SOLID_CHESS_COLOR2);

			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
		glEnd();
	}
}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::draw_solid_non_illuminated()
{
int i;

	glDisable(GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor4fv(SOLID_COLOR);

	for (i=0;i<Faces_vertices.size();i++){
		glBegin(GL_TRIANGLES);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._0]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._1]);
			glVertex3fv((GLfloat *) &Vertices[Faces_vertices[i]._2]);
		glEnd();
	}
}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::draw_solid_illuminated()
{

}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::draw_solid_illuminated_gouraud()
{

}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::draw_points_edges_solid_non_illuminated()
{
	_draw_points();
	draw_edges();
	draw_solid_non_illuminated();
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
		case SOLID_ILLUMINATED:draw_solid_illuminated();break;
		case SOLID_ILLUMINATED_GOURAUD:draw_solid_illuminated_gouraud();break;
		case SOLID_NON_ILLUMINATED:draw_solid_non_illuminated();break;
		case POINTS_EDGES_SOLID_NON_ILLUMINATED:draw_points_edges_solid_non_illuminated();
	}
}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::compute_faces_normals()
{
int i, normal;
vector<_vertex3f> calculos;

	if (!Faces_normals_computed){
		calculos.resize(Faces_vertices.size()*2);
		normal=0;

		// Calculo de vertices para la normal
		for (i=0;i<Faces_vertices.size();i++){
			calculos[normal]=Vertices[Faces_vertices[i].x]-Vertices[Faces_vertices[i].y];
			calculos[normal+1]=Vertices[Faces_vertices[i].z]-Vertices[Faces_vertices[i].y];
			normal+=2;
		}
		
		Faces_normals.resize(calculos.size()/2);
		normal=0;
		
		// Calculo de la normal del plano
		for (i=0;i<calculos.size();i+=2){
			//vx = v1y * v2z - v1z * v2y
			Faces_normals[normal]._0=(calculos[i]._1*calculos[i+1]._2)-(calculos[i]._2*calculos[i+1]._1);
			//vy = v1z * v2x - v1x * v2z
			Faces_normals[normal]._1=(calculos[i]._2*calculos[i+1]._0)-(calculos[i]._0*calculos[i+1]._2);
			//vz = v1x * v2y - v1y * v2x
			Faces_normals[normal]._2=(calculos[i]._0*calculos[i+1]._1)-(calculos[i]._1*calculos[i+1]._0);
			normal++;
		}

		Faces_normals_computed=true;
	}
}

//*************************************************************************
//
//*************************************************************************

void _triangles_object3D::compute_vertices_normals()
{
int i;
vector<int> contador;

	if (!Vertices_normals_computed){
	
		compute_faces_normals();

		Vertices_normals.resize(Faces_vertices.size());
		contador.resize(Faces_vertices.size());
		
		for (i=0;i<Faces_vertices.size();i++) {
			Vertices_normals[i].x=0;
			Vertices_normals[i].y=0;
			Vertices_normals[i].z=0;
			contador[i]=0;
		}

		// Calculo de las caras adyacentes
		for (i=0;i<Faces_vertices.size();i++){ 
			Vertices_normals[Faces_vertices[i]._0]+=Faces_normals[i];
			Vertices_normals[Faces_vertices[i]._1]+=Faces_normals[i];
			Vertices_normals[Faces_vertices[i]._2]+=Faces_normals[i];

			contador[Faces_vertices[i]._0]++;
			contador[Faces_vertices[i]._1]++;
			contador[Faces_vertices[i]._2]++;
		}

		// Promedio de las caras adyacentes
		for (i=0;i<Vertices_normals.size();i++){
			Vertices_normals[Faces_vertices[i]._0]/=contador[i];
			Vertices_normals[Faces_vertices[i]._1]/=contador[i];
			Vertices_normals[Faces_vertices[i]._2]/=contador[i];
		}
	
		Vertices_normals_computed=true;
	}
}

//*************************************************************************
//
//*************************************************************************

int _triangles_object3D::create(vector<float> Vertices1, vector<int> Faces1)
{
int i, vertice;

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
}

//*************************************************************************
// _ply_triangles_object3D
//*************************************************************************

_ply_triangles_object3D::_ply_triangles_object3D()
{ 
}
