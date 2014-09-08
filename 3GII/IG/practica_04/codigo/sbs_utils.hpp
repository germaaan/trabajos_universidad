
#ifndef SBS_UTILS_H
#define SBS_UTILS_H

#include <stdlib.h>

namespace sbs
{

typedef double real ;     // se puede cambiar a 'float'

typedef struct
{
   real x,y,z ;
}
  vector3 ;

typedef vector3 punto ; // punto es un 'alias' de 'vector3'

void error( const char * msg, const char * donde ) ;

void * res_memoria( const char * msg, size_t tamano ) ;

vector3 * v3_copia    ( vector3 * destino, const vector3 * origen ) ;
vector3 * v3_asigna   ( vector3 * destino, real vx, real vy, real vz ) ;
vector3 * v3_resta    ( vector3 * destino, const vector3 * op1, const vector3 * op2 ) ;
vector3 * v3_provec   ( vector3 * destino, const vector3 * op1, const vector3 * op2 ) ;
vector3 * v3_normaliza( vector3 * destino, const vector3 * v ) ;
punto *   asigna_punto( punto * destino, real px, real py, real pz ) ;

} ;

#endif


