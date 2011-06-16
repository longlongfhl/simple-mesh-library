#include <iostream>
#include <math.h>
#include "../inc/vector3d.h"

using namespace std;

Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3D::Vector3D(const Vector3D &_v)
{
	x = _v.x;
	y = _v.y;
	z = _v.z;
}

Vector3D::~Vector3D()
{
	
}

Vector3D& Vector3D::operator = ( const Vector3D& _v )
{
	x = _v.x;
	y = _v.y;
	z = _v.z;
	
	return *this;
}

Vector3D Vector3D::operator+= ( const double& _a )
{
	x += _a;
	y += _a;
	z += _a;
	
	return *this;
}

Vector3D Vector3D::operator+= ( const Vector3D& _v )
{
	x += _v.x;
	y += _v.y;
	z += _v.z;
	
	return *this;
}

Vector3D Vector3D::operator+ ( const double& _a )
{
	x += _a;
	y += _a;
	z += _a;
	
	return *this;
}

Vector3D Vector3D::operator+ ( const Vector3D& _v )
{
	x += _v.x;
	y += _v.y;
	z += _v.z;
	
	return *this;
}

Vector3D Vector3D::operator-= ( const double& _a )
{
	x -= _a;
	y -= _a;
	z -= _a;
	
	return *this;
}

Vector3D Vector3D::operator-= ( const Vector3D& _v )
{
	x -= _v.x;
	y -= _v.y;
	z -= _v.z;
	
	return *this;
}

Vector3D Vector3D::operator- ( const double& _a )
{
	x -= _a;
	y -= _a;
	z -= _a;
	
	return *this;
}

Vector3D Vector3D::operator- ( const Vector3D& _v )
{
	x -= _v.x;
	y -= _v.y;
	z -= _v.z;
	
	return *this;
}

Vector3D Vector3D::operator*= ( const double& _a )
{
	x *= _a;
	y *= _a;
	z *= _a;
	
	return *this;
}

Vector3D Vector3D::operator*= ( const Vector3D& _v )
{
	x *= _v.x;
	y *= _v.y;
	z *= _v.z;
	
	return *this;
}

Vector3D Vector3D::operator* ( const double& _a )
{
	x *= _a;
	y *= _a;
	z *= _a;
	
	return *this;
}

Vector3D Vector3D::operator* ( const Vector3D& _v )
{
	x *= _v.x;
	y *= _v.y;
	z *= _v.z;
	
	return *this;
}

Vector3D Vector3D::operator/= ( const Vector3D& _v )
{
	x /= _v.x;
	y /= _v.y;
	z /= _v.z;
	
	return *this;
}

Vector3D Vector3D::operator/= ( const double& _a )
{
	x /= _a;
	y /= _a;
	z /= _a;
	
	return *this;
}

Vector3D Vector3D::operator/ ( const Vector3D& _v )
{
	x /= _v.x;
	y /= _v.y;
	z /= _v.z;
	
	return *this;
}

Vector3D Vector3D::operator/ ( const double& _a )
{
	x /= _a;
	y /= _a;
	z /= _a;
	
	return *this;
}

double Vector3D::getX()
{
	return x;
}

double Vector3D::getY()
{
	return y;
}

double Vector3D::getZ()
{
	return z;
}

double* Vector3D::getArray()
{
	double* rslt = (double*) malloc ( 3 * sizeof (double));
	
	rslt[0] = x;
	rslt[1] = y;
	rslt[2] = z;
	
	return rslt;
}

void Vector3D::setX(double _x)
{
	x = _x;
}

void Vector3D::setY(double _y)
{
	y = _y;
}

void Vector3D::setZ(double _z)
{
	z = _z;
}

void Vector3D::set(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Vector3D::clear()
{
	x = 0;
	y = 0;
	z = 0;
}

void Vector3D::normalize()
{
	double norme = sqrt ( x*x + y*y + z*z );
	x /= norme;
	y /= norme;
	z /= norme;
}

void Vector3D::print()
{
	cout<<"[ "<<x<<" "<<y<<" "<<z<<" ]"<<endl;
}
