#include <GL/glu.h>
#include <GL/glut.h>
#include "aux-p4.hpp"
#include "materiales.hpp"



//**********************************************************************

Textura::Textura( const std::string & nombreArchivoJPG ) 
{
   modo_gen_ct=mgct_desactivada; 
   coefs_s[0] = coefs_s[1] = coefs_s[2] = coefs_s[3] = 0;
   coefs_t[0] = coefs_t[1] = coefs_t[2] = coefs_t[3] = 0;
   ident_textura = 1;

   imagen = new jpg::Imagen(nombreArchivoJPG);

   glGenTextures(1, &ident_textura);
   glBindTexture(GL_TEXTURE_2D, ident_textura);
   gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, imagen->tamX(), imagen->tamY(), GL_RGB, GL_UNSIGNED_BYTE, imagen->leerPixels());
}

//----------------------------------------------------------------------

Textura::~Textura( ) 
{
   if ( imagen != NULL )
   {  delete imagen ;
      imagen = NULL ;
   }
}

//----------------------------------------------------------------------

void Textura::activar( ) 
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ident_textura);
   
	if (modo_gen_ct != mgct_desactivada){
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);

		if (modo_gen_ct == mgct_coords_objeto){
			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
			glTexGenfv(GL_S, GL_OBJECT_PLANE, coefs_s);
			glTexGenfv(GL_T, GL_OBJECT_PLANE, coefs_t);
       } else{
	  		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
			glTexGenfv(GL_S, GL_EYE_PLANE, coefs_s);
	  		glTexGenfv(GL_T, GL_EYE_PLANE, coefs_t);
	}
	} else{
      	glDisable(GL_TEXTURE_GEN_S);
   		glDisable(GL_TEXTURE_GEN_T);
   }
   
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

//**********************************************************************

//**********************************************************************

Material::Material() 
{
   iluminacion = false ;
   tex = NULL ;
   
   coloresCero() ;
}

//----------------------------------------------------------------------

Material::Material( const std::string & nombreArchivoJPG ) 
{
   iluminacion    = false ;
   tex            = new Textura( nombreArchivoJPG ) ;
   
   coloresCero();
   
   del.difusa = vectorRGB( 0.5, 0.5, 0.5 );
   tra.difusa = vectorRGB( 0.2, 0.2, 0.2 );
   
   del.especular = vectorRGB( 1.0, 1.0, 1.0 );
   tra.especular = vectorRGB( 0.2, 0.2, 0.2 );
}

//----------------------------------------------------------------------

void Material::coloresCero()
{
   const vectorRGB ceroRGB(0.0,0.0,0.0);
   
   color         = 
   
   del.emision   = 
   del.ambiente  = 
   del.difusa    = 
   del.especular = 

   tra.emision   = 
   tra.ambiente  = 
   tra.difusa    = 
   tra.especular = ceroRGB ;
   
   del.exp_brillo = 
   tra.exp_brillo = 1.0 ;
}

//----------------------------------------------------------------------

Material::~Material() 
{      
   if ( tex != NULL )
   {  delete tex ;
      tex = NULL ;
   }
}


//----------------------------------------------------------------------

void Material::activar()
{  

	if (!iluminacion){
		glDisable(GL_LIGHTING);
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_FALSE);
      	glColor3fv((GLfloat *) & color);
	} else{
		glEnable(GL_LIGHTING);

		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
		
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

		glMaterialfv(GL_FRONT, GL_EMISSION,(GLfloat *) &del.emision);
		glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat *) &del.ambiente );
		glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat *) &del.difusa);
		glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat *) &del.especular);
		glMaterialfv(GL_FRONT, GL_SHININESS, &del.exp_brillo);
		
		glMaterialfv(GL_BACK, GL_EMISSION, (GLfloat *) &tra.emision);
		glMaterialfv(GL_BACK, GL_AMBIENT, (GLfloat *) &tra.ambiente);
		glMaterialfv(GL_BACK, GL_DIFFUSE, (GLfloat *) &tra.difusa);
		glMaterialfv(GL_BACK, GL_SPECULAR, (GLfloat *) &tra.especular);
		glMaterialfv(GL_BACK, GL_SHININESS, &tra.exp_brillo);	
	}
   		
	if (tex !=  NULL)
		tex->activar();
}
  
//**********************************************************************

FuenteLuz::FuenteLuz( GLenum p_ind_fuente, GLfloat p_longi_ini, GLfloat p_lati_ini, const vectorRGB & p_color )
{
   assert( glGetError() == GL_NO_ERROR );
   
   // guardar el indice opengl de la fuente, y comprobar que es 
   // alguno de GL_LIGHT0, GL_LIGHT1, etc.....
   
   ind_fuente = p_ind_fuente ;
   GLenum max_num_fuentes ;
   
   glGetIntegerv( GL_MAX_LIGHTS, (GLint *) &max_num_fuentes );
   assert( GL_LIGHT0 <= ind_fuente );
   assert( ind_fuente <= GL_LIGHT0 + max_num_fuentes );
   
   // inicializar parámetros de la fuente de luz
   longi_ini = p_longi_ini ;
   lati_ini  = p_lati_ini  ;
   longi = longi_ini ;
   lati  = lati_ini ;
   
   col_ambiente  = p_color ;
   col_difuso    = p_color ;
   col_especular = p_color ;
   
   assert( glGetError() == GL_NO_ERROR );
}

//----------------------------------------------------------------------

void FuenteLuz::activar()
{
	GLfloat light_position[4] = {0.0, 0.0, 1.0, 0.0};
   
	glEnable(GL_LIGHTING);
	glEnable(ind_fuente);
   
	glLightfv(ind_fuente, GL_AMBIENT,(GLfloat *) &col_ambiente);
	glLightfv(ind_fuente, GL_DIFFUSE,(GLfloat *) &col_difuso);
	glLightfv(ind_fuente, GL_SPECULAR,(GLfloat *) &col_especular);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
		glRotatef(lati,1,1,0);
		glRotatef(longi,0,1,1);
		glLightfv(ind_fuente, GL_POSITION, light_position);  
	glPopMatrix(); 
}

//----------------------------------------------------------------------

bool FuenteLuz::gestionarEventoTeclaEspecial( int key ) 
{
   bool actualizar = true ;
   const float incr = 3.0f ;
   
   switch( key )
   {
      case GLUT_KEY_RIGHT:
         longi = longi+incr ;
         break ;
      case GLUT_KEY_LEFT:
         longi = longi-incr ;
         break ;
      case GLUT_KEY_UP:
         lati = minim( lati+incr, 90.0) ;
         break ;
      case GLUT_KEY_DOWN:
         lati = maxim( lati-incr, -90.0 ) ;
         break ;
      case GLUT_KEY_HOME:
         lati  = lati_ini ;
         longi = longi_ini ;
         break ;
      default :
         actualizar = false ;
         cout << "tecla no usable para la fuente de luz." << endl << flush ;
   }
   
   //if ( actualizar )
   //   cout << "fuente de luz cambiada: longi == " << longi << ", lati == " << lati << endl << flush ;
   return actualizar ;
}
