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
	angleX = 0;
	angleY = 0;
	mouseX = 0;
	mouseY = 0;
}

TrackBall::TrackBall(const TrackBall &_t)
{
	state = _t.state;
	angleX = _t.angleX;
	angleY = _t.angleY;
	mouseX = _t.mouseX;
	mouseY = _t.mouseY;
}

TrackBall::~TrackBall()
{
	
}

TrackBall& TrackBall::operator = ( const TrackBall& _t )
{
	state = _t.state;
	angleX = _t.angleX;
	angleY = _t.angleY;
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

void TrackBall::setAngleX(double _x)
{
	angleX = _x;
}

void TrackBall::setAngleZ(double _y)
{
	angleY = _y;
}

void TrackBall::setMouseX(int _x)
{
	mouseX = _x;
}
void TrackBall::setMouseY(int _y)
{
	mouseY = _y;
}

void TrackBall::displayBegin()
{
	glPushMatrix();
	glRotatef( -angleX,0,1,0);
	glRotatef( -angleZ, 0,0,1);
}

void TrackBall::displayEnd()
{
	glPopMatrix();
}

void TrackBall::mouseGLUT(int _attachedButton, int _mouseButton, int _state, int _x, int _y)
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

void TrackBall::motionGLUT(int _x, int _y)
{
	if ( state )
	{
		angleX += _y - mouseY;
		angleZ += _x - mouseX;
		mouseX = _x;
		mouseY = _y;
	}
}
