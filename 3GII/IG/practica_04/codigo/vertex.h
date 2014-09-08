//**************************************************************************
// Class for definng vertices
//
// Domingo Martin Perandres 2003,2004,2005,2006,2007
//
// GPL3
//
// ultima actualizacion 20071010
//**************************************************************************


#pragma interface

#ifndef _VERTEX
#define _VERTEX

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <iostream>
//#include "error.h"

using namespace std;

typedef enum {VERTEX_BEHIND_PLANE,VERTEX_AHEAD_PLANE,VERTEX_IN_PLANE} _vertex_position;

const float COPLANE_THRESHOLD=1e-12;
const float MAX_FLOAT_VALUE=1e99;


template <class Type> class _matrix4;

template <class Type> class _vertex2;
template <class Type> class _vertex3;
template <class Type> class _vertex4;

//*************************************************************************
//
//*************************************************************************

template <class Type>
class _vertex2
{

public:

union {
Type x;
Type r;
Type s;
Type _0;
Type row;
};

union {
Type y;
Type g;
Type t;
Type _1;
Type col;
};


				 	_vertex2(Type x1=0,Type y1=0);
				 	_vertex2(const _vertex2<Type> &Vertex1);
					_vertex2(const _vertex3<Type> &Vertex1);
					_vertex2(const _vertex4<Type> &Vertex1);
_vertex2 	&operator()(Type x1,Type y1); // like equal
_vertex2 	&operator()(Type *Vertices1);
_vertex2 	&operator()(const _vertex2<Type> &Vertex1);
_vertex2 	&operator()(const _vertex3<Type> &Vertex1);
_vertex2 	&operator()(const _vertex4<Type> &Vertex1);
_vertex2 	&operator=(const _vertex2<Type> &Vertex1);
_vertex2 	&operator=(const _vertex3<Type> &Vertex1);
_vertex2 	&operator=(const _vertex4<Type> &Vertex1);
_vertex2 	&operator=(Type *Vertices1);

_vertex2 	operator+(const _vertex2<Type> &Vertex1);
_vertex2 	&operator+=(const _vertex2<Type> &Vertex1);
_vertex2 	operator-(const _vertex2<Type> &Vertex1);
_vertex2 	&operator-=(const _vertex2<Type> &Vertex1);

_vertex2 	operator*(Type Value);
_vertex2 	&operator*=(Type Value);
_vertex2 	operator/(Type Value);
_vertex2 	&operator/=(Type Value);

Type 			dot_product(const _vertex2<Type> &Vertex1)
										{return(x*Vertex1.x+y*Vertex1.y);};
bool			operator==(const _vertex2<Type> &Vertex1);
bool			operator!=(const _vertex2<Type> &Vertex1);

_vertex2 	&normalize();
double		module(){return (sqrt(x*x+y*y));};
_vertex2 	clone(){_vertex2<Type> Vertex1(*this);return Vertex1;};


inline 	Type &operator[](int Position){return *(&x+Position);};

void show_values();
};


//*************************************************************************
//
//*************************************************************************

template <class Type>
class _vertex3
{

public:

union {
Type x;
Type r;
Type s;
Type _0;
};

union {
Type y;
Type g;
Type t;
Type _1;
};

union {
Type z;
Type b;
Type u;
Type _2;
};

				 	_vertex3(Type x1=0,Type y1=0,Type z1=0);
					_vertex3(const _vertex2<Type> &Vertex1);
				 	_vertex3(const _vertex3<Type> &Vertex1);
					_vertex3(const _vertex4<Type> &Vertex1);

_vertex3 	&operator()(Type x1,Type y1,Type z1); // like equal
_vertex3 	&operator()(Type *Vertices1);
_vertex3 	&operator()(const _vertex2<Type> &Vertex1);
_vertex3 	&operator()(const _vertex3<Type> &Vertex1);
_vertex3 	&operator()(const _vertex4<Type> &Vertex1);
_vertex3 	&operator=(const _vertex2<Type> &Vertex1);
_vertex3 	&operator=(const _vertex3<Type> &Vertex1);
_vertex3 	&operator=(const _vertex4<Type> &Vertex1);
_vertex3 	&operator=(Type *Vertices1);
_vertex3 	operator+(const _vertex3<Type> &Vertex1);
_vertex3 	&operator+=(const _vertex3<Type> &Vertex1);
_vertex3 	operator-(const _vertex3<Type> &Vertex1);
_vertex3 	&operator-=(const _vertex3<Type> &Vertex1);
_vertex3 	operator*(Type Value);
_vertex3 	&operator*=(Type Value);
_vertex3 	operator*(_matrix4<Type> &Matrix1);
_vertex3 	&operator*=(_matrix4<Type> &Matrix1);
_vertex3 	operator/(Type Value);
_vertex3 	&operator/=(Type Value);
Type 			dot_product(const _vertex3<Type> &Vertex1)
										{return(x*Vertex1.x+y*Vertex1.y+z*Vertex1.z);};
_vertex3	cross_product(const _vertex3<Type> &Vertex1);
bool			operator==(const _vertex3<Type> &Vertex1);
bool			operator==(const _vertex2<Type> &Vertex1);
bool			operator!=(const _vertex3<Type> &Vertex1);
bool			operator!=(const _vertex2<Type> &Vertex1);
bool			equal_coordinates(int Num_coordinates1);

_vertex3 	&normalize();
double		module(){return (sqrt(x*x+y*y+z*z));};
_vertex3 	clone(){_vertex3<Type> Vertex1(*this);return Vertex1;};

_vertex3<unsigned char> to_byte();
_vertex3 &from_byte(_vertex3<unsigned char> &Vertex1);

Type			compute_angle(const _vertex3<Type> &Vertex1);

inline 	Type &operator[](int Position){return *(&x+Position);};
void 	show_values();
};


//*************************************************************************
//
//*************************************************************************

template <class Type>
class _vertex4
{

public:

union {
Type x;
Type r;
Type s;
Type _0;
};

union {
Type y;
Type g;
Type t;
Type _1;
};

union {
Type z;
Type b;
Type u;
Type _2;
};

union {
Type w;
Type a;
Type v;
Type _3;
};

				 	_vertex4(Type x1=0,Type y1=0,Type z1=0,Type w1=0);
					_vertex4(const _vertex2<Type> &Vertex1);
				 	_vertex4(const _vertex3<Type> &Vertex1);
					_vertex4(const _vertex4<Type> &Vertex1);

_vertex4 	&operator()(Type x1,Type y1,Type z1,Type w1=0); // like equal
_vertex4 	&operator()(Type *Vertices1);
_vertex4 	&operator()(const _vertex2<Type> &Vertex1);
_vertex4 	&operator()(const _vertex3<Type> &Vertex1);
_vertex4 	&operator()(const _vertex4<Type> &Vertex1);
_vertex4 	&operator=(const _vertex2<Type> &Vertex1);
_vertex4 	&operator=(const _vertex3<Type> &Vertex1);
_vertex4 	&operator=(const _vertex4<Type> &Vertex1);
_vertex4 	&operator=(Type *Vertices1);
_vertex4 	operator+(const _vertex4<Type> &Vertex1);
_vertex4 	&operator+=(const _vertex4<Type> &Vertex1);
_vertex4 	operator-(const _vertex4<Type> &Vertex1);
_vertex4 	&operator-=(const _vertex4<Type> &Vertex1);
_vertex4 	operator*(Type Value);
_vertex4 	&operator*=(Type Value);
_vertex4 	operator*(_matrix4<Type> &Matrix1);
_vertex4 	&operator*=(_matrix4<Type> &Matrix1);
_vertex4 	operator/(Type Value);
_vertex4 	&operator/=(Type Value);
bool			operator==(const _vertex4<Type> &Vertex1);
bool			operator!=(const _vertex4<Type> &Vertex1);


_vertex4 	&project();
Type 			dot_product(const _vertex4<Type> &Vertex1)
										{return(x*Vertex1.x+y*Vertex1.y+z*Vertex1.z+w*Vertex1.w);};
_vertex4 	&normalize();
double		module(){return (sqrt(x*x+y*y+z*z+w*w));};
_vertex4 	clone(){_vertex4 Vertex1(*this);return Vertex1;};

inline 	Type &operator[](int Position){return *(&x+Position);};

_vertex4<unsigned char> to_byte();
_vertex4 &from_byte(_vertex4<unsigned char> &Vertex1);

void		show_values();
};

//*************************************************************************
// 030421
// auxiliar classes
//*************************************************************************

template <class Type>
class _plane:public _vertex4<Type>
{
public:

		         				_plane(Type x1=0,Type y1=0,Type z1=0,Type w1=0);
                		_plane(const _vertex4<Type> &Vertex1);
_plane<Type>				&operator=(_plane &Plane1);
int									compute_coefficients(_vertex3<Type> Vertex1,
													_vertex3<Type> Vertex2,_vertex3<Type> Vertex3);

_vertex_position		compute_vertex_position(_vertex3<Type> Vertex1);
_vertex3<Type>			normal();
void				show_values();
};


//*************************************************************************
// 030421
//
//
//*************************************************************************

template <class Type>
class _bounding_box3
{
public:
_vertex3<Type> Minimum,Maximum;
bool Computed;

      _bounding_box3(Type XMin1=(Type) MAX_FLOAT_VALUE, Type YMin1=(Type) MAX_FLOAT_VALUE, Type ZMin1=(Type) MAX_FLOAT_VALUE, Type XMax1=- (Type)MAX_FLOAT_VALUE, Type YMax1=-(Type)MAX_FLOAT_VALUE, Type ZMax1=-(Type)MAX_FLOAT_VALUE);
			_bounding_box3(const _bounding_box3<Type> &Bounding_box1);
_bounding_box3<Type> compute(const _vertex3<Type> &Vertex1);
_bounding_box3<Type> compute(_bounding_box3<Type> &Bounding_box1);

_vertex3<Type>	center();
Type 	max_value();
Type 	min_value();
void	show_values();
};


//*************************************************************************
//
//*************************************************************************

typedef _vertex2<unsigned char> 		_vertex2uc;
typedef _vertex2<char> 		_vertex2c;
typedef _vertex2<unsigned int> 		_vertex2ui;
typedef _vertex2<int> 		_vertex2i;
typedef _vertex2<float> 	_vertex2f;
typedef _vertex2<double> 	_vertex2d;

typedef _vertex3<unsigned char> 		_vertex3uc;
typedef _vertex3<char> 		_vertex3c;
typedef _vertex3<unsigned int> 		_vertex3ui;
typedef _vertex3<int> 		_vertex3i;
typedef _vertex3<float> 	_vertex3f;
typedef _vertex3<double> 	_vertex3d;

typedef _vertex4<unsigned char> 		_vertex4uc;
typedef _vertex4<char> 		_vertex4c;
typedef _vertex4<unsigned int> 		_vertex4ui;
typedef _vertex4<int> 		_vertex4i;
typedef _vertex4<float> 	_vertex4f;
typedef _vertex4<double> 	_vertex4d;

typedef _vertex3f	_color3f;
typedef _vertex3d _color3d;
typedef _vertex4f	_color4f;
typedef _vertex4d _color4d;

typedef _plane<float> _planef;
typedef _plane<double> _planed;

typedef _bounding_box3<float> _bounding_box3f;
typedef _bounding_box3<double> _bounding_box3d;

//*************************************************************************
// 030322
//*************************************************************************
//*************************************************************************
// Vertex2
//*************************************************************************

template <class Type> _vertex2<Type>::_vertex2(Type x1,Type y1)
{

x=x1;
y=y1;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type>::_vertex2(const _vertex2<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type>::_vertex2(const _vertex3<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type>::_vertex2(const _vertex4<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
}


//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator()(Type x1,Type y1)
{
x=x1;
y=y1;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator()(const _vertex2<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator()(const _vertex3<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator()(const _vertex4<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator()(Type *Vertices1)
{
x=Vertices1[0];
y=Vertices1[1];
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator=(const _vertex2<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}


//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator=(const _vertex3<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator=(const _vertex4<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator=(Type *Vertices1)
{
x=Vertices1[0];
y=Vertices1[1];
return(*this);
}

//*************************************************************************
// 20071010
//*************************************************************************

template <class Type> _vertex2<Type>
_vertex2<Type>::operator+(const _vertex2<Type> &Vertex1)
{
_vertex2<Type> VertexTemp(*this);

VertexTemp.x+=Vertex1.x;
VertexTemp.y+=Vertex1.y;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator+=(const _vertex2<Type> &Vertex1)
{

x+=Vertex1.x;
y+=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type>
_vertex2<Type>::operator-(const _vertex2<Type> &Vertex1)
{
_vertex2<Type> VertexTemp(*this);

VertexTemp.x-=Vertex1.x;
VertexTemp.y-=Vertex1.y;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator-=(const _vertex2<Type> &Vertex1)
{

x-=Vertex1.x;
y-=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type>
_vertex2<Type>::operator*(Type Value)
{
_vertex2<Type> VertexTemp(*this);

VertexTemp.x*=Value;
VertexTemp.y*=Value;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator*=(Type Value)
{

x*=Value;
y*=Value;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type>
_vertex2<Type>::operator/(Type Value)
{
_vertex2<Type> VertexTemp(*this);

VertexTemp.x/=Value;
VertexTemp.y/=Value;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::operator/=(Type Value)
{

x/=Value;
y/=Value;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> bool
_vertex2<Type>::operator==(const _vertex2<Type> &Vertex1)
{

if (x==Vertex1.x && y==Vertex1.y) return true;
return false;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> bool
_vertex2<Type>::operator!=(const _vertex2<Type> &Vertex1)
{

return !((*this)==(Vertex1));
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex2<Type> &
_vertex2<Type>::normalize()
{
Type Module=this->module();

x/=Module;
y/=Module;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************


template <class Type> void
_vertex2<Type>::show_values()
{

	cout << "x=" << x << " y=" << y << endl;
}

//*************************************************************************
// 030322
//*************************************************************************
//*************************************************************************
// Vertex3
//*************************************************************************

template <class Type> _vertex3<Type>::_vertex3(Type x1,Type y1,Type z1)
{

x=x1;
y=y1;
z=z1;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>::_vertex3(const _vertex2<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>::_vertex3(const _vertex3<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>::_vertex3(const _vertex4<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
}


//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator()(Type x1,Type y1,Type z1)
{
x=x1;
y=y1;
z=z1;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator()(const _vertex2<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator()(const _vertex3<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator()(const _vertex4<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator()(Type *Vertices1)
{
x=Vertices1[0];
y=Vertices1[1];
z=Vertices1[2];
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator=(const _vertex2<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}


//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator=(const _vertex3<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator=(const _vertex4<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator=(Type *Vertices1)
{
x=Vertices1[0];
y=Vertices1[1];
z=Vertices1[2];
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>
_vertex3<Type>::operator+(const _vertex3<Type> &Vertex1)
{
_vertex3<Type> VertexTemp(*this);

VertexTemp.x+=Vertex1.x;
VertexTemp.y+=Vertex1.y;
VertexTemp.z+=Vertex1.z;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator+=(const _vertex3<Type> &Vertex1)
{

x+=Vertex1.x;
y+=Vertex1.y;
z+=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>
_vertex3<Type>::operator-(const _vertex3<Type> &Vertex1)
{
_vertex3<Type> VertexTemp(*this);

VertexTemp.x-=Vertex1.x;
VertexTemp.y-=Vertex1.y;
VertexTemp.z-=Vertex1.z;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator-=(const _vertex3<Type> &Vertex1)
{

x-=Vertex1.x;
y-=Vertex1.y;
z-=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>
_vertex3<Type>::operator*(Type Value)
{
_vertex3<Type> VertexTemp(*this);

VertexTemp.x*=Value;
VertexTemp.y*=Value;
VertexTemp.z*=Value;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator*=(Type Value)
{

x*=Value;
y*=Value;
z*=Value;
return(*this);
}

//*************************************************************************
// 031007
//*************************************************************************

template <class Type> _vertex3<Type>
_vertex3<Type>::operator*(_matrix4<Type> &Matrix1)
{
_vertex3<Type> VertexTemp(*this);
_vertex4f Vertex1(*this);
_vertex4f Colum1(Matrix1.get(0,0),Matrix1.get(1,0),Matrix1.get(2,0),Matrix1.get(3,0)),
Colum2(Matrix1.get(0,1),Matrix1.get(1,1),Matrix1.get(2,1),Matrix1.get(3,1)),
Colum3(Matrix1.get(0,2),Matrix1.get(1,2),Matrix1.get(2,2),Matrix1.get(3,2));

Vertex1.w=1.;

VertexTemp.x=Vertex1.dot_product(Colum1);
VertexTemp.y=Vertex1.dot_product(Colum2);
VertexTemp.z=Vertex1.dot_product(Colum3);
return(VertexTemp);
}

//*************************************************************************
// 031007
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator*=(_matrix4<Type> &Matrix1)
{
_vertex4f Vertex1=*this;
_vertex4f Colum1(Matrix1.get(0,0),Matrix1.get(1,0),Matrix1.get(2,0),Matrix1.get(3,0)),
Colum2(Matrix1.get(0,1),Matrix1.get(1,1),Matrix1.get(2,1),Matrix1.get(3,1)),
Colum3(Matrix1.get(0,2),Matrix1.get(1,2),Matrix1.get(2,2),Matrix1.get(3,2));

Vertex1.w=1.;

x=Vertex1.dot_product(Colum1);
y=Vertex1.dot_product(Colum2);
z=Vertex1.dot_product(Colum3);
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>
_vertex3<Type>::operator/(Type Value)
{
_vertex3<Type> VertexTemp(*this);

VertexTemp.x/=Value;
VertexTemp.y/=Value;
VertexTemp.z/=Value;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::operator/=(Type Value)
{

x/=Value;
y/=Value;
z/=Value;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type>
_vertex3<Type>::cross_product(const _vertex3<Type> &Vertex1)
{
_vertex3<Type> VertexTemp(*this),VertexTemp1;

VertexTemp1.x=y*Vertex1.z-z*Vertex1.y;
VertexTemp1.y=z*Vertex1.x-x*Vertex1.z;
VertexTemp1.z=x*Vertex1.y-y*Vertex1.x;
return(VertexTemp1);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> bool
_vertex3<Type>::operator==(const _vertex3<Type> &Vertex1)
{

if (x==Vertex1.x && y==Vertex1.y && z==Vertex1.z) return true;
return false;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> bool
_vertex3<Type>::operator==(const _vertex2<Type> &Vertex1)
{

if (x==Vertex1.x && y==Vertex1.y) return true;
return false;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> bool
_vertex3<Type>::operator!=(const _vertex3<Type> &Vertex1)
{

return !((*this)==Vertex1);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> bool
_vertex3<Type>::operator!=(const _vertex2<Type> &Vertex1)
{

return !((*this)==(Vertex1));
}

//*************************************************************************
// 030421
//*************************************************************************

template <class Type> bool
_vertex3<Type>::equal_coordinates(int Num_coordinates1)
{

if (Num_coordinates1>2)
	{
	if (x==y && y==z) return true;
	return false;
	}
if (Num_coordinates1==2)
	{
	if (x==y || y==z || x==z) return true;
	return false;
	}
return true;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::normalize()
{
Type Module=this->module();

x/=Module;
y/=Module;
z/=Module;
return(*this);
}

//*************************************************************************
// 030426
//*************************************************************************

template <class Type> _vertex3<unsigned char>
_vertex3<Type>::to_byte()
{
_vertex3<unsigned char> Color1;

Color1.r=(int) (r*(Type) 255);
Color1.g=(int) (g*(Type) 255);
Color1.b=(int) (b*(Type) 255);
return(Color1);
}

//*************************************************************************
// 030426
//*************************************************************************

template <class Type> _vertex3<Type> &
_vertex3<Type>::from_byte(_vertex3<unsigned char> &Vertex1)
{
r=(Type) Vertex1.r/(Type) 255.;
g=(Type) Vertex1.g/(Type) 255.;
b=(Type) Vertex1.b/(Type) 255.;
return(*this);
}

//*************************************************************************
// 031111
// Funcion que calcula el angulo entre dos vectores, usando el
// coseno y el seno (producto escalar y vectorial). Los vectores
// deben estar normalizados. Se devuelve el valor del angulo
// entre 0 y PI para figuras concavas, y de PI a 2*PI para convexas
//*************************************************************************

template <class Type> Type
_vertex3<Type>::compute_angle(const _vertex3<Type> &Vertex1)
{
_vertex3f Auxiliar;
float cosine,sine;

cosine=this->dot_product(Vertex1);
Auxiliar=this->cross_product(Vertex1);
sine=Auxiliar.module();
return (atan2(sine,cosine));
}


//*************************************************************************
// 030322
//*************************************************************************


template <class Type> void
_vertex3<Type>::show_values()
{

	cout << "x=" << x << " y=" << y << " z=" << z << endl;
}


//*************************************************************************
// 030322
//*************************************************************************
//*************************************************************************
// Vertex4
//*************************************************************************

template <class Type> _vertex4<Type>::_vertex4(Type x1,Type y1,Type z1,Type w1)
{
  
x=x1;
y=y1;
z=z1;
w=w1;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>::_vertex4(const _vertex2<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>::_vertex4(const _vertex3<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>::_vertex4(const _vertex4<Type> &Vertex1)
{

x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
w=Vertex1.w;
}


//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator()(Type x1,Type y1,Type z1,Type w1)
{
x=x1;
y=y1;
z=z1;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator()(const _vertex2<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator()(const _vertex3<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator()(const _vertex4<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
w=Vertex1.w;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator()(Type *Vertices1)
{
x=Vertices1[0];
y=Vertices1[1];
z=Vertices1[2];
w=Vertices1[3];
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator=(const _vertex2<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
return(*this);
}


//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator=(const _vertex3<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator=(const _vertex4<Type> &Vertex1)
{
x=Vertex1.x;
y=Vertex1.y;
z=Vertex1.z;
w=Vertex1.w;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator=(Type *Vertices1)
{
x=Vertices1[0];
y=Vertices1[1];
z=Vertices1[2];
w=Vertices1[3];
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>
_vertex4<Type>::operator+(const _vertex4<Type> &Vertex1)
{
_vertex4<Type> VertexTemp(*this);

VertexTemp.x+=Vertex1.x;
VertexTemp.y+=Vertex1.y;
VertexTemp.z+=Vertex1.z;
VertexTemp.w+=Vertex1.w;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator+=(const _vertex4<Type> &Vertex1)
{

x+=Vertex1.x;
y+=Vertex1.y;
z+=Vertex1.z;
w+=Vertex1.w;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>
_vertex4<Type>::operator-(const _vertex4<Type> &Vertex1)
{
_vertex4<Type> VertexTemp(*this);

VertexTemp.x-=Vertex1.x;
VertexTemp.y-=Vertex1.y;
VertexTemp.z-=Vertex1.z;
VertexTemp.w-=Vertex1.w;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator-=(const _vertex4<Type> &Vertex1)
{

x-=Vertex1.x;
y-=Vertex1.y;
z-=Vertex1.z;
w-=Vertex1.w;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>
_vertex4<Type>::operator*(Type Value)
{
_vertex4<Type> VertexTemp(*this);

VertexTemp.x*=Value;
VertexTemp.y*=Value;
VertexTemp.z*=Value;
VertexTemp.w*=Value;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator*=(Type Value)
{

x*=Value;
y*=Value;
z*=Value;
w*=Value;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>
_vertex4<Type>::operator*(_matrix4<Type> &Mat1)
{
_vertex4<Type> Vertex1(*this),Vertex2;

Vertex2.x=Vertex1.x*Mat1.get(0,0)+Vertex1.y*Mat1.get(1,0)+
			 Vertex1.z*Mat1.get(2,0)+Vertex1.w*Mat1.get(3,0);
Vertex2.y=Vertex1.x*Mat1.get(0,1)+Vertex1.y*Mat1.get(1,1)+
			 Vertex1.z*Mat1.get(2,1)+Vertex1.w*Mat1.get(3,1);
Vertex2.z=Vertex1.x*Mat1.get(0,2)+Vertex1.y*Mat1.get(1,2)+
			 Vertex1.z*Mat1.get(2,2)+Vertex1.w*Mat1.get(3,2);
Vertex2.w=Vertex1.x*Mat1.get(0,3)+Vertex1.y*Mat1.get(1,3)+
			 Vertex1.z*Mat1.get(2,3)+Vertex1.w*Mat1.get(3,3);
return(Vertex2);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator*=(_matrix4<Type> &Mat1)
{
_vertex4<Type> Vertex1(*this);

this->x=Vertex1.x*Mat1.get(0,0)+Vertex1.y*Mat1.get(1,0)+
			 Vertex1.z*Mat1.get(2,0)+Vertex1.w*Mat1.get(3,0);
this->y=Vertex1.x*Mat1.get(0,1)+Vertex1.y*Mat1.get(1,1)+
			 Vertex1.z*Mat1.get(2,1)+Vertex1.w*Mat1.get(3,1);
this->z=Vertex1.x*Mat1.get(0,2)+Vertex1.y*Mat1.get(1,2)+
			 Vertex1.z*Mat1.get(2,2)+Vertex1.w*Mat1.get(3,2);
this->w=Vertex1.x*Mat1.get(0,3)+Vertex1.y*Mat1.get(1,3)+
			 Vertex1.z*Mat1.get(2,3)+Vertex1.w*Mat1.get(3,3);
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type>
_vertex4<Type>::operator/(Type Value)
{
_vertex4<Type> VertexTemp(*this);

VertexTemp.x/=Value;
VertexTemp.y/=Value;
VertexTemp.z/=Value;
VertexTemp.w/=Value;
return(VertexTemp);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::operator/=(Type Value)
{

x/=Value;
y/=Value;
z/=Value;
w/=Value;
return(*this);
}

//*************************************************************************
// 061223
//*************************************************************************

template <class Type> bool
_vertex4<Type>::operator==(const _vertex4<Type> &Vertex1)
{

if (x==Vertex1.x && y==Vertex1.y && z==Vertex1.z && w==Vertex1.w) return true;
return false;
}

//*************************************************************************
// 061223
//*************************************************************************

template <class Type> bool
_vertex4<Type>::operator!=(const _vertex4<Type> &Vertex1)
{

return !((*this)==Vertex1);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::project()
{

if (w!=0)
	{
	if (w!=1)
		{
		x=x/w;
		y=y/w;
		z=z/w;
		w=1;
		}
	}
else assert(w!=0);
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::normalize()
{
Type Module=this->module();

x/=Module;
y/=Module;
z/=Module;
w/=Module;
return(*this);
}

//*************************************************************************
// 030426
//*************************************************************************

template <class Type> _vertex4<unsigned char>
_vertex4<Type>::to_byte()
{
_vertex4<unsigned char> Color1;

Color1.r=(int) (r*(Type) 255);
Color1.g=(int) (g*(Type) 255);
Color1.b=(int) (b*(Type) 255);
Color1.a=(int) (a*(Type) 255);
return(Color1);
}

//*************************************************************************
// 030426
//*************************************************************************

template <class Type> _vertex4<Type> &
_vertex4<Type>::from_byte(_vertex4<unsigned char> &Vertex1)
{
r=(Type) Vertex1.r/(Type) 255.;
g=(Type) Vertex1.g/(Type) 255.;
b=(Type) Vertex1.b/(Type) 255.;
a=(Type) Vertex1.a/(Type) 255.;
return(*this);
}

//*************************************************************************
// 030322
//*************************************************************************


template <class Type> void
_vertex4<Type>::show_values()
{

	cout << "x=" << x << " y=" << y << " z=" << z << " w=" << w << endl;
}


//*************************************************************************
// 030421
//*************************************************************************
//*************************************************************************
//
//*************************************************************************

template <class Type>
_plane<Type>::_plane(Type x1,Type y1,Type z1,Type w1)
{

this->x=x1;
this->y=y1;
this->z=z1;
this->w=w1;
}

//*************************************************************************
//
//*************************************************************************

template <class Type>
_plane<Type>::_plane(const _vertex4<Type> &Vertex1)
{

this->x=Vertex1.x;
this->y=Vertex1.y;
this->z=Vertex1.z;
this->w=Vertex1.w;
}

//*************************************************************************
//
//*************************************************************************

template <class Type>
_plane<Type> &_plane<Type>::operator=(_plane<Type> &Plane1)
{

this->x=Plane1.x;
this->y=Plane1.y;
this->z=Plane1.z;
this->w=Plane1.w;
return *this;
}

//*************************************************************************
// Computes the plane coefficents with the vector product
// Given Vertex1,vertex2 and Vertex3, the 1 vector is computed as
// v1=Vertex2-Vertex1, and the second as
// v2=Vertex
//*************************************************************************

template <class Type>
int	_plane<Type>::compute_coefficients(_vertex3<Type> Vertex1,_vertex3<Type> Vertex2,_vertex3<Type> Vertex3)
{
_vertex3<Type> v1,v2,v3,Vertex_aux1(Vertex1);
float Mod;

v1=Vertex1-Vertex2;
v2=Vertex3-Vertex2;
v3=v2.cross_product(v1);
if ((v3.equal_coordinates(3) && v3.x==0)==true)
  {
  //printf("Warning: plane.compute_coefficients->3 coordenates are equals and 0 %s %d",__FILE__,__LINE__);
 	return(-1);
  }

Mod=v3.module();
assert(Mod!=0);
this->x=v3.x/Mod;
this->y=v3.y/Mod;
this->z=v3.z/Mod;
this->w=-this->x*Vertex_aux1.x-this->y*Vertex_aux1.y-this->z*Vertex_aux1.z;
return 0;
}

//*************************************************************************
//
//*************************************************************************

template <class Type> _vertex_position _plane<Type>::compute_vertex_position(_vertex3<Type> Vertex1)
{
double Result;

Result=this->x*Vertex1.x+this->y*Vertex1.y+this->z*Vertex1.z+this->w;

if (Result>(double) COPLANE_THRESHOLD) return VERTEX_AHEAD_PLANE;
if (Result<-(double) COPLANE_THRESHOLD) return VERTEX_BEHIND_PLANE;
return VERTEX_IN_PLANE;
}

//*************************************************************************
//
//*************************************************************************

template <class Type>
_vertex3<Type> _plane<Type>::normal()
{
_vertex3<Type> Normal1;

Normal1.x=this->x;
Normal1.y=this->y;
Normal1.z=this->z;
return(Normal1);
}

//*************************************************************************
// especializations
//*************************************************************************

// template <> inline void
// _plane<float>::show_values()
// {
// 
// printf("plane: x=%f y=%f z=%f w=%f\n",x,y,z,w);
// }
// 
// template <> inline void
// _plane<double>::show_values()
// {
// 
// printf("plane: x=%lf y=%lf z=%lf w=%lf\n",x,y,z,w);
// }


//*************************************************************************
// 030421
//*************************************************************************
//*************************************************************************
// bounding box
//*************************************************************************


template <class Type>
_bounding_box3<Type>::_bounding_box3(Type Xmin1,Type Ymin1, Type Zmin1, Type Xmax1, Type Ymax1, Type Zmax1)
{

Minimum.x=Xmin1;
Minimum.y=Ymin1;
Minimum.z=Zmin1;
/*
Maximum.x=Xmax1;
Maximum.y=Ymax1;
Maximum.z=Zmax1;*/
Computed=false;
}

//*************************************************************************
// bounding box
//*************************************************************************

template <class Type>
_bounding_box3<Type>::_bounding_box3(const _bounding_box3<Type> &Bounding_box1)
{
Minimum.x=Bounding_box1.Minimum.x;
Minimum.y=Bounding_box1.Minimum.y;
Minimum.z=Bounding_box1.Minimum.z;
Maximum.x=Bounding_box1.Maximum.x;
Maximum.y=Bounding_box1.Maximum.y;
Maximum.z=Bounding_box1.Maximum.z;
Computed=Bounding_box1.Computed;
}

//*************************************************************************
// 030421
//*************************************************************************

template <class Type> _bounding_box3<Type>
_bounding_box3<Type>::compute(const _vertex3<Type> &Vertex1)
{

if (Vertex1.x<Minimum.x) Minimum.x=Vertex1.x;
if (Vertex1.y<Minimum.y) Minimum.y=Vertex1.y;
if (Vertex1.z<Minimum.z) Minimum.z=Vertex1.z;
if (Vertex1.x>Maximum.x) Maximum.x=Vertex1.x;
if (Vertex1.y>Maximum.y) Maximum.y=Vertex1.y;
if (Vertex1.z>Maximum.z) Maximum.z=Vertex1.z;
return(*this);
}

//*************************************************************************
// 030421
//*************************************************************************

template <class Type> _bounding_box3<Type>
_bounding_box3<Type>::compute(_bounding_box3<Type> &Bounding_box1)
{
if (Bounding_box1.Minimum.x<Minimum.x) Minimum.x=Bounding_box1.Minimum.x;
if (Bounding_box1.Minimum.y<Minimum.y) Minimum.y=Bounding_box1.Minimum.y;
if (Bounding_box1.Minimum.z<Minimum.z) Minimum.z=Bounding_box1.Minimum.z;
if (Bounding_box1.Minimum.x>Maximum.x) Maximum.x=Bounding_box1.Maximum.x;
if (Bounding_box1.Maximum.y>Maximum.y) Maximum.y=Bounding_box1.Maximum.y;
if (Bounding_box1.Maximum.z>Maximum.z) Maximum.z=Bounding_box1.Maximum.z;
return(*this);
}

//*************************************************************************
// 030421
//*************************************************************************

template <class Type>
_vertex3<Type> _bounding_box3<Type>::center()
{
_vertex3<Type> Vertex_aux1;

Vertex_aux1=Minimum+Maximum;
Vertex_aux1/=2;
return Vertex_aux1;
}

//*************************************************************************
// 030423
//*************************************************************************

template <class Type>
Type _bounding_box3<Type>::max_value()
{
Type Max_value=-(Type)MAX_FLOAT_VALUE;

if (Max_value<Minimum.x) Max_value=Minimum.x;
if (Max_value<Minimum.y) Max_value=Minimum.y;
if (Max_value<Minimum.z) Max_value=Minimum.z;
if (Max_value<Maximum.x) Max_value=Maximum.x;
if (Max_value<Maximum.y) Max_value=Maximum.y;
if (Max_value<Maximum.z) Max_value=Maximum.z;
return(Max_value);
}

//*************************************************************************
// 030423
//*************************************************************************

template <class Type>
Type _bounding_box3<Type>::min_value()
{
Type Min_value=MAX_FLOAT_VALUE;

if (Min_value>Minimum.x) Min_value=Minimum.x;
if (Min_value>Minimum.y) Min_value=Minimum.y;
if (Min_value>Minimum.z) Min_value=Minimum.z;
if (Min_value>Maximum.x) Min_value=Maximum.x;
if (Min_value>Maximum.y) Min_value=Maximum.y;
if (Min_value>Maximum.z) Min_value=Maximum.z;
return(Min_value);
}

//*************************************************************************
//
//*************************************************************************


template <class Type> void
_bounding_box3<Type>::show_values()
{

printf("begin bounding_box3:\n");
printf("Minimum ");
Minimum.show_values();
printf("Maximum ");
Maximum.show_values();
printf("end bounding_box3:\n");
}





#endif
