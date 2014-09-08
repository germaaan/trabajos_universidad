
#include <ctype.h>
#include <cmath>
#include <iostream>
#include <vector>

#include <GL/gl.h>
#include <GL/glut.h>

#include "jpg_imagen.hpp"
#include "sbs_tetera.hpp"
#include "materiales.hpp"
#include "objetos-4.hpp"
#include "tetera.hpp"

using namespace std;

//**********************************************************************
// 
// Clase TexTetera
// ---------------
// clase para la textura de la tetera
// imagen disponible en:
// http://allroundnews.com/seamless-wood-textures-free-for-designers/seamless-wood-texture-free-74/
//
//**********************************************************************

class TexTetera : public Textura 
{ 
   public: 
   TexTetera() ; 
} ;

//----------------------------------------------------------------------
// Constructor

TexTetera::TexTetera()

//:  Textura("seamless-wood-texture-free-74.jpg" ) 
//   http://allroundnews.com/seamless-wood-textures-free-for-designers/seamless-wood-texture-free-74/
:  Textura("1280px-WoodDeck-4180.jpg")
// http://commons.wikimedia.org/wiki/File:WoodDeck-4180.jpg?uselang=ru
{
   // establecer modo de generación de coordenadas de objeto
   modo_gen_ct = mgct_coords_objeto ;
   
   // fijar parámetros para proyección vertical en el plano XZ
   // (los no asignados estan a cero)
   coefs_s[0] = 0.5 ; // hace s = x/2
   coefs_t[2] = 0.5 ; // hace t = z/2 
   
}

//**********************************************************************
//
// class MatTetera
// ---------------
// clase para el material de la tetera
//
//**********************************************************************

class MatTetera : public Material 
{ 
   public: MatTetera() ; 
} ;

//----------------------------------------------------------------------
// Constructor

MatTetera::MatTetera()
{
   coloresCero() ; // 
   
   color = vectorRGB(1.0,1.0,1.0);
   iluminacion    = true ;
   tex            = new TexTetera() ;

   del.difusa    = vectorRGB( 0.7,0.7,0.7 ) ;
   del.especular = vectorRGB( 1.0,1.0,1.0 ) ;
   del.exp_brillo = 50 ;
   
   tra.ambiente  = vectorRGB( 0.05,0.05,0.05 ) ;
   tra.difusa    = vectorRGB( 0.10,0.10,0.10 ) ;
   tra.especular = vectorRGB( 0.0,0.0,0.0 ) ;
   tra.exp_brillo = 50 ;
}

//**********************************************************************
//
// Clase Tetera
//
//**********************************************************************

//----------------------------------------------------------------------
// Constructor

Tetera::Tetera( unsigned long nu, unsigned long nv )
{
   // crear material
   Material *
      mat_tetera = new MatTetera() ;
   
   // crear superficies b-spline
   sbs::sup_bspline 
      * sbs_cuerpo = new sbs::sup_bspline() , 
      * sbs_boca   = new sbs::sup_bspline() , 
      * sbs_asa    = new sbs::sup_bspline() , 
      * sbs_tapa   = new sbs::sup_bspline() ;
      
   sbs::crea_cuerpo( sbs_cuerpo );
   sbs::crea_boca( sbs_boca );
   sbs::crea_asa( sbs_asa );
   sbs::crea_tapa( sbs_tapa );
   
   // crear mallas
   _sup_par_triangles_object3D 
      * cuerpo = new _sup_par_triangles_object3D( nu, nv, FPSupBSpline( sbs_cuerpo )),
      * boca   = new _sup_par_triangles_object3D( nu, nv, FPSupBSpline( sbs_boca   )),
      * asa    = new _sup_par_triangles_object3D( nu, nv, FPSupBSpline( sbs_asa    )),
      * tapa   = new _sup_par_triangles_object3D( nu, nv, FPSupBSpline( sbs_tapa   ));

   // asociar material a las mallas (ATENCION: se comparte el material)
   cuerpo->material = mat_tetera ;
   boca->material   = mat_tetera ;
   asa->material    = mat_tetera ;
   tapa->material   = mat_tetera ;
   
   // añadir mallas al objeto
   meshes.push_back( cuerpo );
   meshes.push_back( boca );
   meshes.push_back( asa );
   meshes.push_back( tapa );
   
   // inicializar factor de escala y desplz
   fesc = _vertex3f(0.3,0.3,0.3);
   despl = _vertex3f( 0.0,-0.35,0.0);
}

