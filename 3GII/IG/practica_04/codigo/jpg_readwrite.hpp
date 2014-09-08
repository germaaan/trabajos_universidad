////////////////////////////////////////////////////////////
//
//	JpegFile - A C++ class to allow reading and writing of
//	RGB and Grayscale JPEG images. (actually, it reads all forms
//	that the JPEG lib will decode into RGB or grayscale) and
//	writes only RGB and Grayscale.
//
//	It is based on a Win32 compilation of the IJG V.6a code.
//
//	This will only work on 32-bit Windows systems. I have only 
//	tried this with Win 95, VC++ 4.1.
//
//	This class Copyright 1997, Chris Losinger
//	This is free to use and modify provided my name is included.
//
//	Comments:
//	Thanks to Robert Johnson for discovering a JPG_DWORD-alignment bug
//	Thanks to Lee Bode for catching a bug in CMfcappView::OnFileGetdimensionsjpg() 
//
////////////////////////////////////////////////////////////
//
//	General Usage:
//
//	#include this file.
//	link with jpeglib2.lib
//
//	All functions here are static. There is no need to have a JpegFile object.
//	There is actually nothing in a JpegFile object anyway. 
//
//	So, you can do this :
//
//		JPG_BOOL ok = JpegFile::vertFlipBuf(buf, widthbytes, height);
//
//	instead of this :
//
//		JpegFile jpgOb;
//		JPG_BOOL ok = jpgOb.vertFlipBuf(buf, widthbytes, height);
//
/////
//
//	Linking usage :
//	It is sometimes necessary to set /NODEFAULTLIB:LIBC (or LIBCD) to use this
//	class. 
//
/////
//
//	Error reporting:
//	The class generates message boxes in response to JPEG errors.
//
//	The JpegFile.cpp fn my_error_exit defines the behavior for
//	fatal errors : show msg box, return to caller.
//
//	Warnings are handled by jpeglib.lib - which	generates msg boxes too.
//	
////////////////////////////////////////////////////////////////

/*
////////////////////////////////////////////////////////////////
//	Reading Usage :

	JPG_UINT height;
	JPG_UINT width;
	unsigned char *dataBuf;
   //read the file
   dataBuf=JpegFile::JpegFileToRGB(fileName,
								&width,
								&height);
	if (dataBuf==NULL) {
		return;
	}

	// RGB -> BGR
	JpegFile::BGRFromRGB(dataBuf, m_width, m_height);


	unsigned char *buf;
	// create a JPG_DWORD aligned buffer from the JpegFile object
	buf = JpegFile::MakeJPG_DWORDAlignedBuf(dataBuf,
									width,
									height,
									&m_widthDW);

	// flip that buffer
	JpegFile::VertFlipBuf(m_buf, m_widthDW, m_height);

	// you now have a buffer ready to be used as a DIB

	// be sure to delete [] dataBuf;	// !!!!!!!!!!
	//			delete [] buf;


	// Writing Usage


	// this assumes your data is stored as a 24-bit RGB DIB.
	// if you have a 1,4,8,15/16 or 32 bit DIB, you'll have to 
	// do some work to get it into a 24-bit RGB state.

	unsigned char *tmp=NULL;

	// assume buf is a JPG_DWORD-aligned BGR buffer, vertically flipped
	// as if read from a BMP file.

	// un-JPG_DWORD-align
	tmp=JpegFile::RGBFromJPG_DWORDAligned(buf,
									widthPix,
									widthBytes,
									height);

	// vertical flip
	JpegFile::VertFlipBuf(tmp, widthPix * 3, height);

	// reverse BGR
	JpegFile::BGRFromRGB(tmp, widthPix, height);

	if (tmp==NULL) {
		AfxMessageBox("~JPG_DWORD Memory Error");
		return;
	}

	// write it
	JPG_BOOL ok=JpegFile::RGBToJpegFile(fileName, 
						tmp,
						width,
						height,
						TRUE, 
						75);
	if (!ok) {
		AfxMessageBox("Write Error");
	}

	delete [] tmp;

////////////////////////////////////////////////////////////////

*/

//
//	for JPG_DWORD aligning a buffer
//

namespace jpg
{

	
#define JPG_BOOL    bool
#define JPG_UINT    unsigned int
#define JPG_ULONG   unsigned long
#define JPG_DWORD   unsigned int
#define JPG_CString const char *



#define WIDTHBYTES(bits)    (((bits) + 31) / 32 * 4)

class JpegFile 
{
public:

	////////////////////////////////////////////////////////////////
	// read a JPEG file to an RGB buffer - 3 bytes per pixel
	// returns a ptr to a buffer .
	// caller is responsible for cleanup!!!
	// unsigned char *buf = JpegFile::JpegFileToRGB(....);
	// delete [] buf;

	static unsigned char * JpegFileToRGB(JPG_CString fileName,			// path to image
							   JPG_UINT *width,					// image width in pixels
							   JPG_UINT *height);				// image height

	////////////////////////////////////////////////////////////////
	// write a JPEG file from a 3-component, 1-byte per component buffer

	static JPG_BOOL RGBToJpegFile(JPG_CString fileName,				// path
							unsigned char *dataBuf,					// RGB buffer
							JPG_UINT width,						// pixels
							JPG_UINT height,					// rows
							JPG_BOOL color,						// TRUE = RGB
															// FALSE = Grayscale
							int quality);					// 0 - 100


	////////////////////////////////////////////////////////////////
	// fetch width / height of an image
	
	static JPG_BOOL GetJPGDimensions(JPG_CString fileName,			// path
								JPG_UINT *width,				// pixels
								JPG_UINT *height);

	////////////////////////////////////////////////////////////////
	//	utility functions
	//	to do things like JPG_DWORD-align, flip, convert to grayscale, etc.
	//

	////////////////////////////////////////////////////////////////
	// allocates a JPG_DWORD-aligned buffer, copies data buffer
	// caller is responsible for delete []'ing the buffer

	static unsigned char * MakeJPG_DWORDAlignedBuf(unsigned char *dataBuf,			// input buf
									 JPG_UINT widthPix,				// input pixels
									 JPG_UINT height,				// lines
									 JPG_UINT *uiOutWidthBytes);	// new width bytes


	////////////////////////////////////////////////////////////////
	// if you have a JPG_DWORD aligned buffer, this will copy the
	// RGBs out of it into a new buffer. new width is widthPix * 3 bytes
	// caller is responsible for delete []'ing the buffer
	
	static unsigned char *RGBFromJPG_DWORDAligned(unsigned char *inBuf,				// input buf
									JPG_UINT widthPix,				// input size
									JPG_UINT widthBytes,			// input size
									JPG_UINT height);

	////////////////////////////////////////////////////////////////
	// vertically flip a buffer - for BMPs
	// in-place
	
	// note, this routine works on a buffer of width widthBytes: not a 
	// buffer of widthPixels.
	static JPG_BOOL VertFlipBuf(unsigned char * inbuf,						// input buf
					   JPG_UINT widthBytes,							// input width bytes
					   JPG_UINT height);							// height

	// NOTE :
	// the following routines do their magic on buffers with a whole number
	// of pixels per data row! these are assumed to be non JPG_DWORD-aligned buffers.

	////////////////////////////////////////////////////////////////
	// convert RGB to grayscale	using luminance calculation
	// in-place
	
	static JPG_BOOL MakeGrayScale(unsigned char *buf,						// input buf 
						JPG_UINT widthPix,							// width in pixels
						JPG_UINT height);							// height

	////////////////////////////////////////////////////////////////
	// swap Red and Blue bytes
	// in-place
	
	static JPG_BOOL BGRFromRGB(unsigned char *buf,							// input buf
					JPG_UINT widthPix,								// width in pixels
					JPG_UINT height);								// lines

	////////////////////////////////////////////////////////////////
	// these do nothing
	JpegFile();		// creates an empty object
	~JpegFile();	// destroys nothing

}; // class JpegFile

}  // namespace jpg

