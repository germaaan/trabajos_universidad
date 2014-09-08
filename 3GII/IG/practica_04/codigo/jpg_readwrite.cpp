////////////////////////////////////////////////////////////
//	JpegFile - A C++ class to allow reading and writing of
//	RGB and Grayscale JPEG images.
//	It is based on the IJG V.6 code.
//
//	This class Copyright 1997, Chris Losinger
//	This is free to use and modify provided my name is 
//	included.
//
//	See jpegfile.h for usage.
//
////////////////////////////////////////////////////////////



#undef FAR        // gets rid of a warning
#define XMD_H     // fixes a type redefiniton issue
#include "jpg_readwrite.hpp"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef __cplusplus
	extern "C" {
#endif // __cplusplus

#include "jpeglib.h"

#ifdef __cplusplus
	}
#endif // __cplusplus

#include <iostream>
#include <fstream>

#include "jpg_memsrc.hpp"
//
//
//

/*
 * <setjmp.h> is used for the optional error recovery mechanism shown in
 * the second part of the example.
 */

#include <setjmp.h>

// error handler, to avoid those pesky exit(0)'s

namespace jpg
{
	
// lee un archivo completo en un buffer de memoria en el heap
// ver: http://www.cplusplus.com/doc/tutorial/files/

struct datos_archivo
{
	char * 			bytes ;
	unsigned long 	numBytes ;
} ;

void leer_archivo( const std::string & nombre, datos_archivo & da )
{
	using namespace std ;
	
	da.bytes = NULL ;
	da.numBytes = 0 ;

	ifstream file(nombre.c_str(), ios::in|ios::binary|ios::ate);
	
	if (! file.is_open())
	{
		cout << "imposible abrir archivo para lectura (" << nombre.c_str() << ")" << endl << flush ;
		exit(1);	
	}
	
	ifstream::pos_type numBytes = file.tellg();
	char *	bytes = new char [numBytes];
	
	file.seekg (0, ios::beg);
	file.read (bytes, numBytes);
	file.close();
	
	da.bytes = bytes ;
	da.numBytes = numBytes ;

}

struct my_error_mgr {
  struct jpeg_error_mgr pub;	/* "public" fields */

  jmp_buf setjmp_buffer;	/* for return to caller */
};

typedef struct my_error_mgr * my_error_ptr;

//
//
//

METHODDEF(void) my_error_exit (j_common_ptr cinfo);

//
//	to handle fatal errors.
//	the original JPEG code will just exit(0). can't really
//	do that in Windows....
//

METHODDEF(void) my_error_exit (j_common_ptr cinfo)
{
	/* cinfo->err really points to a my_error_mgr struct, so coerce pointer */
	my_error_ptr myerr = (my_error_ptr) cinfo->err;

	char buffer[JMSG_LENGTH_MAX];

	/* Create the message */
	(*cinfo->err->format_message) (cinfo, buffer);

	/* Always display the message. */
	fprintf (stderr,"JPEG Fatal Error\n");


	/* Return control to the setjmp point */
	longjmp(myerr->setjmp_buffer, 1);
}

// store a scanline to our data buffer
void j_putRGBScanline(unsigned char *jpegline, 
						 int widthPix,
						 unsigned char *outBuf,
						 int row);

void j_putGrayScanlineToRGB(unsigned char *jpegline, 
						 int widthPix,
						 unsigned char *outBuf,
						 int row);


//
//	constructor doesn't do much - there's no real class here...
//

JpegFile::JpegFile()
{
}

//
//	
//

JpegFile::~JpegFile()
{
}

//
//	read a JPEG file
//

unsigned char * JpegFile::JpegFileToRGB(JPG_CString fileName,
							   JPG_UINT *width,
							   JPG_UINT *height)

{

	// basic code from IJG Jpeg Code v6 example.c

	*width=0;
	*height=0;

	/* This struct contains the JPEG decompression parameters and pointers to
	* working space (which is allocated as needed by the JPEG library).
	*/
	struct jpeg_decompress_struct cinfo;
	/* We use our private extension JPEG error handler.
	* Note that this struct must live as long as the main JPEG parameter
	* struct, to avoid dangling-pointer problems.
	*/
	struct my_error_mgr jerr;
	/* More stuff */
	FILE * infile=NULL;		/* source file */

	JSAMPARRAY buffer;		/* Output row buffer */
	int row_stride;		/* physical row width in output buffer */
	//char buf[250];

	
	/* In this example we want to open the input file before doing anything else,
	* so that the setjmp() error recovery below can assume the file is open.
	* VERY IMPORTANT: use "b" option to fopen() if you are on a machine that
	* requires it in order to read binary files.
	*/
	
	
	
	/* Step 1: allocate and initialize JPEG decompression object */

	/* We set up the normal JPEG error routines, then override error_exit. */
	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = my_error_exit;


	/* Establish the setjmp return context for my_error_exit to use. */
	if (setjmp(jerr.setjmp_buffer)) {
		/* If we get here, the JPEG code has signaled an error.
		 * We need to clean up the JPEG object, close the input file, and return.
		 */

		jpeg_destroy_decompress(&cinfo);

                fprintf(stderr,"(ha ocurrido un error leyendo el jpeg)\n");

		if (infile!=NULL)
			fclose(infile);
		return NULL;
	}

	/* Now we can initialize the JPEG decompression object. */
	jpeg_create_decompress(&cinfo);

	/* Step 2: specify data source (eg, a file) */

	if ( false )
	{
		if ((infile = fopen(fileName, "rb")) == NULL) 
		{
			fprintf(stderr, "JPEG :\nCan't open %s\n", fileName);
			return NULL;
		}	
		jpeg_stdio_src(&cinfo, infile);
	}
	else
	{
		datos_archivo da ;
		leer_archivo(std::string(fileName), da);
		jpeg_memory_src(&cinfo,(JOCTET *)da.bytes, (size_t) da.numBytes );
	}

	/* Step 3: read file parameters with jpeg_read_header() */

	(void) jpeg_read_header(&cinfo, TRUE);
	/* We can ignore the return value from jpeg_read_header since
	*   (a) suspension is not possible with the stdio data source, and
	*   (b) we passed TRUE to reject a tables-only JPEG file as an error.
	* See libjpeg.doc for more info.
	*/

	/* Step 4: set parameters for decompression */

	/* In this example, we don't need to change any of the defaults set by
	* jpeg_read_header(), so we do nothing here.
	*/

	/* Step 5: Start decompressor */

	(void) jpeg_start_decompress(&cinfo);
	/* We can ignore the return value since suspension is not possible
	* with the stdio data source.
	*/

	/* We may need to do some setup of our own at this point before reading
	* the data.  After jpeg_start_decompress() we have the correct scaled
	* output image dimensions available, as well as the output colormap
	* if we asked for color quantization.
	* In this example, we need to make an output work buffer of the right size.
	*/ 

	// get our buffer set to hold data
	unsigned char *dataBuf;

	////////////////////////////////////////////////////////////
	// alloc and open our new buffer
	dataBuf=(unsigned char *)new unsigned char[cinfo.output_width * 3 * cinfo.output_height];
	
	if (dataBuf==NULL) 
	{

		fprintf (stderr, "JpegFile :\nOut of memory\n");

		jpeg_destroy_decompress(&cinfo);
		
		fclose(infile);

		return NULL;
	}

	// how big is this thing gonna be?
	*width = cinfo.output_width;
	*height = cinfo.output_height;
	
	/* JSAMPLEs per row in output buffer */
	row_stride = cinfo.output_width * cinfo.output_components;

	/* Make a one-row-high sample array that will go away when done with image */
	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

	/* Step 6: while (scan lines remain to be read) */
	/*           jpeg_read_scanlines(...); */

	/* Here we use the library's state variable cinfo.output_scanline as the
	* loop counter, so that we don't have to keep track ourselves.
	*/
	while (cinfo.output_scanline < cinfo.output_height) {
		/* jpeg_read_scanlines expects an array of pointers to scanlines.
		 * Here the array is only one element long, but you could ask for
		 * more than one scanline at a time if that's more convenient.
		 */
		(void) jpeg_read_scanlines(&cinfo, buffer, 1);
		/* Assume put_scanline_someplace wants a pointer and sample count. */

		// asuumer all 3-components are RGBs
		if (cinfo.out_color_components==3) {
			
			j_putRGBScanline(buffer[0], 
								*width,
								dataBuf,
								cinfo.output_scanline-1);

		} else if (cinfo.out_color_components==1) {

			// assume all single component images are grayscale
			j_putGrayScanlineToRGB(buffer[0], 
								*width,
								dataBuf,
								cinfo.output_scanline-1);

		}

	}

	/* Step 7: Finish decompression */

	(void) jpeg_finish_decompress(&cinfo);
	/* We can ignore the return value since suspension is not possible
	* with the stdio data source.
	*/

	/* Step 8: Release JPEG decompression object */

	/* This is an important step since it will release a good deal of memory. */
	jpeg_destroy_decompress(&cinfo);

	/* After finish_decompress, we can close the input file.
	* Here we postpone it until after no more JPEG errors are possible,
	* so as to simplify the setjmp error logic above.  (Actually, I don't
	* think that jpeg_destroy can do an error exit, but why assume anything...)
	*/
	if ( infile != NULL )
		fclose(infile);

	/* At this point you may want to check to see whether any corrupt-data
	* warnings occurred (test whether jerr.pub.num_warnings is nonzero).
	*/

	return dataBuf;
}

JPG_BOOL JpegFile::GetJPGDimensions(JPG_CString fileName,
								JPG_UINT *width,
								JPG_UINT *height)

{
	// basic code from IJG Jpeg Code v6 example.c

	/* This struct contains the JPEG decompression parameters and pointers to
	* working space (which is allocated as needed by the JPEG library).
	*/
	struct jpeg_decompress_struct cinfo;
	/* We use our private extension JPEG error handler.
	* Note that this struct must live as long as the main JPEG parameter
	* struct, to avoid dangling-pointer problems.
	*/
	struct my_error_mgr jerr;
	/* More stuff */
	FILE * infile=NULL;		/* source file */
//	char buf[250];

	/* In this example we want to open the input file before doing anything else,
	* so that the setjmp() error recovery below can assume the file is open.
	* VERY IMPORTANT: use "b" option to fopen() if you are on a machine that
	* requires it in order to read binary files.
	*/

	if ((infile = fopen(fileName, "rb")) == NULL) {
		fprintf(stderr, "JPEG :\nCan't open %s\n", fileName);
		return FALSE;
	}

	/* Step 1: allocate and initialize JPEG decompression object */

	/* We set up the normal JPEG error routines, then override error_exit. */
	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = my_error_exit;


	/* Establish the setjmp return context for my_error_exit to use. */
	if (setjmp(jerr.setjmp_buffer)) {
		/* If we get here, the JPEG code has signaled an error.
		 * We need to clean up the JPEG object, close the input file, and return.
		 */

		jpeg_destroy_decompress(&cinfo);

		if (infile!=NULL)
			fclose(infile);
		return FALSE;
	}

	/* Now we can initialize the JPEG decompression object. */
	jpeg_create_decompress(&cinfo);

	/* Step 2: specify data source (eg, a file) */

	jpeg_stdio_src(&cinfo, infile);

	/* Step 3: read file parameters with jpeg_read_header() */

	(void) jpeg_read_header(&cinfo, TRUE);
	/* We can ignore the return value from jpeg_read_header since
	*   (a) suspension is not possible with the stdio data source, and
	*   (b) we passed TRUE to reject a tables-only JPEG file as an error.
	* See libjpeg.doc for more info.
	*/


	// how big is this thing ?
	*width = cinfo.image_width;
	*height = cinfo.image_height;

	/* Step 8: Release JPEG decompression object */

	/* This is an important step since it will release a good deal of memory. */
	jpeg_destroy_decompress(&cinfo);

	/* After finish_decompress, we can close the input file.
	* Here we postpone it until after no more JPEG errors are possible,
	* so as to simplify the setjmp error logic above.  (Actually, I don't
	* think that jpeg_destroy can do an error exit, but why assume anything...)
	*/
	fclose(infile);

	/* At this point you may want to check to see whether any corrupt-data
	* warnings occurred (test whether jerr.pub.num_warnings is nonzero).
	*/

	return TRUE;
}

//
//
//

unsigned char *JpegFile::RGBFromJPG_DWORDAligned(unsigned char *inBuf,
									JPG_UINT widthPix, 
									JPG_UINT widthBytes,
									JPG_UINT height)
{
	if (inBuf==NULL)
		return NULL;


	unsigned char *tmp;
	tmp=(unsigned char *)new unsigned char[height * widthPix * 3];
	if (tmp==NULL)
		return NULL;

	JPG_UINT row;

	for (row=0;row<height;row++) {
		memcpy((tmp+row * widthPix * 3), 
				(inBuf + row * widthBytes), 
				widthPix * 3);
	}

	return tmp;
}

//
//
//

JPG_BOOL JpegFile::RGBToJpegFile(JPG_CString fileName, 
							unsigned char *dataBuf,
							JPG_UINT widthPix,
							JPG_UINT height,
							JPG_BOOL color, 
							int quality)
{
	if (dataBuf==NULL)
		return FALSE;
	if (widthPix==0)
		return FALSE;
	if (height==0)
		return FALSE;

	unsigned char * tmp;
	if (!color) {
		tmp = (unsigned char*)new unsigned char[widthPix*height];
		if (tmp==NULL) {
			fprintf(stderr, "Memory error\n");
			return FALSE;
		}

		JPG_UINT row,col;
		for (row=0;row<height;row++) {
			for (col=0;col<widthPix;col++) {
				unsigned char *pRed, *pGrn, *pBlu;
				pRed = dataBuf + row * widthPix * 3 + col * 3;
				pGrn = dataBuf + row * widthPix * 3 + col * 3 + 1;
				pBlu = dataBuf + row * widthPix * 3 + col * 3 + 2;

				// luminance
				int lum = (int)(.299 * (double)(*pRed) + .587 * (double)(*pGrn) + .114 * (double)(*pBlu));
				unsigned char *pGray;
				pGray = tmp + row * widthPix + col;
				*pGray = (unsigned char)lum;
			}
		}
	}

	struct jpeg_compress_struct cinfo;
	/* More stuff */
	FILE * outfile=NULL;			/* target file */
	//int row_stride;			/* physical row widthPix in image buffer */

	struct my_error_mgr jerr;

	/* Step 1: allocate and initialize JPEG compression object */
	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = my_error_exit;

	/* Establish the setjmp return context for my_error_exit to use. */
	if (setjmp(jerr.setjmp_buffer)) {
		/* If we get here, the JPEG code has signaled an error.
		 * We need to clean up the JPEG object, close the input file, and return.
		 */

		jpeg_destroy_compress(&cinfo);

		if (outfile!=NULL)
			fclose(outfile);

		if (!color) {
			delete [] tmp;
		}
		return FALSE;
	}

	/* Now we can initialize the JPEG compression object. */
	jpeg_create_compress(&cinfo);

	/* Step 2: specify data destination (eg, a file) */
	/* Note: steps 2 and 3 can be done in either order. */

	if ((outfile = fopen(fileName, "wb")) == NULL) {
		fprintf(stderr, "JpegFile :\nCan't open %s\n", fileName);
		return FALSE;
	}

	jpeg_stdio_dest(&cinfo, outfile);

	/* Step 3: set parameters for compression */
												    
	/* First we supply a description of the input image.
	* Four fields of the cinfo struct must be filled in:
	*/
	cinfo.image_width = widthPix; 	/* image widthPix and height, in pixels */
	cinfo.image_height = height;
	if (color) {
		cinfo.input_components = 3;		/* # of color components per pixel */
		cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */
	} else {
		cinfo.input_components = 1;		/* # of color components per pixel */
		cinfo.in_color_space = JCS_GRAYSCALE; 	/* colorspace of input image */
	}

 
/* Now use the library's routine to set default compression parameters.
   * (You must set at least cinfo.in_color_space before calling this,
   * since the defaults depend on the source color space.)
   */

  jpeg_set_defaults(&cinfo);
  /* Now you can set any non-default parameters you wish to.
   * Here we just illustrate the use of quality (quantization table) scaling:
   */
  jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);

  /* Step 4: Start compressor */

  /* TRUE ensures that we will write a complete interchange-JPEG file.
   * Pass TRUE unless you are very sure of what you're doing.
   */
  jpeg_start_compress(&cinfo, TRUE);

  /* Step 5: while (scan lines remain to be written) */
  /*           jpeg_write_scanlines(...); */

  /* Here we use the library's state variable cinfo.next_scanline as the
   * loop counter, so that we don't have to keep track ourselves.
   * To keep things simple, we pass one scanline per call; you can pass
   * more if you wish, though.
   */
  //row_stride = widthPix * 3;	/* JSAMPLEs per row in image_buffer */

  while (cinfo.next_scanline < cinfo.image_height) {
    /* jpeg_write_scanlines expects an array of pointers to scanlines.
     * Here the array is only one element long, but you could pass
     * more than one scanline at a time if that's more convenient.
     */
	unsigned char *outRow;
	if (color) {
		outRow = dataBuf + (cinfo.next_scanline * widthPix * 3);
	} else {
		outRow = tmp + (cinfo.next_scanline * widthPix);
	}

    (void) jpeg_write_scanlines(&cinfo, &outRow, 1);
  }

  /* Step 6: Finish compression */

  jpeg_finish_compress(&cinfo);

  /* After finish_compress, we can close the output file. */
  fclose(outfile);

  /* Step 7: release JPEG compression object */

  /* This is an important step since it will release a good deal of memory. */
  jpeg_destroy_compress(&cinfo);

  if (!color)
	  delete [] tmp;
  /* And we're done! */

  return TRUE;
}

//
//	stash a scanline
//

void j_putRGBScanline(unsigned char *jpegline, 
					 int widthPix,
					 unsigned char *outBuf,
					 int row)
{
	int offset = row * widthPix * 3;
	int count;
	for (count=0;count<widthPix;count++) 
	{
		*(outBuf + offset + count * 3 + 0) = *(jpegline + count * 3 + 0);
		*(outBuf + offset + count * 3 + 1) = *(jpegline + count * 3 + 1);
		*(outBuf + offset + count * 3 + 2) = *(jpegline + count * 3 + 2);
	}
}

//
//	stash a gray scanline
//

void j_putGrayScanlineToRGB(unsigned char *jpegline, 
							 int widthPix,
							 unsigned char *outBuf,
							 int row)
{
	int offset = row * widthPix * 3;
	int count;
	for (count=0;count<widthPix;count++) {

		unsigned char iGray;

		// get our grayscale value
		iGray = *(jpegline + count);

		*(outBuf + offset + count * 3 + 0) = iGray;
		*(outBuf + offset + count * 3 + 1) = iGray;
		*(outBuf + offset + count * 3 + 2) = iGray;
	}
}

//
// copies unsigned char buffer into JPG_DWORD-aligned unsigned char buffer
// return addr of new buffer
//

unsigned char * JpegFile::MakeJPG_DWORDAlignedBuf(unsigned char *dataBuf,
									 JPG_UINT widthPix,				// pixels!!
									 JPG_UINT height,
									 JPG_UINT *uiOutWidthBytes)		// bytes!!!
{
	////////////////////////////////////////////////////////////
	// what's going on here? this certainly means trouble 
	if (dataBuf==NULL)
		return NULL;

	////////////////////////////////////////////////////////////
	// how big is the smallest JPG_DWORD-aligned buffer that we can use?
	JPG_UINT uiWidthBytes;
	uiWidthBytes = WIDTHBYTES(widthPix * 24);

	JPG_DWORD dwNewsize=(JPG_DWORD)((JPG_DWORD)uiWidthBytes * 
							(JPG_DWORD)height);
	unsigned char *pNew;

	////////////////////////////////////////////////////////////
	// alloc and open our new buffer
	pNew=(unsigned char *)new unsigned char[dwNewsize];
	if (pNew==NULL) {
		return NULL;
	}
	
	////////////////////////////////////////////////////////////
	// copy row-by-row
	JPG_UINT uiInWidthBytes = widthPix * 3;
	JPG_UINT uiCount;
	for (uiCount=0;uiCount < height;uiCount++) {
		unsigned char * bpInAdd;
		unsigned char * bpOutAdd;
		JPG_ULONG lInOff;
		JPG_ULONG lOutOff;

		lInOff=uiInWidthBytes * uiCount;
		lOutOff=uiWidthBytes * uiCount;

		bpInAdd= dataBuf + lInOff;
		bpOutAdd= pNew + lOutOff;

		memcpy(bpOutAdd,bpInAdd,uiInWidthBytes);
	}

	*uiOutWidthBytes=uiWidthBytes;
	return pNew;
}

//
//	vertically flip a buffer 
//	note, this operates on a buffer of widthBytes bytes, not pixels!!!
//

JPG_BOOL JpegFile::VertFlipBuf(unsigned char  * inbuf, 
					   JPG_UINT widthBytes, 
					   JPG_UINT height)
{   
	unsigned char  *tb1;
	unsigned char  *tb2;

	if (inbuf==NULL)
		return FALSE;

	JPG_UINT bufsize;

	bufsize=widthBytes;

	tb1= (unsigned char *)new unsigned char[bufsize];
	if (tb1==NULL) {
		return FALSE;
	}

	tb2= (unsigned char *)new unsigned char [bufsize];
	if (tb2==NULL) {
		delete [] tb1;
		return FALSE;
	}
	
	JPG_UINT row_cnt;     
	JPG_ULONG off1=0;
	JPG_ULONG off2=0;

	for (row_cnt=0;row_cnt<(height+1)/2;row_cnt++) {
		off1=row_cnt*bufsize;
		off2=((height-1)-row_cnt)*bufsize;   
		
		memcpy(tb1,inbuf+off1,bufsize);
		memcpy(tb2,inbuf+off2,bufsize);	
		memcpy(inbuf+off1,tb2,bufsize);
		memcpy(inbuf+off2,tb1,bufsize);
	}	

	delete [] tb1;
	delete [] tb2;

	return TRUE;
}        


//
//	swap Rs and Bs
//
//	Note! this does its stuff on buffers with a whole number of pixels
//	per data row!!
//


JPG_BOOL JpegFile::BGRFromRGB(unsigned char *buf, JPG_UINT widthPix, JPG_UINT height)
{
	if (buf==NULL)
		return FALSE;

	JPG_UINT col, row;
	for (row=0;row<height;row++) {
		for (col=0;col<widthPix;col++) {
			unsigned char *pRed, //*pGrn, 
                    *pBlu;
			pRed = buf + row * widthPix * 3 + col * 3;
			//pGrn = buf + row * widthPix * 3 + col * 3 + 1;
			pBlu = buf + row * widthPix * 3 + col * 3 + 2;

			// swap red and blue
			unsigned char tmp;
			tmp = *pRed;
			*pRed = *pBlu;
			*pBlu = tmp;
		}
	}
	return TRUE;
}

//
//	Note! this does its stuff on buffers with a whole number of pixels
//	per data row!!
//

JPG_BOOL JpegFile::MakeGrayScale(unsigned char *buf, JPG_UINT widthPix, JPG_UINT height)
{
	if (buf==NULL)
		return FALSE;

	JPG_UINT row,col;
	for (row=0;row<height;row++) {
		for (col=0;col<widthPix;col++) {
			unsigned char *pRed, *pGrn, *pBlu;
			pRed = buf + row * widthPix * 3 + col * 3;
			pGrn = buf + row * widthPix * 3 + col * 3 + 1;
			pBlu = buf + row * widthPix * 3 + col * 3 + 2;

			// luminance
			int lum = (int)(.299 * (double)(*pRed) + .587 * (double)(*pGrn) + .114 * (double)(*pBlu));

			*pRed = (unsigned char)lum;
			*pGrn = (unsigned char)lum;
			*pBlu = (unsigned char)lum;
		}
	}
	return TRUE;
}


} // fin namespace VR
