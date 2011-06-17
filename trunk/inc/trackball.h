#ifndef TRACKBALL_H
#define TRACKBALL_H

/**
 * \file	trackball.h
 * \brief	Declaration de la classe TrackBall qui gere une visualisation de type trackball.
 */

class TrackBall
{
	/*!
	 * \class TrackBall
	 * \brief Classe représentant une trackball simpliste.
	 * 
	 * Classe représentant une trackball simpliste pour une visualisation user-friendly de la scene 3D.
	 * Une trackball de cette classe s'attache a un boutton particulier de la souris.
	 * L'activation de la trackball se fait par quatre methodes qui doivent etre placees a des endroits precis :
	 * \li \c displayBegin() : doit etre placee au debut du callback de dessin de la scene.
	 * \li \c displayEnd() : doit etre placee a la fin du callback de dessin de la scene.
	 * \li \c mouseGLUT(...) : doit etre place dans le callback en charge des evenements souris.
	 * \li \c motionGLUT(...) : doit etre place dans le callback en charge des evenements de deplacement de la souris.
	 *
	 * \warning THESE METHODS ARE BASED ON THE GL AND GLUT LIBRARIES. 
	 * \warning IF YOU USE SOME OTHERS LIBRARIES FOR YOUR SOFTWARE, PLEASE WRITE YOUR OWN display/mouse/motion METHODS WITH THE GRAPHIC LIBRARY USED AND THE WINDOW MANAGEMENT LIBRARY NAMES IN SUFFIXE.
	 * \warning THEN LET US KNOW YOUR NEW METHOD.
	 * \warning EXAMPLE : displayBeginGL_GTK(), displayEndGL_GTK(), ... IF YOU ARE USING OPENGL AS YOUR GRAPHIC LIBRARY AND GTK AS YOUR WINDOW MANAGEMENT LIBRARY.
	 * \warning THANK YOU.
	 *
	 * Cette trackball a vocation a etre amelioree/reecrite puisqu'elle ne suit pas exactement les attentes de l'utilisateur.
	 * Toutefois elle permet une manipulation simiple et rapide du point de vue de la scene 3D.
	 *
	 * \todo Ameliorer la trackball pour la rendre plus intuitive (pour l'instant elle ne suis pas exactement les attentes de l'utilisateur mais a le merite d'exister).
	 *
	 */
	
	private :
		bool	state;		/*! <State of the trackball : ON (true) or OFF (false) wether the attached button is down or not.*/
		double	angleY;		/*! <Angle on th Oy axe to rotate the scene.*/
		double	angleZ;		/*! <Angle on th Oz axe to rotate the scene.*/
		int		mouseX;		/*! <Last position of the mouse cursor in the Ox window axe.*/
		int		mouseY;		/*! <Last position of the mouse cursor in the Oy window axe.*/
		
	public:
		/*!
		*  \brief Default constructor of the TrackBall class.
		*
		*  Default constructor of the TrackBall class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		TrackBall();
		
		/*!
		*  \brief Copy constructor of the TrackBall class.
		*
		*  Copy constructor of the TrackBall class.
		*/
		TrackBall( const TrackBall& _t );
		
		/*!
		*  \brief Destructor of the TrackBall class.
		*
		*  Destructor of the TrackBall class.
		*/
		~TrackBall();
		
		/*!
		*  \brief Affectation operator of the TrackBall class.
		*
		*  Affectation operator of the TrackBall class.
		*/
		TrackBall& operator= ( const TrackBall& _t );
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \return (bool) Returns the trackball state.
		*/
		bool getState();
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \return (double) Returns the trackball angle on the Oy axe.
		*/
		double getAngleY ();
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \return (double) Returns the trackball angle on the Oz axe.
		*/
		double getAngleZ ();
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \return (int) Returns the trackball old mouse cursor's positions on the window Ox axe.
		*/
		int getMouseX ();
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \return (int) Returns the trackball old mouse cursor's positions on the window Oy axe.
		*/
		int getMouseY ();
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \param _s : State to attribute to the trackball.
		*
		*  \return (void)
		*/
		void setState( bool _s );
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \param _y : Angle on the Oy axe to attribute to the trackball.
		*
		*  \return (void)
		*/
		void setAngleY ( double _y );
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \param _z : Angle on the Oz to attribute to the trackball.
		*
		*  \return (void)
		*/
		void setAngleZ ( double _z );
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \param _x : Old cursor's position along the Ox window axe to attribute to the trackball.
		*
		*  \return (void)
		*/
		void setMouseX ( int _x );
		
		/*!
		*  \brief Getter of the TrackBall class.
		*
		*  Getter of the TrackBall class.
		*
		*  \param _y : Old cursor's position along the Oy window axe to attribute to the trackball.
		*
		*  \return (void)
		*/
		void setMouseY ( int _y );
		
		
		/*!
		*  \brief Method that sets the OpenGL environement to display a 3D scene with a trackball vizualisation.
		*
		*  Method that sets the OpenGL environement to display a 3D scene with a trackball vizualisation.
		*  \warning This method has to be placed at the first line (after the color buffer clearing) of the GLUT display callback func.
		*
		*  \return (void)
		*/
		void displayBeginGL_GLUT ();
		
		/*!
		*  \brief Method that sets the OpenGL environement to display a 3D scene with a trackball vizualisation.
		*
		*  Method that sets the OpenGL environement to display a 3D scene with a trackball vizualisation.
		*  \warning This method has to be placed at the last line (before the flushing buffers line) of the GLUT display callback func.
		*
		*  \return (void)
		*/
		void displayEndGL_GLUT ();
		
		/*!
		*  \brief Method managing the mouse GLUT events and sets the trackball parameters consequently.
		*
		*  Method managing the mouse GLUT events and sets the trackball parameters consequently.
		*  \warning This method has to be placed in the GLUT mouse callback func.
		*
		*  \param _attachedButton : Button the user wants to attach the trackball activation. Can be set to : GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON or GLUT_RIGHT_BUTTON.
		*  \param _mouseButton : The mouse button that called back the callback.
		*  \param _x : The position of the mouse cursor along the Ox window axe when the callback has been called.
		*  \param _y : The position of the mouse cursor along the Oy window when the callback has been called.
		*
		*  \return (void)
		*/
		void mouseGL_GLUT (int _attachedButton, int _mouseButton, int _state, int _x, int _y);
		
		/*!
		*  \brief Method managing the mouse motion GLUT events and sets the trackball parameters consequently.
		*
		*  Method managing the mouse motion GLUT events and sets the trackball parameters consequently.
		*  \warning This method has to be placed in the GLUT mouse motion callback func.
		*
		*  \param _x : The position of the mouse cursor along the Ox window axe when the callback has been called.
		*  \param _y : The position of the mouse cursor along the Oy window when the callback has been called.
		*
		*  \return (void)
		*/
		void motionGL_GLUT (int _x, int _y);
};

#endif
