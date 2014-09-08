/*********************************************************************
***
***  Fichero: SBSPLINE.H
***  Funcion: Dibujo de superficies B-Spline, no uniformes, no racionales.
***           Declaracion de estr. de datos y funciones.
***           Practicas de Informatica Grafica.
***
*********************************************************************/

/**  Vector de nodos (Knot Vector) para funciones base de los
***  splines no uniformes y no-racionales de orden 4
**/

#ifndef SBS_SBSPLINE_H
#define SBS_SBSPLINE_H

#include "sbs_utils.hpp"

namespace sbs
{

typedef struct {
   int nn      ; /** numero de nodos (minimo 8)      **/
   real *tn    ; /** lista de nodos                  **/
} vector_nodos  ;

/** Creacion y copia de un vector de nodos
*** <nn> debe igual que <m+4>
*** donde <m> es el numero de puntos de control usados (minimo 4)
**/
void asigna_vector_nodos( vector_nodos *vn, int nn, real *tn ) ;
void copia_vector_nodos( vector_nodos *vn1, vector_nodos *vn2 ) ;

/** Evaluacion de la funcion base numero <i> en el punto <u>
***
*** <i> puede valer desde <0> hasta <nn-5>, ambos inclusive.
*** <u> puede valer entre <0> y <1>
**/
real eval_base( vector_nodos *vn, int i, real u ) ;

/** auxiliar de la anterior
**/
real eval_base_rec( vector_nodos *vn, int i, int k, real u ) ;

/** determina el indice del tramo en el que esta el parametro <u>
*** (<u> debe estar entre <0> y <1>)
**/
int indice_tramo( vector_nodos *vn, real u ) ;

/** Funciones B-Spline (para pruebas)
**/

typedef struct {
  vector_nodos vn ;
  int          np ;
  real       *tpc ;
} fun_bspline ;

void asigna_fun_bspline( fun_bspline *fbspl, int np, real *tpc, vector_nodos *vn ) ;

/** evalua la funcion en un punto
*** <u> debe estar entre <0> y <1>
**/
real eval_fbspl( fun_bspline *fbspl, real u ) ;

/** Superficies B-Spline.
**/

typedef struct {
   vector_nodos vnu ;  /** vector de nodos para el parametro u      **/
   vector_nodos vnv ;  /** vector de nodos para el parametro v      **/
   int npu, npv     ;  /** numero de puntos de control en u y en v  **/
   vector3 *tpc    ;   /** array de puntos de control               **/
} sup_bspline ;

/**  Creacion de superficies b-spline
***
***  <npu> y <npv> deben ser mayores o iguales a <4>
***  <tpc> apunta a una tabla de <npu*npv> vectores, dispuestos por filas
***  tpc[npu*i+j] es el vector en la fila <i> columna <j>
**/

void asigna_sup_bspline( sup_bspline *sbs, int npu, int npv,
			 vector3 *tpc,
			 vector_nodos *vnu, vector_nodos *vnv ) ;

/** evaluacion de una supericie b-spline en un punto (u,v)
*** (se obtiene un vector3, (u,v) esta en [0,1]^2)
**/
vector3 * eval_sup_bspline( sup_bspline *sbs, vector3 *p, real u, real v ) ;

} ; // fin namespace sbs

#endif




