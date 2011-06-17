#include "../inc/trackball.h"

/* ___________________ GLUT & OpenGL Librairies __ */
#ifdef __APPLE__
        #include <OpenGL/gl.h>
        #include <OpenGL/glu.h>
        #include <GLUT/glut.h>
#else
        #ifdef _WIN32
        #include "../glut.h"
        #else
        #include <GL/gl.h>
        #include <GL/glu.h>
        #include <GL/glut.h>
        #endif
#endif

TrackBall::TrackBall()
{
	state = false;
	angleY = 0;
	angleZ = 0;
	mouseX = 0;
	mouseY = 0;
}

TrackBall::TrackBall(const TrackBall &_t)
{
	state = _t.state;
	angleY = _t.angleY;
	angleZ = _t.angleZ;
	mouseX = _t.mouseX;
	mouseY = _t.mouseY;
}

TrackBall::~TrackBall()
{
	
}

TrackBall& TrackBall::operator = ( const TrackBall& _t )
{
	state = _t.state;
	angleY = _t.angleY;
	angleZ = _t.angleZ;
	mouseX = _t.mouseX;
	mouseY = _t.mouseY;
	
	return *this;
}
bool TrackBall::getState()
{
	return state;
}

double TrackBall::getAngleY()
{
	return angleY;
}

double TrackBall::getAngleZ()
{
	return angleZ;
}

int TrackBall::getMouseX()
{
	return mouseX;
}

int TrackBall::getMouseY()
{
	return mouseY;
}

void TrackBall::setState(bool _s)
{
	state = _s;
}

void TrackBall::setAngleY(double _y)
{
	angleY = _y;
}

void TrackBall::setAngleZ(double _z)
{
	angleZ = _z;
}

void TrackBall::setMouseX(int _x)
{
	mouseX = _x;
}
void TrackBall::setMouseY(int _y)
{
	mouseY = _y;
}

void TrackBall::displayBeginGL_GLUT()
{
	glPushMatrix();
	glRotatef( -angleY,0,1,0);
	glRotatef( -angleZ, 0,0,1);
}

void TrackBall::displayEndGL_GLUT()
{
	glPopMatrix();
}

void TrackBall::mouseGL_GLUT(int _attachedButton, int _mouseButton, int _state, int _x, int _y)
{
	if ( _mouseButton == _attachedButton )
	{
		if ( _state == GLUT_DOWN )
		{
			state = true;
			mouseX = _x;
			mouseY = _y;
		}
		
		else
			state = false;
	}
}

void TrackBall::motionGL_GLUT(int _x, int _y)
{
	if ( state )
	{
		angleY += _y - mouseY;
		angleZ += _x - mouseX;
		mouseX = _x;
		mouseY = _y;
	}
}
