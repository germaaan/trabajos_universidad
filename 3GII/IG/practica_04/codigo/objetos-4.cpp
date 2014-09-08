#include <cmath>
#include <GL/gl.h>
#include "objetos-4.hpp"
#include "file_ply_stl.hpp"


//**********************************************************************
//
// clase FPCuadrado
//
//**********************************************************************

void FPCuadrado::eval( double u, double v, vector3d &pos, vector3d &nor ) const 
{
   assert( 0.0 <= u && u <= 1.0 );
   assert( 0.0 <= v && v <= 1.0 );
   
   pos = vector3d( u, 0.0, v );
   nor = vector3d( 0.0, 1.0, 0.0 );
} 

//**********************************************************************
//
// clase FPCilindro
//
//**********************************************************************

void FPCilindro::eval( double u, double v, vector3d &pos, vector3d &nor ) const 
{
   assert( 0.0 <= u && u <= 1.0 );
   assert( 0.0 <= v && v <= 1.0 );
   
   const double alpha = 2.0*M_PI*u ;
   
   pos = vector3d( cos(alpha), v, -sin(alpha) );
   nor = vector3d( pos.x, 0.0, pos.z );
} 

//**********************************************************************
//
// clase FPEsfera
//
//**********************************************************************

void FPEsfera::eval( double u, double v, vector3d &pos, vector3d &nor ) const 
{
   assert( 0.0 <= u && u <= 1.0 );
   assert( 0.0 <= v && v <= 1.0 );
   
   const double 
      alpha = 2.0*M_PI*u ,    // longitud
      beta  = M_PI*(v-0.5) ;  // latitud
   const double
      cos_beta = cos(beta) ;
   
   pos = vector3d( cos(alpha)*cos_beta, sin(beta), -sin(alpha)*cos_beta );
   nor = pos ;
} 

//**********************************************************************
//
// clase FPDisco
//
//**********************************************************************

void FPDisco::eval( double u, double v, vector3d &pos, vector3d &nor ) const 
{
   assert( 0.0 <= u && u <= 1.0 );
   assert( 0.0 <= v && v <= 1.0 );
   
   const double alpha = 2.0*M_PI*u ;
   
   pos = vector3d( v*cos(alpha), 0.0, v*sin(alpha) );
   nor = vector3d( 0.0, 1.0, 0.0 );
} 

//**********************************************************************
//
// clase FPSupBSpline
//
//**********************************************************************

FPSupBSpline::FPSupBSpline( sbs::sup_bspline * p_sup_bsp )
{
   sup_bsp = p_sup_bsp ;
   assert( sup_bsp != NULL );
}
   
void FPSupBSpline::eval( double u, double v, vector3d &pos, vector3d &nor ) const 
{
   assert( 0.0 <= u && u <= 1.0 );
   assert( 0.0 <= v && v <= 1.0 );
   
   sbs::vector3 
      p00, pu0, pu1, pv0, pv1, tang_u, tang_v, nor1, nor2 ;
   const sbs::real
      vv = 1.0-v ;
      
   eval_sup_bspline( sup_bsp, &p00, u, vv );
   
   pos = vector3d( p00.x, p00.y, p00.z );
   
   // calculo de la normal a partir de las tangentes de la función, 
   // calculadas usando derivacion numérica
   const sbs::real 
      delta =  0.005 ;
   const sbs::real  
      u0 = ( delta    <= u    ) ? u-delta : u,
      u1 = ( u+delta  <= 1.0 ) ? u+delta : u,
      v0 = ( vv+delta <= 1.0 ) ? vv+delta : vv, 
      v1 = ( delta    <= vv   ) ? vv-delta : vv ;
   
   eval_sup_bspline( sup_bsp, &pu0, u0, vv );
   eval_sup_bspline( sup_bsp, &pu1, u1, vv );
   sbs::v3_resta( &tang_u, &pu1, &pu0 );
   
   eval_sup_bspline( sup_bsp, &pv0, u, v0);
   eval_sup_bspline( sup_bsp, &pv1, u, v1);
   sbs::v3_resta( &tang_v, &pv1, &pv0 );
   
   sbs::v3_provec( &nor1, &tang_u, &tang_v );
   sbs::v3_normaliza( &nor2, &nor1 );
   
   nor = vector3d(nor2.x,nor2.y,nor2.z) ; 
}
   
   
//**********************************************************************
//
// Clase _sup_par_triangles_object3D
// 
//**********************************************************************

// función auxiliar: devuelve el indice de un vértice en la tabla
// de vértices, dado el tamaño de la rejilla y la fila y columna del
// vértice

inline unsigned long indice(  const unsigned long nu, const unsigned long nv,
                              const unsigned long iu, const unsigned long iv )
{
   assert( iu <= nu && iv <= nv ) ;
   return iv*(nu+1L) + iu ; 
}

//----------------------------------------------------------------------
// Constructor: añade todos los vértices y triángulo, incluyendo normales
// y coordenadas de textura

_sup_par_triangles_object3D::_sup_par_triangles_object3D
(  
   const unsigned long nu, 
   const unsigned long nv, 
   const FunPar & fp 
) 
{
   assert( nu > 1 && nv > 1 );
   
   const unsigned long 
      nverts = (nu+1L)*(nv+1L) , // número total de vértices del modelo
      //naris  = 3L*nverts + nu + nv , // número total de aristas del modelo
      ncaras = 2L*nu*nv ; // número de caras del modelo
      
   // crear tablas de vértices, normales y coordenadas de textura
   
   Vertices.resize( nverts );
   Vertices_normals.resize( nverts );
   Vertices_tex_coords.resize( nverts );
   
   for( unsigned long iv = 0 ; iv <= nv ; iv++ )
   for( unsigned long iu = 0 ; iu <= nu ; iu++ )
   {
      const vector2d // coords. paramétricas
         cpar( double(iu)/double(nu) , double(iv)/double(nv) ); 
      vector3d 
         pos, nor ;  // posicion y normal
         
      // evalua posición y normal a partir de las coordenadas paramétricas
      fp.eval( cpar.s,cpar.t, pos, nor ); 
      
      // insertar vectores en las tablas
      const unsigned long 
         inv = indice(nu,nv,iu,iv) ; // indice del vértice en la tabla
      
      Vertices[inv]            = _vertex3f( pos.x, pos.y, pos.z )  ;  
      Vertices_normals[inv]    = _vertex3f( nor.x, nor.y, nor.z )  ;
      Vertices_tex_coords[inv] = _vertex2f( cpar.s, 1.0-cpar.t  ); 
   }
   
   Vertices_normals_computed = true ;
   Vertices_tex_coords_computed = true ;
   
   // crear tablas de aristas y caras
   Faces_vertices.resize( ncaras );
   
   unsigned long 
      co_car = 0L ;
   
   for( unsigned long iv = 0 ; iv < nv ; iv++ )
   for( unsigned long iu = 0 ; iu < nu ; iu++ )
   {
      const unsigned long // indices de los vértices en la tabla de v.
         inv0 = indice( nu,nv, iu  ,iv   ) ,  // inf.izq.
         inv1 = indice( nu,nv, iu+1,iv   ) ,  // inf.der.
         inv2 = indice( nu,nv, iu  ,iv+1 ) ,  // sup.izq.
         inv3 = indice( nu,nv, iu+1,iv+1 ) ;  // sup.der.
         
      Faces_vertices[co_car++] = _vertex3i( inv0, inv1, inv3 );
      Faces_vertices[co_car++] = _vertex3i( inv0, inv3, inv2 );
   }
   
   // calcular la caja englobante y normales de caras
   //compute_bounding_box();
   compute_faces_normals() ;
}

//**********************************************************************
//
// Clase _multiple_triangles_mesh_object3D
// 
//**********************************************************************

//----------------------------------------------------------------------
// Constructor: concretado en clases derivadas

_multiple_meshes::_multiple_meshes() 
{
   fesc = _vertex3f(1.0,1.0,1.0);
   despl = _vertex3f( 0.0,0.0,0.0);
}

//----------------------------------------------------------------------
// Dibuja todas las mallas de triangulos usando un modo

void _multiple_meshes::draw( _draw_type Draw_type )
{
   glMatrixMode( GL_MODELVIEW );
   glPushMatrix();
   
      glTranslatef(despl.x,despl.y,despl.z);
      glScalef( fesc.x, fesc.y, fesc.z );
      
      for( unsigned i = 0 ; i < meshes.size() ; i++ )
      {
         assert( meshes[i] != NULL );
         meshes[i]->draw( Draw_type ) ;
      }
   
   glMatrixMode( GL_MODELVIEW );
   glPopMatrix() ;
}


//----------------------------------------------------------------------
// Destructor: libera la memoria ocupada por las mallas

_multiple_meshes::~_multiple_meshes()
{
   for( unsigned i = 0 ; i < meshes.size() ; i++ )
      if ( meshes[i] != NULL )
      {  delete meshes[i] ;
         meshes[i] = NULL ;
      }
}





