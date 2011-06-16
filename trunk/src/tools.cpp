#include "../inc/tools.h"
#include <iostream>
#include <math.h>

Vector3D tools_crossProduct(Vector3D _u, Vector3D _v )
{
	Vector3D rslt;
	
	rslt.setX( _u.getY()*_v.getZ() - _u.getZ()*_v.getY() );
	rslt.setY( _u.getZ()*_v.getX() - _u.getX()*_v.getZ() );
	rslt.setZ( _u.getX()*_v.getY() - _u.getY()*_v.getX() );
	
	return rslt;
}

void tools_couleurpure ( Vector3D tls, Vector3D& rgb )
{
	float t = tls.getX();
	
	if ( t >= 0 && t < M_PI/3)
		rgb.set( 1, t/(M_PI/3), 0 );
		
	if ( t >= M_PI/3 && t < 2*M_PI/3 )
		rgb.set( -t/(M_PI/3) + 2, 1, 0 );
	
	if ( t >= 2*M_PI/3 && t < 3*M_PI/3 )
		rgb.set( 0, 1, t/(M_PI/3) - 2 );
	
	if ( t >= 3*M_PI/3 && t < 4*M_PI/3 )
		rgb.set( 0, -t/(M_PI/3) + 4, 1);
	
	if ( t >= 4*M_PI/3 && t < 5*M_PI/3 )
		rgb.set( t/(M_PI/3) - 4, 0, 1 );
		
	if ( t >= 5*M_PI/3 && t < 6*M_PI/3 )
		rgb.set( 1, 0, -t/(M_PI/3) + 6 );
}

void tools_couleursaturee ( Vector3D tls , Vector3D& rgb )
{
	float l = tls.getY();
	
	if ( l <= 0.5 )
		rgb *= l*2;
	
	if ( l >= 0.5 )
	{
		rgb.setX(2*( 1-rgb.getX() ) * l + 2*rgb.getX() -1);
		rgb.setY(2*( 1-rgb.getY() ) * l + 2*rgb.getY() -1);
		rgb.setZ(2*( 1-rgb.getZ() ) * l + 2*rgb.getZ() -1);
	}
}

void tools_couleurfinale ( Vector3D tls, Vector3D& rgb )
{
	float L = tls.getY();
	float s = tls.getZ();
	
	rgb.setX(( rgb.getX() - L ) * s + L);
	rgb.setY(( rgb.getY() - L ) * s + L);
	rgb.setZ(( rgb.getZ() - L ) * s + L);
}

Vector3D tools_TLStoRGB(Vector3D _color)
{
	Vector3D rslt;
	
	tools_couleurpure( _color, rslt );
	tools_couleursaturee( _color, rslt );
	tools_couleurfinale( _color, rslt );
	
	return rslt;
}

Vector3D tools_colorFromValue(int _mode, double _value)
{
	Vector3D rslt;
	double angle = _value;
	
	if ( _mode == DEGREES )
		angle = M_PI * _value / 180;
	
	else if ( _mode != RADIANS )
	{
		cout<<"Wrong mode given to the tools_colorFromValue function, returnin a black color."<<endl;
		rslt.set( 0, 0, 0 );
		return rslt;
	}
	
	rslt =  tools_TLStoRGB( Vector3D( angle, 0.5, 1 ) );
	
	return rslt;
}
