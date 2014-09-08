#ifndef ESFERA_MUNDO_HPP
#define ESFERA_MUNDO_HPP

#include "materiales.hpp"
#include "objetos-4.hpp"

//**********************************************************************
// clase para dibujar una esfera con un mapamundi

class EsferaMundo : public _sup_par_triangles_object3D
{
   public:
   EsferaMundo() ;
} ;

//**********************************************************************
// clase para dibujar una esfera sin textura con una mapa de amistades de facebook

class EsferaFacebook : public _sup_par_triangles_object3D
{
   public:
   EsferaFacebook() ;
} ;


#endif
