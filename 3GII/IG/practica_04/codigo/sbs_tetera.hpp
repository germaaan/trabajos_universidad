/**  Fichero: TETERA.H
***  Funcion: Decl. de datos y funciones para crear la tetera
***           como parametros de superficies b-spline
**/

#ifndef SBS_TETERA_H
#define SBS_TETERA_H

#include "sbs_sbspline.hpp"

namespace sbs
{

void crea_cuerpo( sup_bspline *sbs ) ;
void crea_boca  ( sup_bspline *sbs ) ;
void crea_asa   ( sup_bspline *sbs ) ;
void crea_tapa  ( sup_bspline *sbs ) ;

} ;

#endif
