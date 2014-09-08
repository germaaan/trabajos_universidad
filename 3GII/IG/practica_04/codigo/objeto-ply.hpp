#ifndef OBJETO_PLY_HPP
#define OBJETO_PLY_HPP

#include "objetos-3.h"




//**********************************************************************
//
// Clase ObjetoPLY
// -------------
// Clase para gestionar el cambio por teclado de los parámetros del 
// material de un objeto PLY
//
//**********************************************************************

class ObjetoPLY : public _ply_triangles_object3D
{
   public:
   
   ObjetoPLY(  const std::string & p_nom_fich_ply , const std::string & p_nom_fich_jpg ) ;
   
   // atributos del material que se pueden cambiar por teclado
   float 
      refl_amb, // reflectividad de la componente ambiental
      refl_dif,  // reflectividad de la componente difusa
      refl_esp,  // reflectividad de la componente especular
      exp_brillo ; // exponente de brillo
   
   // actualiza el material de _ply_triangles_object3D con los valores de arriba
   void actualizar_refls() ;
   
   // gestiona un evento de teclado dirigido a este objeto
   bool gestionarEventoTeclaEspecial( int key ) ;
   
   // calcular la caja englobante (devuelve centro, p.min, p.max y máxima dimension)
   void compute_bounding_box( _vertex3f & centro, 
             _vertex3f & pmin, _vertex3f & pmax, float max_dim ) ;
} ;

#endif // fin OBJETO_PLY_HPP
