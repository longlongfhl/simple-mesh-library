#include "../inc/tools.h"

Vector3D tools_crossProduct(Vector3D _u, Vector3D _v )
{
	Vector3D rslt;
	
	rslt.setX( _u.getY()*_v.getZ() - _u.getZ()*_v.getY() );
	rslt.setY( _u.getZ()*_v.getX() - _u.getX()*_v.getZ() );
	rslt.setZ( _u.getX()*_v.getY() - _u.getY()*_v.getX() );
	
	return rslt;
}
