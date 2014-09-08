#include <stdlib.h>
#include <string>
#include <iostream>

#include "jpg_imagen.hpp"
#include "jpg_readwrite.hpp"

namespace jpg 
{

//**********************************************************************
//
// constructor: crea imagen, cargándola de un archivo JPG

Imagen::Imagen( const std::string & nombreArchivo ) 
{
	using namespace std ;
	
	// incializar la imagen a la imagen nula
	
	buf = NULL ;
	w = 0 ;
	h = 0 ;
	
	//cout << "cargando archivo jpeg '" << nombreArchivo << "' .... " << flush ;
	
	buf = JpegFile::JpegFileToRGB( nombreArchivo.c_str(), &w, &h ) ;
	
	if (buf == NULL)
	{	std::cout << "error al cargar imagen (vea stderr para detalles)" << std::endl << std::flush ;
		exit(1);
	}
	
	//cout << " hecho." << endl << flush ;
}

//**********************************************************************

unsigned char * Imagen::leerPixels() 
{
   return buf ;
}	

//**********************************************************************

unsigned char * Imagen::leerPixel( unsigned ix, unsigned iy ) 
{
   return buf + (unsigned long)3*( (unsigned long)w*(unsigned long)iy + (unsigned long)ix );  
}

//**********************************************************************

unsigned long Imagen::tamX() const 
{
   return w ;
}

//**********************************************************************

unsigned long Imagen::tamY() const 
{
   return h ;
}

//**********************************************************************

void Imagen::escribirEn( const std::string & nombreArchivo )
{
    /**
   	static BOOL RGBToJpegFile(CString fileName,				// path
							unsigned char *dataBuf,					// RGB buffer
							UINT width,						// pixels
							UINT height,					// rows
							BOOL color,						// TRUE = RGB
															// FALSE = Grayscale
							int quality);					// 0 - 100
    **/

	bool result = bool( JpegFile::RGBToJpegFile( nombreArchivo.c_str(), buf,w,h,1,100) );

	if ( ! result )
	{
		std::cout << "error al escribir imagen (" << nombreArchivo << ")." ;
		exit(1) ; 
	}
}

//**********************************************************************
 
Imagen::~Imagen ()  
{
   if ( buf != NULL )
       delete[] buf ;
   buf = NULL ;
}

//**********************************************************************


} // fin namespace jpg


