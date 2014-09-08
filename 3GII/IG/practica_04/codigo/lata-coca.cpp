
#include <ctype.h>
#include <cmath>
#include <iostream>
#include <vector>

#include <GL/gl.h>
#include <GL/glut.h>

#include "jpg_imagen.hpp"
#include "materiales.hpp"
#include "objetos-4.hpp"
#include "lata-coca.hpp"

using namespace std;


const float radio = 0.33f ; // radio de la lata (del disco de la tapa) 

//**********************************************************************
//
// Clase MCuerpoLata
// ----------------
// clase para el material del cuerpo de una lata de coca-cola
//
//**********************************************************************

class MCuerpoLata : public Material 
{ 
   public: 
   MCuerpoLata() ; 
} ;

//----------------------------------------------------------------------

MCuerpoLata::MCuerpoLata()
{
   coloresCero() ;
   
   iluminacion    = true ;
   tex            = new Textura( "lata-coke.jpg" ) ;
   
   del.difusa     = vectorRGB( 0.7,0.7,0.7 ) ;
   del.especular  = vectorRGB( 1.0,1.0,1.0 ) ;
   del.exp_brillo = 30 ;
   
   tra.difusa     = vectorRGB( 0.2,0.2,0.2 ) ;
   tra.especular  = vectorRGB( 0.0,0.0,0.0 ) ;
   tra.exp_brillo = 20 ;
}


//**********************************************************************
//
// Clase TexTapaLata
// ----------------
// clase para la textura de la tapa de la lata de coca-cola
//
//**********************************************************************

class TexTapaLata : public Textura
{ 
   public: 
   TexTapaLata() ; 
} ;

//----------------------------------------------------------------------

TexTapaLata::TexTapaLata() 

:  Textura("can-top.jpg")
{
   // activar generacion de coords. de textura en modo objeto
   // (proyeccion en el plano XZ)
   
   modo_gen_ct = mgct_coords_objeto ;
   
   coefs_s[0] = 0.5f ;
   coefs_s[3] = 0.5f ;
   
   coefs_t[2] = 0.5f  ;
   coefs_t[3] = 0.5f ;
}

//**********************************************************************
//
// Clase MTapaLata
// ----------------
// clase para el material de la tapa de la lata de coca-cola
//
//**********************************************************************

class MTapaLata : public Material 
{ 
   public: 
   MTapaLata() ; 
} ;

//----------------------------------------------------------------------

MTapaLata::MTapaLata()
{
   coloresCero() ; 

   iluminacion    = true ;
   tex            = new TexTapaLata() ;
   
   del.difusa    = vectorRGB( 1.0,1.0,1.0 ) ;
   del.especular = vectorRGB( 2.0,2.0,2.0 ) ;
   del.exp_brillo = 30 ;
   
   tra.difusa    = vectorRGB( 0.2,0.2,0.2 ) ;
   tra.especular = vectorRGB( 0.0,0.0,0.0 ) ;
   tra.exp_brillo = 20 ;
}

//**********************************************************************
// clase LataCocaCola
//
//**********************************************************************

//----------------------------------------------------------------------
// Constructor: crea mallas y materiales para cilindro y tapa

LataCocaCola::LataCocaCola()
{
   // crear mallas y materiales
   _sup_par_triangles_object3D 
      * malla_cilindro = new _sup_par_triangles_object3D( 64, 64, FPCilindro() ),
      * malla_tapa     = new _sup_par_triangles_object3D( 64, 64, FPDisco() );
   Material
      * mat_cilindro = new MCuerpoLata(),
      * mat_tapa     = new MTapaLata() ;

   // asociar materiales a las mallas
   malla_cilindro->material = mat_cilindro ;
   malla_tapa->material = mat_tapa ;

   // insertar mallas en el vector de mallas
   meshes.push_back( malla_cilindro );
   meshes.push_back( malla_tapa );
   
   // cambiar posicion
   fesc  = _vertex3f(radio,1.0,radio);
   despl = _vertex3f(0.0,-0.5,0.0);
   
   // desplazar en Y malla de la tapa
   std::vector<_vertex3f> & v = malla_tapa->Vertices ;
   for( unsigned long i = 0 ; i < v.size() ; i++ )
      v[i].y += 1.0f ;
}




