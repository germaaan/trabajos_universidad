#ifndef OBJETOS_4_HPP
#define OBJETOS_4_HPP


//**********************************************************************

#include <string>
#include <vector>
#include "vertex.h"
#include "sbs_sbspline.hpp"
#include "objetos-3.h"



typedef _vertex2<double> vector2d ;
typedef _vertex3<double> vector3d ;
//typedef _vertex2<unsigned long> vector2ul ;
//typedef _vertex3<unsigned long> vector3ul ;

//**********************************************************************
// clase base para funciones de parametrización

class FunPar
{
   public:
   virtual void eval( double u, double v, vector3d &pos, vector3d &nor ) const = 0 ;
} ;

//**********************************************************************
// función de parametrización de un cuadrado de lado unidad

class FPCuadrado : public FunPar
{
   public:
   virtual void eval( double u, double v, vector3d &pos, vector3d &nor ) const ;
} ;

//**********************************************************************
// función de parametrización de una esfera

class FPEsfera : public FunPar
{
   public:
   virtual void eval( double u, double v, vector3d &pos, vector3d &nor ) const ;
} ;

//**********************************************************************
// función de parametrización del cilindro

class FPCilindro : public FunPar
{
   public:
   virtual void eval( double u, double v, vector3d &pos, vector3d &nor ) const ;
} ;

//**********************************************************************
// función de parametrización de un disco

class FPDisco : public FunPar
{
   public:
   virtual void eval( double u, double v, vector3d &pos, vector3d &nor ) const ;
} ;

//**********************************************************************
// función de parametrización de un cono

class FPCono : public FunPar
{
   public:
   virtual void eval( double u, double v, vector3d &pos, vector3d &nor ) const ;
} ;

//**********************************************************************
// función de parametrización de una superficie b-spline

class FPSupBSpline : public FunPar
{
   public:
   virtual void eval( double u, double v, vector3d &pos, vector3d &nor ) const ;
   FPSupBSpline( sbs::sup_bspline * p_sup_bsp );
   
   protected:
   sbs::sup_bspline * sup_bsp ;
} ;


//**********************************************************************
// Malla de triangulos construida usando una función de parametrizacion

class _sup_par_triangles_object3D : public _triangles_object3D
{  
   public:
   _sup_par_triangles_object3D( const unsigned long nu, const unsigned long nv, const FunPar & fp ) ;
} ;

//**********************************************************************
// objeto compuesto de múltiples mallas de triángulos, cada una con su
// material 

class _multiple_meshes
{
   public:
   
   _multiple_meshes() ;
   ~_multiple_meshes() ;

   void 	draw( _draw_type Draw_type );
   
   protected:
   std::vector<_triangles_object3D *> 
      meshes ;
   
   _vertex3f 
      fesc , // factores de escala
      despl ; // desplazamiento
} ;



#endif
