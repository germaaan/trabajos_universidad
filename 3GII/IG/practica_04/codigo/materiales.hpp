#ifndef MATERIALES_HPP
#define MATERIALES_HPP

#include <string>
#include <vector>
#include <GL/gl.h>

#include "vertex.h"
#include "jpg_imagen.hpp"
#include "materiales.hpp"

typedef _vertex3<float> vectorRGB ;

class Material ;
class Textura  ;
   
//**********************************************************************
// posibles modos de generacion de coords. de textura

typedef enum 
{  mgct_desactivada,  
   mgct_coords_objeto, 
   mgct_coords_ojo 
} 
   ModoGenCT ;
   
//**********************************************************************
// extrae un puntero (GLfloat *) a un vectorRGB con tres valores reales

inline const GLfloat * dir( const vectorRGB & rgb )
{  return (const GLfloat *) &(rgb.r) ;
}

//**********************************************************************
// Estructura ColoresMat
// ---------------------
// estructura con las reflectividades o colores de un material (+exp.brillo)

struct ColoresMat
{
   _vertex3f
      emision,    // color de la emisividad del material
      ambiente,   // reflectividad para la componente ambiental (M_A)
      difusa,     // reflectividad para la componente difusa (M_D)
      especular ; // reflectividad para la componente especular (M_S)
   GLfloat
      exp_brillo ; // exponente de brillo especular
} ;

//**********************************************************************
// Clase Textura:
// ---------------
// clase que encapsula una imagen de textura de OpenGL, así como los
// parámetros relativos a como se aplica  a las primitivas que se dibujen
// mientras está activa

class Textura
{
   public:
   
   // carga una imagen de textura en la memoria de vídeo, e
   // inicializa los atributos de la textura a valores por defecto.
   Textura( const std::string & nombreArchivoJPG ) ;
   
   // libera la memoria dinámica usada por la textura, si hay alguna
   ~Textura() ; 
   
   // modifica el estado de OpenGL de forma que, a partir de la llamada,
   // se usará la textura en el cálculo del color de los pixels en los 
   // que se proyectan las primitivas que se dibujen
   void activar() ;
   
   protected: //----------------------------------------------------------
   
   GLuint 
      ident_textura ;// 'nombre' o identif. de textura para OpenGL
   jpg::Imagen *
      imagen ;       // objeto con los bytes de la imagen de textura
   ModoGenCT
      modo_gen_ct ;  // modo de generacion de coordenadas de textura
                     // (desactivadas si modo_gen_ct == mgct_desactivada)
   GLfloat
      coefs_s[4] ,   // si 'modo_gen_ct != desactivadas', coeficientes para la coord. S
      coefs_t[4] ;   // idem para coordenada T
} ;


//**********************************************************************
// Clase Material
// ---------------
// clase que encapsula los atributos de un material, incluyendo la
// textura del mismo. 

class Material
{
   public:
   
   // crea un material con un color plano blanco sin textura 
   // ni iluminación
   Material() ;     
   
   // crea un material con una textura asociada, y con la iluminación activada.
   // 'nombreArchivoJPG' nombre del archivo que contiene la imagen de text.
   Material( const std::string & nombreArchivoJPG ) ;
   
   // libera la memoria dinámica ocupada por el material
   ~Material() ;    
   
   // cambia el estado de OpenGL de forma que a partir de la llamada
   // se usaran los atributos de este material como valores de los parámetros
   // en la evaluación del MIL durante la visualización de primitivas
   void activar() ; 
  
    //--------------------------------------------------------
   
   void coloresCero();// pone todos los colores y reflectividades a cero
   
   bool 
      iluminacion ;  // true si el material requiere activar iluminación, 
                     // false si requiere desactivarla
   Textura *
      tex ;          // si !=NULL, el material tiene esta textura
   GLuint 
      ident_textura ;// identificador de textura, si tiene_textura=true
   _vertex3f
      color ;        // color del material cuando iluminacion=false 
   ColoresMat
      del,           // reflectividades de caras delanteras, si iluminacion= true
      tra ;          // reflectividades de caras traseras, si iluminacion=true
} ;

//**********************************************************************
// Clase FuenteLuz
// ---------------
// clase que contiene los atributo de una fuente de luz OpenGL

class FuenteLuz
{
   public:
   
   // inicializa la fuente de luz, indicando el indice de la misma, que
   // debe ser el valor de GL_LIGHT0 o GL_LIGHT1 o GL_LIGHT2 etc...
   //
   // p_ind_fuente == GL_LIGHT0, GL_LIGHT1, etc...
   // p_longi_ini == valor inicial del ángulo horizontal en grados
   // p_lati_ini  == idem del ángulo vértical
   // p_color     == color de la fuente de luz (amb, dif y spec )
   FuenteLuz( GLenum p_ind_fuente, GLfloat p_longi_ini, GLfloat p_lati_ini, const vectorRGB & p_color ) ; 
   
   // cambia el estado de OpenGL de forma que a partir de la llamada
   // se usará esta fuente de luz en los calculos del MIL
   // (en cada momento puede haber varias fuentes activadas)
   void activar() ;
   
   // cambia los atributos de la instancia en respuesta a una pulsación
   // de una tecla 'especial' (según la terminología de 'glut')
   bool gestionarEventoTeclaEspecial( int key ) ; 

   protected:
   
   GLenum
      ind_fuente ;// indice de la fuente de luz 
                  // (entre GL_LIGHT0 y GL_LIGHT0+máx.núm.fuentes)
   GLfloat 
      longi,      // longitud actual de la fuente direccional (entre 0 y 360)
      lati,       // latitud actual de la fuente direccional (entre -90 y 90)
      longi_ini,  // valor inicial de 'longi'
      lati_ini ;  // valor inicial de 'lati'
   _vertex3f
      col_ambiente,  // color de la fuente para la componente ambiental
      col_difuso,    // color de la fuente para la componente difusa
      col_especular; // color de la fuente para la componente especular
   
} ;


#endif
