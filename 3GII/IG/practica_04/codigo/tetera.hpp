#ifndef TETERA_HPP
#define TETERA_HPP

#include "objetos-4.hpp"


//**********************************************************************
//
// Clase Tetera:
// -------------
// clase con varias mallas (superf. B-Spline) que representan la tetera
//
//**********************************************************************

class Tetera : public _multiple_meshes
{
   public:
   Tetera( unsigned long nu, unsigned long nv ) ;
} ;

#endif // fin TETERA_HPP
