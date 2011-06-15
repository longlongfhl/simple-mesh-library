#include <iostream>

/* __________________________ SML library ________ */
#include "../inc/mesh.h"

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

using namespace std;

/* ************************************************************************ */
/* ***						  GLOBALS VARIABLES                  		*** */
/* ************************************************************************ */

int		__winX = 500;											/* Window width. */
int		__winY = 500;											/* Window height. */
int		__displayMode = SMOOTH;									/* Displaying mode. Changed by user with the keyboard callback. */
int		__vertexIndex = 0;

Mesh	__mesh;													/* Mesh to visualize, is loaded in the main func. */


/* ************************************************************************ */
/* ***						FUNCTIONS PROTOTYPES                  		*** */
/* ************************************************************************ */
void	printMeshInfo	( Mesh _mesh );							/* Equals to the member method "printInfo". */
void	printHelp		();										/* Prints help in the konsole. */
void	displayGL		();										/* GLUT callback for rendering. */
void	reshapeGL		( int _w, int _h );						/* GLUT callback for resizing the window. */
void	initGL			();										/* GLUT OpenGL rendering initialization. */
void	keyboardGL		( unsigned char _k, int _x, int _y );	/* GLUT callback for keyboard typing. */
int		main			( int _argc, char** _argv );			/* Main function, launches the glut loop. */

/* ************************************************************************ */
/* ***						  MAIN PROGRAM								*** */
/* ************************************************************************ */
void printMeshInfo ( Mesh _mesh )
{
	cout<<"Mesh Informations :"<<endl;
	cout<<"___________________"<<endl;
	cout<<"Nb vertices = "<<_mesh.getNVerts()<<endl;
	cout<<"Nb edges    = "<<_mesh.getNEdges()<<endl;
	cout<<"Nb faces    = "<<_mesh.getNFaces()<<endl;
}

void printHelp ()
{
	cout<<"Help :"<<endl;
	cout<<"______"<<endl;
	cout<<"\t- v : display mode will be set to VERTICES"<<endl;
	cout<<"\t- e : display mode will be set to EDGES"<<endl;
	cout<<"\t- f : display mode will be set to FACES"<<endl;
	cout<<"\t- s : display mode will be set to SMOOTH"<<endl;
	cout<<"\t- i : prints informations about the mesh"<<endl;
	cout<<"\t- q : quit the software"<<endl;
}

void displayGL ()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	__mesh.display( __displayMode, 0.7,0.7,0.7 );
	
	glutSwapBuffers();
}

void reshapeGL(int _w, int _h)
{
       __winX = _w;
       __winY = _h;

        glViewport(0, 0,__winX,__winY);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(60.0, (GLfloat)_w/(GLfloat)_h, 0.1, 500.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
		gluLookAt( -1.5, 0, 0,
				   0, 0, 0,
				   0, 0, 1 );
        
        glutPostRedisplay();
}

void initGL()
{
        GLfloat mat_specular   [4] = { 0.18, 0.18, 0.18, 0.18 };
        GLfloat mat_shininess  [ ] = { 128 };
        GLfloat global_ambient [ ] = { 0.02, 0.02, 0.05, 0.05 };
        GLfloat light0_ambient [ ] = { 0, 0, 0, 0 };
        GLfloat light0_diffuse [ ] = { 0.85, 0.85, 0.8, 0.85 };
        GLfloat light0_specular[ ] = { 0.85, 0.85, 0.15, 0.85 };

        glClearColor(0,0,0,0);

		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
		
		glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
		
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_NORMALIZE);
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);       
}

void keyboardGL(unsigned char _k, int _x, int _y)
{
	if ( _k == 27 || _k == 'q' || _k == 'Q' )
		exit(0);
	
	if ( _k == 'v' || _k == 'V' )
		__displayMode = VERTICES;
	
	if ( _k == 'e' || _k == 'E' )
		__displayMode = EDGES;
	
	if ( _k == 'f' || _k == 'F' )
		__displayMode = FACES;
	
	if ( _k == 's' || _k == 'S' )
		__displayMode = SMOOTH;
	
	if ( _k == 'h' || _k == 'H' )
		printHelp();
	
	if ( _k == 'i' )
		printMeshInfo( __mesh );
	
	glutPostRedisplay();
}

int main ( int _argc, char** _argv )
{
	int posX, posY;
	
	if ( _argc == 2 )
	{
		/* Arguments are correct. We load the mesh, compute its normals and normalize it in a unit-length box. */
		__mesh.loadOBJ( _argv[1] );
		__mesh.computeNormals();
		__mesh.normalize();
		
		cout<<"Type \"h\" for help"<<endl;
	}
	
	else
	{
		cout<<"Usage : "<<_argv[0]<<" mesh.obj"<<endl;
		return -1;
	}
	
	/* ************************************************************************ */
	/* ***					CREATING WINDOW WITH GLUT						*** */
	/* ************************************************************************ */
	glutInit(&_argc, _argv);
	
	posX = 250;
	posY = 200;
	
	glutInitWindowSize( __winX , __winY );
	glutInitWindowPosition(posX, posY);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	
	glutCreateWindow("SML Example -Mesh Viewer using OpenGL and GLUT");
	glutDisplayFunc(displayGL);
	glutReshapeFunc(reshapeGL);
	glutKeyboardFunc(keyboardGL);
	initGL();
	
	glutMainLoop();
	
	return 0;
}
