/**  Fichero: SBSPLINE.C
***  Funcion: Dibujo de superficies B-Spline, no uniformes, no racionales.
***           Implementacion de funciones.
***           Practicas de Informatica Grafica.
***           (ver Foley, pp.495-500)
**/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#include "sbs_sbspline.hpp"

namespace sbs
{

/** vectores de nodos
**/
void asigna_vector_nodos( vector_nodos *vn, int nn, real *tn )

{  int  i ;
   real umin, umax, f ;

   if ( nn<8 )
      error("asigna_vector_nodos","el numero minimo de nodos es 8") ;

   vn->nn= nn ;
   vn->tn= (real *) res_memoria("asigna_vector_nodos",sizeof(real)*nn ) ;

   /** cargar nodos en el array local, y comprobar ordenacion
   **/
   for( i= 0 ; i<nn ; i++ )
   {  if ( (i>0) && (tn[i-1] > tn[i]) )
	 error("asigna_vector_nodos","nodos no ordenados") ;
      vn->tn[i]= tn[i] ;
   }

   /** transformar el vector de nodos de forma que el rango valido
   *** del parametro siempre este entre 0 y 1
   **/

   umin= tn[3]    ;
   umax= tn[nn-4] ;
   if (umax == umin)
      error("asigna_vector_nodos","no hay rango valido para el parametro");

   f=  1.0/(umax-umin) ;
   for( i= 0 ; i<nn ; i++ )
      vn->tn[i]=  f*(vn->tn[i]-umin) ;
}

void copia_vector_nodos( vector_nodos *vn1, vector_nodos *vn2 )
{
   int i ;

   vn1->nn= vn2->nn ;
   vn1->tn= (real *)res_memoria("copia_vector_nodos",sizeof(real)*vn2->nn ) ;
   for( i= 0 ; i< vn1->nn ; i++ )
      vn1->tn[i]= vn2->tn[i] ;
}

real eval_base( vector_nodos *vn, int i, real u )
{
   return eval_base_rec(vn,i,4,u);
}

real eval_base_rec( vector_nodos *vn, int i, int k, real u )
{
  real den1, den2, fra1, fra2, res ;
  real *t= vn->tn ;

   if ( k==1 )
   if ( i<0 || i>vn->nn-2 )
      error("ah","eh") ;

   if ( k==1 )
   {
     if ( t[i] <= u  && u < t[i+1] )
      return 1.0 ;

     
     if ( t[vn->nn-4] == t[vn->nn-1] ) 
     if ( i==vn->nn-5 && u >= t[vn->nn-4] )
	return 1.0 ;
     

     return 0.0 ;
  }

  den1= t[i+k-1] - t[i] ;
  fra1= den1 == 0.0 ? 0.0 : (u-t[i])/den1   ;

  den2= t[i+k] - t[i+1] ;
  fra2= den2 == 0.0 ? 0.0 : (t[i+k]-u)/den2 ;

  res= 0.0 ;
  if (fra1!=0.0)
    res= fra1 * eval_base_rec(vn,i,k-1,u)   ;

  if (fra2!=0.0)
    res += fra2 * eval_base_rec(vn,i+1,k-1,u) ;

  return res ;
}

int indice_tramo( vector_nodos *vn, real u )
{
   int i ;

   for( i= 3 ; i < (vn->nn)-4 ; i++ )
     if ( vn->tn[i] <= u && u < vn->tn[i+1] )
       return i ;

   return (vn->nn)-5 ;
}

/**  Funciones b-spline
**/
void asigna_fun_bspline( fun_bspline *fbspl, int np, real *tpc, vector_nodos *vn )
{
  int i ;

  if ( np < 4 )
     error("asigna_fun_bspline","minimo numero de puntos de control es 4") ;

  fbspl->np= np ;
  fbspl->tpc= (real *)res_memoria("asigna_fun_bspline",sizeof(real)*np) ;
  for( i= 0 ; i<np ; i++ )
     fbspl->tpc[i]= tpc[i] ;

  copia_vector_nodos( &(fbspl->vn), vn ) ;
  if ( vn->nn != fbspl->np+4 )
     error("asigna_fun_bspline","numero de nodos o puntos de control incorrecto");
}

real eval_fbspl( fun_bspline *fbspl, real u )
{
   int  i, j ; 
   real res= 0.0 ;

   if ( u < 0.0 ) u=0.0 ;
   else if ( u >= 1.0 ) u= 0.999999999 ;

   i= indice_tramo( &(fbspl->vn), u) ;

   for( j= i-3 ; j<=i ; j++ )
     res += fbspl->tpc[j] * eval_base( &(fbspl->vn), j, u ) ;

   return res ;
}



/** Superficies B-spline
**/

void asigna_sup_bspline
(  
   sup_bspline *sbs, 
   int npu, 
   int npv,
   vector3 *tpc,
   vector_nodos *vnu, 
   vector_nodos *vnv 
)
{
   vector3 *porg, *pdes ;
   int     i ;

   if ( npu<4 || npv <4 || npu+4 != vnu->nn || npv+4 != vnv->nn )
      error("asigna_sup_bspline","numero de nodos o puntos de control incorrecto");

   sbs->npu= npu ;
   sbs->npv= npv ;
   copia_vector_nodos( &(sbs->vnu), vnu ) ;
   copia_vector_nodos( &(sbs->vnv), vnv ) ;

   sbs->tpc= (vector3 *)res_memoria("asigna_sup_bspline",sizeof(vector3)*npu*npv) ;

   porg= tpc ;
   pdes= sbs->tpc ;
   for( i= 0 ; i<npu*npv ; i++ )
      v3_copia( pdes++, porg++ ) ;
}

vector3 * eval_sup_bspline( sup_bspline *sbs, vector3 *p, real u, real v )
{
    int iu= indice_tramo( &(sbs->vnu), u ) ;
    int iv= indice_tramo( &(sbs->vnv), v ) ;
    int i, itramo, j, jtramo ;
    // vector3 pres ; // ¿no se usa?
    real resx, resy, resz ;

    real bu[4], bv[4] ;

    for( itramo= iu-3, i= 0 ; i<4 ; i++, itramo++ )
      bu[i]= eval_base( &(sbs->vnu), itramo, u ) ;

    for( jtramo= iv-3, j= 0 ; j<4 ; j++, jtramo++ )
      bv[j]= eval_base( &(sbs->vnv), jtramo, v ) ;

    resx= 0.0 ;
    resy= 0.0 ;
    resz= 0.0 ;

    for( i= 0, itramo= iu-3 ; i<4 ; i++, itramo++ )
    for( j= 0, jtramo= iv-3 ; j<4 ; j++, jtramo++ )
    {
       real b = bu[i]*bv[j] ;
       vector3 *pij= sbs->tpc + (jtramo*(sbs->npu)+itramo) ;

       resx += b*pij->x ;
       resy += b*pij->y ;
       resz += b*pij->z ;
    }
    return v3_asigna( p, resx, resy, resz ) ;
}


} ; // fin namespace sbs
