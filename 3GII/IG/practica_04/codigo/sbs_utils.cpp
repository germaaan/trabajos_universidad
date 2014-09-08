#include <math.h>
#include <stdio.h>
#include "sbs_utils.hpp"

namespace sbs
{
   
void error( const char * msg, const char * donde )
{
    printf("\nerror: %s",msg);
    printf("\nen la función '%s'",donde) ;
    printf("\nacabando programa...");
    printf("\n");

    exit(1) ;
}

void * res_memoria( const char * msg, size_t tamano )
{
    void * res = malloc(tamano) ;

    if ( res == NULL )
    	error("no se puede reservar memoria",msg) ;
    	
    	
    return res ;

}

vector3 *  v3_copia( vector3 * destino, const vector3 * origen )
{
   destino->x = origen->x ;
   destino->y = origen->y ;
   destino->z = origen->z ;

   return destino ;
}

vector3 *  v3_asigna( vector3 * destino, real vx, real vy, real vz )
{
   destino->x = vx ;
   destino->y = vy ;
   destino->z = vz ;

   return destino ;
}

punto * asigna_punto( punto * destino, real px, real py, real pz )
{
   destino->x = px ;
   destino->y = py ;
   destino->z = pz ;

   return destino ;

}

vector3 *  v3_resta( vector3 * destino, const vector3 * op1, const vector3 * op2 )
{
   destino->x = op1->x - op2->x ;
   destino->y = op1->y - op2->y ;
   destino->z = op1->z - op2->z ;

   return destino ;
}

vector3 *  v3_provec( vector3 * destino, const vector3 * op1, const vector3 * op2 )
{
   destino->x = op1->y*op2->z - op1->z*op2->y ;
   destino->y = op1->z*op2->x - op1->x*op2->z ;
   destino->z = op1->x*op2->y - op1->y*op2->x ;

   return destino ;
}

vector3 * v3_normaliza( vector3 * destino, const vector3 * v )
{
   double l = sqrt( v->x*v->x + v->y*v->y + v->z*v->z ) ;

   destino->x = v->x/l ;
   destino->y = v->y/l ;
   destino->z = v->z/l ;

   return destino ;
}


} ; // namespace sbs 
