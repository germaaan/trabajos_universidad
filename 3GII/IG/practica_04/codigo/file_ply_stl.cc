//**********************************************************************
// class to read ply files of triangles
//
// Domingo Martín y Carlos Ureña
// Gnu Public Licence
//**********************************************************************



#include "file_ply_stl.hpp"


namespace _file_ply 
{

//**********************************************************************

void error( const char *msgError )
{
   using namespace std ;
   cout  << endl
         << "error: " << msgError << endl 
         << "programa terminado." << endl
         << flush ; 
        
   exit(-1);
}

// buffer de lectura usado para leer una linea completa del ply

const streamsize 
   bufferCapacity = streamsize(10)*streamsize(1024) ;
char 
   buffer[(unsigned long)(bufferCapacity)];


//**********************************************************************
//
// read: lee un archivo ply y lo carga en 'vertices' y 'faces'
//
// * 'nombreArchivo' no debe incluir la extensión .ply (se le añade antes de abrirlo)
// * si hay un error, aborta
// * elimina cualquier contenido previo en los vectores 'vertices' y 'faces'
// * lee el archivo .ply y lo carga en 'vertices' y 'faces'
// * solo admite plys con triángulos, 
// * no lee colores, coordenadas de textura, ni normales.


void read( const char * nombreArchivo, vector<float> &vertices, vector<int> &faces )
{

   // modelos ply en:
   // http://graphics.im.ntu.edu.tw/~robin/courses/cg03/model/
   // http://people.sc.fsu.edu/~jburkardt/data/ply/ply.html
   
   using namespace std ;

   const string 
      sfn = string(nombreArchivo) + ".ply" ;
   
   string 
      token ;
   unsigned long long int 
      nVertexs = 0, 
      nFaces   = 0 ;
   unsigned
      state    = 0; // 0 antes de leer 'element vertex', 1 antes de leer 'element face', 2 después
   bool 
      inHeader = true ;
   ifstream  
      src( sfn.c_str() ) ; // open the file
      
   if ( ! src.is_open() ) 
   {
      string msg = string("no puedo abrir archivo '") + sfn + "' para lectura." ; 
      error(msg.c_str());
   }
    
   src >> token ;

   if ( token != "ply" )
      error("el archivo de entrada no comienza con 'ply'.");

   src.getline(buffer,bufferCapacity);

   cout << "leyendo malla de triángulos de '" + sfn + "' " << flush ;

   // leer cabecera:
   
   while( inHeader )
   {
      if ( src.eof() ) 
         error("fin de archivo no esperado en la cabecera");

     src >> token ;

     if ( token == "end_header" )
     {  if ( state != 2 )
           error("no se encuentran elementos 'element vertex' ni 'element face' en la cabecera");
        src.getline(buffer,bufferCapacity);
        inHeader = false ;
     }
     else if ( token == "comment" )
     {  src.getline(buffer,bufferCapacity);
        //cout << "  comment: " << buffer << endl ;
     }
     else if ( token == "format" )
     {  src >> token ;
        if ( token != "ascii" )
        {  string msg = string("no se puede leer archivo en formato no 'ascii', el formato es: '")+token+"'" ;
           error(msg.c_str());
        }
        src.getline(buffer,bufferCapacity);
     }
     else if ( token == "element" )
     {  src >> token ;
        if ( token == "vertex" )
        {  if ( state != 0 )
              error("'element vertex' va después de 'element face'");
           src >> nVertexs ;
           //cout << "  number of vertexes == " << nVertexs << endl ;
           state = 1 ;
        }
        else if ( token == "face" )
        {  if ( state != 1 )
              error("warning: 'element vertex' va después de 'element face'");
           src >> nFaces ;
           //cout << "  number of faces == " << nFaces << endl ;
           state = 2 ;
        }
        else
        {  cout << "  elemento '" + token + "' ignorado." << endl ;
        }
        src.getline(buffer,bufferCapacity);
     }
     else if ( token == "property" )
     {  src.getline(buffer,bufferCapacity); // ignore properties, so far ...
     }
   } // end of while( inHeader )

   if ( nVertexs == 0 || nFaces == 0 )
      error("hay cero vértices o cero caras en el archivo");
      
   cout << "  (" << nVertexs << " vértices, " << nFaces << " caras)" << endl << flush ;
   
      
   // leer vértices:
      
   vertices.resize( nVertexs*3 );

   //cout << "  reading " << nVertexs << " vertexes ...." << endl << flush ;
     
   for( unsigned long long iv = 0 ; iv < nVertexs ; iv++ )
   {
      if ( src.eof() ) 
         error("fin de archivo no esperado en la lista de vértices");

      float x,y,z ;

      src >> x >> y >> z ;
      //cout << "vertex #" << iv << " readed: (" << x << "," << y << "," << z << ")" << endl ;
      
      src.getline(buffer,bufferCapacity); // ignore more properties, so far ...
      
      // add new vertex
      unsigned long long base = iv*3 ;
      vertices[base+0] = x ;
      vertices[base+1] = y ;
      vertices[base+2] = z ; 
   }

   //cout << "  end vertex list" << endl << flush ;
   //cout << "  reading " << nFaces << " faces ...." << endl << flush ;
   
   // leer caras
   
   faces.resize( nFaces*3 );
   
   for( unsigned long long ifa = 0 ; ifa < nFaces ; ifa++ )
   {
      if ( src.eof() ) 
         error("fin de archivo no esperado en la lista de caras");

      unsigned nv ;
      src >> nv ;
      //cout << "reading face #" << ifa << " with " << nv << " vertexes: " ;
      
      if ( nv != 3 )
         error("se ha encontrado una cara con un número de vértices distinto de 3.");
         
      unsigned long long iv0, iv1, iv2 ;

      src >> iv0 >> iv1 >> iv2 ;
      //cout << " " << iv0 << ", " << iv1 << ", " << iv2 << endl ;

      src.getline(buffer,bufferCapacity); // ignore more properties, so far ...

      unsigned long long base = ifa*3 ; 
      faces[base+0] = iv0 ;
      faces[base+1] = iv1 ;
      faces[base+2] = iv2 ;
   }

   //cout << "  end face list." << endl ;
   //cout << "ply file readed" << endl << flush ;
   
   return ;
}


} // fin namespace _file_ply
