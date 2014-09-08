
#include <ctype.h>
#include <cmath>
#include <iostream>
#include <vector>

#include <GL/gl.h>
#include <GL/glut.h>

#include "jpg_imagen.hpp"
#include "materiales.hpp"
#include "objetos-4.hpp"
#include "esfera-mundo.hpp"

using namespace std;



//**********************************************************************
//
// Clase MatEsferaMundo
// -----------------------
// clase para el material de la esfera del mundo
//
//**********************************************************************

class MatEsferaMundo : public Material 
{ 
   public: 
   MatEsferaMundo() ; 
} ;

//----------------------------------------------------------------------

MatEsferaMundo::MatEsferaMundo()
{
   coloresCero() ; // no necesario?
   
   iluminacion    = true ;
   tex            = new Textura( "world1024x512.jpg" ) ;
   //tex            = new Textura( "rejilla.jpg" ) ;
   
   del.ambiente  = vectorRGB( 0.1,0.1,0.1 ) ;
   del.difusa    = vectorRGB( 0.8,0.8,0.9 ) ;
   del.especular = vectorRGB( 1.0,1.0,1.0 ) ;
   del.exp_brillo = 120.0f ;
   
   tra.difusa    = vectorRGB( 0.2,0.2,0.2 ) ;
   tra.especular = vectorRGB( 0.0,0.0,0.0 ) ;
   tra.exp_brillo = 60 ;
}

//**********************************************************************
//
// Clase EsferaMundo
//
//**********************************************************************

EsferaMundo::EsferaMundo()

:  _sup_par_triangles_object3D( 64, 64, FPEsfera() ) 
{
   material = new MatEsferaMundo() ;
}

//**********************************************************************
//
// Clase MatEsferaFacebook
// -----------------------
// clase para el material del cuerpo de la esfera 'facebook'
//
//**********************************************************************

class MatEsferaFacebook : public Material 
{ 
   public: 
   MatEsferaFacebook() ; 
} ;

//----------------------------------------------------------------------
// Constructor

MatEsferaFacebook::MatEsferaFacebook()
{
   iluminacion  = false ;
   color        = vectorRGB(1.0,1.0,1.0); 
   tex          = new Textura( "facebook-world-map-friendships.jpg" ) ;
}

//**********************************************************************
//
// Clase EsferaFacebook
//
//**********************************************************************

EsferaFacebook::EsferaFacebook()

:  _sup_par_triangles_object3D( 64, 64, FPEsfera() ) 
{
   material = new MatEsferaFacebook() ;
}




