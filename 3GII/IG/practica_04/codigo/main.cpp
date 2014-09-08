#include <ctype.h>
#include <cmath>
#include <iostream>
#include <vector>

#include <GL/gl.h>
#include <GL/glut.h>

#include "aux-p4.hpp"
#include "objetos-3.h"
#include "lata-coca.hpp"
#include "esfera-mundo.hpp"
#include "tetera.hpp"
#include "objeto-ply.hpp"

using namespace std;

//**********************************************************************
// tamaño de la ventana

int
  altoActual  = 1024, 
  anchoActual = 1024 ;
  
//**********************************************************************
// lista de objetos, y modo de dibujo

const unsigned 
   num_objetos = 6 ; // número total de objetos distintos que pueden dibujarse

const char *
   descr_objetos[num_objetos] =   // descripciones de los objetos:
   {  "lata de coca cola", 
      "esfera del mundo (mapa físico)",
      "esfera del mundo (amistades de facebook)",
      "tetera" ,
      "objeto ply",
      "object cube"
   } ;

LataCocaCola *   obj_lata_coca_cola = NULL ; // objeto indice 0
EsferaMundo *    obj_esfera_mundo = NULL ;   // objeto indice 1
EsferaFacebook * obj_esfera_facebook = NULL ;// objeto indice 2
Tetera *         obj_tetera = NULL ;         // objeto indice 3
ObjetoPLY *      obj_ply = NULL ;            // objeto indice 4
_cube_object3D*  obj_cube = NULL ;           // objeto indice 5
   
_draw_type                // declarado en 'objetos-3.h'
   modo_dibujo_actual ;   // modo actual de dibujo
   
const unsigned int
   num_modos_dibujo = ((unsigned int) SOLID_MATERIAL_GOUROUD)+1 ;
   
unsigned 
   i_objeto_act ; // índice del objeto que se está visualizando ahora mismo

//**********************************************************************
// fuentes de luz 

FuenteLuz 
   * fuente_luz_0 = NULL ,
   * fuente_luz_1 = NULL ;
   
//**********************************************************************
// parámetros de la matriz de vista y modelado

const GLfloat
   longi_cam_ini =  45.0,  // valor inicial para 'longi_cam' (ver abajo)
   lati_cam_ini  =  30.0 , // valor inicial para 'lati_cam' (ver abajo)
   dis_cam_ini   =  1.0 ;  // valor inicial para la distancia de la camara al origen
   
GLfloat
   longi_cam =  longi_cam_ini, // angulo de longitud actual de la cámara, en grados
   lati_cam  =  lati_cam_ini , // angulo de latitud actual de la cámara, en grados
   dis_cam   =  dis_cam_ini ;  // distancia de la camara al origen
   
GLfloat
   ang_ry_obj = 0.0 , // ángulo actual de rotacion en Y+ del objeto, en grados
   ang_rx_obj = 0.0 , // ángulo actual de rotacion en X- del objeto, en grados
   ang_rz_obj = 0.0 , // ángulo actual de rotacion en Z+ del objeto, en grados
   f_esc_obj  = 1.0 ; // factor de escala del objeto (en tanto por uno)

//**********************************************************************
// gestión de los modos de teclado

typedef enum 
{  mt_rot_objeto, 
   mt_par_camara, 
   mt_rot_luz,
   mt_tipo_dibujo_objeto,
   mt_material_ply,
   num_modos_teclado 
} 
   ModoTeclado ;
   
const char * 
   descr_mt[num_modos_teclado] =  // descripciones de los modos de teclado
      {  "F1: rotación y escala de objeto\n" 
               "\t\t flechas hor/ver  -> rotaciones Y+)/X-.\n"
               "\t\t pg.arr/ab.       -> rotacion en Z+.\n"
               "\t\t mas/meno         -> aumentar/disminuir tamaño de objeto.\n"
               "\t\t inicio           -> reinicializar posicion/tamaño del objeto.\n",
         "F2: rotación y zoom de cámara\n"
               "\t\t flechas   -> rotaciones hor./ver.\n"
               "\t\t mas/menos -> alejar/acercar cámara.\n"
               "\t\t inicio    -> reset.\n",
         "F3: rotación de la fuente de luz.\n"
               "\t\t flechas   -> rotaciones hor/ver.\n"
               "\t\t inicio    -> reset.\n",
         "F4: tipo de dibujo y objeto a dibujar.\n"
               "\t\t flecha arr./abajo -> modo de dibujo (caras, aristas, puntos).\n"
               "\t\t flecha izq./der   -> cambiar objeto que se dibuja.\n",
         "F5: material y texturas del objeto ply.\n"
               "\t\t flechas arr/aba   -> aumentar/dism. componente ambiental.\n"
               "\t\t flechas der/izq   -> aumentar/dism. componente difusa.\n"
               "\t\t pg.arr./aba.      -> aumentar/dism. componente especular.\n"
               "\t\t insert/fin        -> aumentar/dism  exponente de brillo especular.\n"
      } ;

ModoTeclado 
   modo_tecl_actual ;


//**********************************************************************
// fijar la matriz de vista, deja activo el modo de matriz modelview

void MatrizVista()
{
   const GLfloat
      longi_cam_rad = longi_cam*2.0f*M_PI / 360.0f ,
      lati_cam_rad  = lati_cam *2.0f*M_PI / 360.0f ;
      
   const GLfloat
      eyex = dis_cam*( sin(longi_cam_rad)*cos(lati_cam_rad) ),
      eyey = dis_cam*( sin(lati_cam_rad) ),
      eyez = dis_cam*( cos(longi_cam_rad)*cos(lati_cam_rad) );
      
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity() ;
   gluLookAt
   (  eyex, eyey, eyez,  // posición de la cámara
      0.0f, 0.0f, 0.0f,  // punto de atencion (== origen)
      0.0f, 1.0f, 0.0f   // vector 'up' (== eje Y+)
   ) ;
}

//**********************************************************************

void MatrizProyeccion()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity() ;
   
   if ( anchoActual < altoActual  )
   {  const GLfloat ratioYX = GLfloat(altoActual)/GLfloat(anchoActual) ;
      glOrtho( -dis_cam,dis_cam, -dis_cam*ratioYX,dis_cam*ratioYX, -dis_cam*3.0,dis_cam*3.0 );
   }
   else
   {  const GLfloat ratioXY = GLfloat(anchoActual)/GLfloat(altoActual) ;
      glOrtho( -dis_cam*ratioXY,dis_cam*ratioXY, -dis_cam,dis_cam, -dis_cam*3.0,dis_cam*3.0 );
   }
   
}

//**********************************************************************

void FuncRedimensionar( int nuevoAncho, int nuevoAlto )
{
  altoActual = nuevoAlto ;
  anchoActual = nuevoAncho ;
  
  glViewport(0,0,anchoActual,altoActual);
  
  using namespace std ;
  //cout << "ventana redimensionada, nuevo tamaño: " << anchoActual << " x " << altoActual << " pixels." << endl << flush ;
}

//**********************************************************************

void DibujarEjes()
{
   glDisable( GL_TEXTURE_2D );
   glDisable( GL_LIGHTING );
   glShadeModel( GL_FLAT );
   
   glMatrixMode( GL_MODELVIEW );
   glPushMatrix();
      glScalef( 1.0, 1.0, 1.0 );
      glBegin( GL_LINES );
         // eje X -rojo
         glColor4f( 1.0,0.0,0.0, 1.0 );
         glVertex3f( 0.0,0.0,0.0 );
         glVertex3f( 1.0,0.0,0.0 );
         // eje Y - verde
         glColor4f( 0.0,1.0,0.0, 1.0 );
         glVertex3f( 0.0,0.0,0.0 );
         glVertex3f( 0.0,1.0,0.0 );
         // eje Z - azul
         glColor4f( 0.0,0.0,1.0, 1.0 );
         glVertex3f( 0.0,0.0,0.0 );
         glVertex3f( 0.0,0.0,1.0 );
      glEnd();
   glPopMatrix();
}

//**********************************************************************

void DibujarFondo()
{
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ) ;
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   glOrtho( -1,1, -1,1, -1,1 );
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();
   
   glDisable(GL_LIGHTING);
   glDisable(GL_TEXTURE_2D);
   glDisable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);
   glDisable(GL_CULL_FACE);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
   glBegin( GL_QUADS );
      glColor3f(0.3,0.3,0.33); glVertex3f( -1.0, -1.0, 0.0 );
      glColor3f(0.3,0.3,0.33); glVertex3f( +1.0, -1.0, 0.0 );
      glColor3f(0.0,0.0,0.1); glVertex3f( +1.0, +1.0, 0.0 );
      glColor3f(0.0,0.0,0.1); glVertex3f( -1.0, +1.0, 0.0 );
   glEnd() ;
   glEnable( GL_DEPTH_TEST);
   
}

//**********************************************************************
// DibujarObjetoActual
// -------------------
// dibuja el objeto actual en el modo de dibujo actual

void DibujarObjetoActual()
{
   switch( i_objeto_act )
   {
      case 0:
         obj_lata_coca_cola->draw( modo_dibujo_actual );
         break;
      case 1:
         obj_esfera_mundo->draw( modo_dibujo_actual );
         break;
      case 2:
         obj_esfera_facebook->draw( modo_dibujo_actual );
         break;
      case 3:
         obj_tetera->draw( modo_dibujo_actual );
         break;
      case 4:
         obj_ply->draw( modo_dibujo_actual );
         break;
      case 5:
		obj_cube->draw( modo_dibujo_actual );
		break;
      default:
         cout << "error: valor no válido de 'i_objeto_act' (" << i_objeto_act << ") -- terminado." << endl << flush ;
         exit(1);
         break ;
   }
}

//**********************************************************************

void DibujarVentana()
{
   using namespace std ;
   //static unsigned long count = 0 ;
   //cout << "redibujando ventana (" << (++count) << ") ... " << flush ;
   
   assert( glGetError() == GL_NO_ERROR );
   assert( fuente_luz_0 != NULL && fuente_luz_1 != NULL) ;
   assert( i_objeto_act < num_objetos );
   //assert( objetos[i_objeto_act] != NULL ) ;
   
   DibujarFondo();
   MatrizProyeccion();
   MatrizVista(); 
   
   glMatrixMode( GL_MODELVIEW );
   
   DibujarEjes();
   fuente_luz_0->activar();
   fuente_luz_1->activar();
   
   glMatrixMode( GL_MODELVIEW );
   glPushMatrix();
      glRotated( ang_rz_obj,  0.0, 0.0, 1.0 );  // (3) rot Z+
      glRotated( ang_rx_obj, -1.0, 0.0, 0.0 ) ; // (2) rot X-
      glRotated( ang_ry_obj,  0.0, 1.0, 0.0 );  // (1) rot Y+
      glScalef( f_esc_obj, f_esc_obj, f_esc_obj );
      DibujarObjetoActual();
   glPopMatrix();    
   
   glutSwapBuffers();
   
   assert( glGetError() == GL_NO_ERROR );
   
   //cout << "hecho." << endl << flush ;
}

//**********************************************************************

void Inicializa( int argc, char *argv[] )
{
   using namespace std ;
   assert( glGetError() == GL_NO_ERROR );
   assert( argc >= 3 );
   
   // inicializar opengl
   glEnable(GL_DEPTH_TEST);
   
   // crear objetos

   obj_lata_coca_cola  = new LataCocaCola();
   obj_esfera_mundo    = new EsferaMundo();
   obj_esfera_facebook = new EsferaFacebook() ;
   obj_tetera          = new Tetera(30,30);
   obj_ply             = new ObjetoPLY(std::string(argv[1]),std::string(argv[2]));
   obj_cube            = new _cube_object3D(std::string(argv[2]));
   
   // inicialmente, el objeto activo es el objeto 0
   i_objeto_act = 0 ; 
   
   // inicialmente, se dibuja todo en modo caras
   modo_dibujo_actual = SOLID_MATERIAL_GOUROUD ;
   
   // crear fuentes de luz
   fuente_luz_0 = new FuenteLuz(GL_LIGHT0, 80.0f, 50.0f, vectorRGB(1.0f,1.0f,1.0f));
   fuente_luz_1 = new FuenteLuz(GL_LIGHT1,-100.0f,-30.0f, vectorRGB(0.8f,0.3f,0.2f));
   
   // inicializar el modo de teclado
   modo_tecl_actual = mt_rot_objeto ;
   cout << "modo teclado: " << descr_mt[modo_tecl_actual] << endl << flush ;

   // ya está
   assert( glGetError() == GL_NO_ERROR );
   //cout << "inicialización realizada." << endl << flush ;
}


//**********************************************************************

void Terminar()
{
   // liberar memoria:
   // (falta)
   // mensaje
   cout << "programa finalizado normalmente." << endl << flush ;
}

//**********************************************************************

void GestionEventoRaton( int button, int state, int x, int y )
{
   using namespace std ;
   
    
}

//**********************************************************************

bool GestionEventoTeclaEspecialObjeto( int key ) 
{
   bool actualizar = true ;
   const double incr = 3.0 ;
   
   switch( key )
   {
      case GLUT_KEY_LEFT:
         ang_ry_obj += incr ;
         break ;
      case GLUT_KEY_RIGHT:
         ang_ry_obj -= incr  ;
         break ;
      case GLUT_KEY_UP:
         ang_rx_obj += incr  ;
         break ;
      case GLUT_KEY_DOWN:
         ang_rx_obj -= incr  ;
         break ;
      case GLUT_KEY_PAGE_UP :
         ang_rz_obj += incr  ;
         break ;
      case GLUT_KEY_PAGE_DOWN :
         ang_rz_obj -= incr  ;
         break ;
      case GLUT_KEY_HOME:
         ang_rz_obj = 0.0f ;
         ang_ry_obj = 0.0f ;
         ang_rx_obj = 0.0f ;
         f_esc_obj  = 1.0f ;
         break ;
      default :
         actualizar = false ;
         cout << "tecla no usable en este modo." << endl << flush ;
   }
   return actualizar ;
}

//**********************************************************************

bool GestionEventoTeclaNormalObjeto( unsigned char key ) 
{
   using namespace std ;
   bool 
      actualizar = true ;
   const float
      f_delta = 0.05f ;  // incremento/decr. del tamaño un 5% al pulsar
   //cout << "GestionEventoTeclaNormalObjeto(key==" << key << ")" << endl << flush ;
   switch( key )
   {
      case '+' :
         if ( f_esc_obj < 10.0f )
            f_esc_obj *= (1.0f+f_delta) ;
         break ;
      case '-' :
         if ( f_esc_obj > 0.1f ) 
            f_esc_obj /= (1.0f+f_delta) ;
         break ;
      default :
         cout << "tecla no usable en este modo." << endl << flush ;
         actualizar = false ;
         break ;
   }
   return actualizar ;
}

//**********************************************************************

bool GestionEventoTeclaEspecialTipoObjeto( int key )
{  
   using namespace std ;
   bool actualizar = true ;
   switch( key )
   {  case GLUT_KEY_UP :
         modo_dibujo_actual = _draw_type( unsigned(modo_dibujo_actual+1) % num_modos_dibujo ) ;
         break ;
      case GLUT_KEY_DOWN :
         modo_dibujo_actual = _draw_type( modo_dibujo_actual > 0 ? modo_dibujo_actual-1 : num_modos_dibujo-1 );
         break ;
      case GLUT_KEY_LEFT :
         i_objeto_act = i_objeto_act > 0 ? i_objeto_act-1 : num_objetos-1 ;  // % no funciona con result. negativo
         //cout  << "objeto a dibujar: (" << i_objeto_act << ")" 
         //      << descr_objetos[i_objeto_act] << endl << flush;
         break ;
      case GLUT_KEY_RIGHT :
         i_objeto_act = (i_objeto_act + 1) % num_objetos ;
         //cout  << "objeto a dibujar: (" << i_objeto_act << ")" 
         //      << descr_objetos[i_objeto_act] << endl << flush;
         break ;
      case GLUT_KEY_HOME :
         i_objeto_act = 0 ;
         break;
      default:
         actualizar = false ;
         cout << "tecla no usada en modo 'tipo de dibujo y objeto'" << endl << flush ;
         break ;
   }
   return actualizar ;
}

//**********************************************************************
// gestor del evento de pulsación de tecla especial en modo 'cámara'

bool GestionEventoTeclaEspecialCamara( int key )
{
   bool actualizar = true ;
   
   const GLfloat incr = 3.0 ;
   
   switch( key )
   {
      case GLUT_KEY_UP :
         lati_cam = minim( lati_cam+incr, 89.7f );
         break ;
      case GLUT_KEY_DOWN :
         lati_cam = maxim( lati_cam-incr, -89.7f );
         break ;
      case GLUT_KEY_LEFT :
         longi_cam += incr ;
         break ;
      case GLUT_KEY_RIGHT :
         longi_cam -= incr ;
         break ;
      case GLUT_KEY_HOME :
         longi_cam = longi_cam_ini ;
         lati_cam  = lati_cam_ini ;
         dis_cam   = dis_cam_ini ;
         break;
      default:
         actualizar = false ;
         cout << "tecla no usada en modo 'cámara'" << endl << flush ;
         break ;
   }
   return actualizar ;
}

//**********************************************************************

bool GestionEventoTeclaNormalCamara( unsigned char key ) 
{
   using namespace std ;
   bool 
      actualizar = true ;
   const float
      f_delta = 0.05f ;  // incremento/decr. de distancia un 5% al pulsar +/-
   //cout << "GestionEventoTeclaNormalCamara(key==" << key << ")" << endl << flush ;
   
   switch( key )
   {
      case '-' :
         if ( dis_cam < 10.0f )
            dis_cam *= (1.0f+f_delta) ;
         break ;
      case '+' :
         if ( dis_cam > 0.1f ) 
            dis_cam /= (1.0f+f_delta) ;
         break ;
      default :
         cout << "tecla no usable en este modo." << endl << flush ;
         actualizar = false ;
         break ;
   }
   return actualizar ;
}


//**********************************************************************

void GestionEventoTeclaNormal( unsigned char key, int x, int y )
{
   using namespace std ;
   bool
      actualizar = true ;
   char 
      upper_key = toupper(key);
   
   switch( upper_key )
   {
      case ' ' :
         modo_tecl_actual = ModoTeclado( (unsigned(modo_tecl_actual)+1) % num_modos_teclado ) ;
         cout << "modo teclado: " << descr_mt[modo_tecl_actual] << endl << flush ;
         break ;
      case 27  :  // código de la tecla 'escape' 
      case 'Q' : 
         Terminar();
         exit(0);
         break ; // inútil, pero si se quita el exit.....
      default  :
         switch ( modo_tecl_actual )
         {
            case mt_rot_objeto :
               actualizar = GestionEventoTeclaNormalObjeto(key) ;
               break ;
            case mt_par_camara :
               actualizar = GestionEventoTeclaNormalCamara(key) ;
               break ;
            default :
               actualizar = false ;
               cout << "tecla no usada en este modo." << endl << flush ;
               break ;
         }
         if ( actualizar )
            glutPostRedisplay();
         break ;
   }
}

//**********************************************************************

void GestionEventoTeclaEspecial( int key, int x, int y )
{
   using namespace std ;
   bool redisplay = false ;
   assert( fuente_luz_0 != NULL );
   
   assert( num_modos_teclado <= 12 );
   
   // acceso directo a los modos con las teclas de función
   // (asume valores consecutivos de GLUT_KEY_Fi)
   if ( GLUT_KEY_F1 <= key && key < GLUT_KEY_F1+num_modos_teclado )
   {
      modo_tecl_actual = ModoTeclado( key - GLUT_KEY_F1 );
      cout << "modo teclado: " << descr_mt[modo_tecl_actual] << endl << flush ;
   }
   else
   {  switch( modo_tecl_actual ) // gestionar la tecla en cada modo
      {
         case mt_rot_objeto :
            redisplay = GestionEventoTeclaEspecialObjeto(key) ;
            break ;
         case mt_rot_luz :
            redisplay = fuente_luz_0->gestionarEventoTeclaEspecial(key) ;
            break ;
         case mt_par_camara :
            redisplay = GestionEventoTeclaEspecialCamara(key) ;
            break ;
         case mt_tipo_dibujo_objeto:
            redisplay = GestionEventoTeclaEspecialTipoObjeto(key) ;
            break ;
         case mt_material_ply :
            redisplay = obj_ply->gestionarEventoTeclaEspecial(key);
            break ;
         default :
            cout << "tecla (aun) no usable en este modo" << endl << flush ;
            break ;
      }
   }
   if ( redisplay )
      glutPostRedisplay();
}

//**********************************************************************

int main( int argc, char *argv[] )
{
   // comprobar parámetros
   if ( argc < 3 )
   {  cout << "uso: " << argv[0] << "  <archivo.ply (sin extension)>  <archivo.jpg (con extension)>" << endl << flush ;
      exit(1);
   }
   
   // inicializar glut
   glutInit(&argc, argv);
   
   // crear ventana
   anchoActual = int( 0.85f*glutGet(GLUT_SCREEN_HEIGHT) ) ;
   altoActual  = anchoActual ;
   glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
   glutInitWindowSize(anchoActual,altoActual);
   glutCreateWindow("IG 12-13 : practica 4");
   
   // definir callbacks
   glutDisplayFunc( DibujarVentana ) ;
   glutReshapeFunc( FuncRedimensionar );
   glutMouseFunc( GestionEventoRaton );
   glutKeyboardFunc( GestionEventoTeclaNormal ) ;
   glutSpecialFunc( GestionEventoTeclaEspecial ); 
   
   // inicializar objetos de la aplicación
   Inicializa(argc,argv) ;
   
   // bucle de eventos
   glutMainLoop();
   
   // terminar la aplicación
   Terminar() ;
   return 0 ;
}


