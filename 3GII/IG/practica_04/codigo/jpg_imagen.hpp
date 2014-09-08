#ifndef JPG_IMAGEN_HPP
#define JPG_IMAGEN_HPP

#include <string>

// clase 'Imagen'
//
// capa de abstracción sobre la clase jpg::JpegFile
// almacena los pixels de una imagen en memoria
// permite crearlos a partir de un archivo jpeg, y escribirlos a un jpeg

namespace jpg 
{

class Imagen 
{
	public:

	// inicializa la instancia e intenta cargar la imagen JPG 
 	// especificada en el nombre del archivo
	Imagen( const std::string & nombreArchivo ) ;

	// inicializa la instancia e intenta cargar la imagen JPG 
	// especificada en el nombre del archivo (wstr)
	Imagen( const std::wstring & wstr ) ;

	// devuelve un puntero a la zona donde estan los pixels,
	// puestos por filas,tres bytes por pixel, en orden RGB, 	
	unsigned char * leerPixels()  ;

	// devuelve un puntero a un pixel concreto
	unsigned char * leerPixel( unsigned ix, unsigned iy ) ;

	// devuelve el numero de columnas de la imagen
	unsigned long tamX() const ;

	// devuelve el numero de filas de la imagen
	unsigned long tamY() const ;

	// intenta escribir la imagen en un archivo JPG
	void escribirEn( const std::string & nombreArchivo );
	
	// borra el buffer
	~Imagen () ;

	private:
    
   unsigned char * buf  ;  // buffer con los pixel
	unsigned int    w, h ;  // ancho y alto, respectivamente

} ;

}

#endif
