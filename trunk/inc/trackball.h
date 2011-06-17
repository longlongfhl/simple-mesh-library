#ifndef TRACKBALL_H
#define TRACKBALL_H

class TrackBall
{
	private :
		bool	state;
		double	angleY;
		double	angleZ;
		int		mouseX;
		int		mouseY;
		
	public:
		TrackBall();
		TrackBall( const TrackBall& _t );
		~TrackBall();
		TrackBall& operator= ( const TrackBall& _t );
		
		bool getState();
		double getAngleY ();
		double getAngleZ ();
		int getMouseX ();
		int getMouseY ();
		
		void setState( bool _s );
		void setAngleY ( double _y );
		void setAngleZ ( double _z );
		void setMouseX ( int _x );
		void setMouseY ( int _y );
		
		void displayBegin ();
		void displayEnd ();
		void mouseGLUT (int _attachedButton, int _mouseButton, int _state, int _x, int _y);
		void motionGLUT (int _x, int _y);
};

#endif
