#ifndef MESH_H
#define MESH_H

/**
 * \file	mesh.h
 * \brief	Declaration de la classe Mesh representant un maillage avec une structure de demi aretes.
 */

/* ______________________________ My includes ____ */
#include "define.h"
#include "tools.h"
#include "map.h"

/* ____________________________ STD Librairies ___ */
#include <vector>

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

/* ************************************************************************************ */
/* ************************************************************************************ */

/*! \def VERTICES
  display mode : only display the mesh vertices.
 */
#define VERTICES 0

/*! \def EDGES
  display mode : only display the mesh edges.
 */
#define EDGES 1

/*! \def FACES
  display mode : only display the mesh faces, each faces will be display with a unique normal (the face's normal).
 */
#define FACES 2

/*! \def SMOOTH
  display mode : only display the mesh faces, each faces will be displayed taking in acount it's vertices normals that will be interpolated along the face, giving a smoother rendering.
 */
#define SMOOTH 3

/* ************************************************************************************ */
/* ************************************************************************************ */


class Mesh
{
	/*!
	 * \class Mesh
	 * \brief Classe représentant un maillage grace a une structure de demi aretes.
	 * 
	 * Un maillage est represente par ses principales caracteristiques : son nombre de sommets, d'aretes et de faces.
	 * Ainsi que trois vectors (pour des raisons de simplicite nous avons choisi d'utiliser des vectors et non des tableaux alloues dynamiquement)
	 * donnant la liste exhaustive de tous ces sommets, demi-aretes et faces du maillage.
	 * On attribue aussi a chaque maillage un identifiant qu'il sera preferable de garder unique pour chaque objet.
	 *
	 * \todo Des ameliorations peuvent etre apportes a cette classe, notamment des methodes-outils qui n'existent pas encore,
	 *  l'ajout d'un attribut de type boumding box ainsi que les methodes qui vont avec (accesseurs/modificateurs, boite a outils, ...)
	 *	le passage des accesseurs/modificateurs en inline...
	 *
	 */
	
	private :
	/* Les 3 entiers nVerts, nEdges et nFaces pourraient etre supprimes et remplaces par de appels a la methode size() de la classe vector */
			
		int				id;			/*! <ID of the mesh.*/
	
		int				nVerts;		/*! <Number of vertex composing the mesh.*/
		int				nEdges;		/*! <Number of half edges composing the mesh.*/
		int				nFaces;		/*! <Number of faces composing the mesh.*/
		
		vector<Vertex*>	verts;		/*! <Vector (array) of pointer to all the vertices componong the mesh.*/
		vector<Edge*>	edges;		/*! <Vector (array) of pointer to all the half edges componong the mesh.*/
		vector<Face*>	faces;		/*! <Vector (array) of pointer to all the faces componong the mesh.*/
		
	public:
		/*!
		*  \brief Default constructor of the Mesh class.
		*
		*  Default constructor of the Mesh class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Mesh();
		
		/*!
		*  \brief Copy constructor of the Mesh class.
		*
		*  Copy constructor of the Mesh class.
		*/
		Mesh( const Mesh& _m );
		
		/*!
		*  \brief Destructor of the Mesh class.
		*
		*  Destructor of the Mesh class.
		*/
		~Mesh();
		
		/*!
		*  \brief Affectation operator of the Mesh class.
		*
		*  Affectation operator of the Mesh class.
		*/
		Mesh& operator= ( const Mesh& _m );
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \return (int) returns the ID of the mesh.
		*/
		int getID ();
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \return (int) returns the number of vertices in the mesh.
		*/
		int getNVerts ();
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \return (int) returns the number of edges componing the mesh.
		*/
		int getNEdges ();
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \return (int) returns the number of faces componing the mesh.
		*/
		int getNFaces();
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \return (vector<Vertex*>) returns an array containing a pointer to each vertex componing the mesh.
		*/
		vector<Vertex*> getVerts ();
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \param _i : index of the vertex we want to be returned.
		*
		*  \return (Vertex*) returns a pointer to the ith vertex of the mesh.
		*/
		Vertex*	getIVert ( int _i );
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \return (vector<Edge*>) returns an array containing a pointer to each half edge componing the mesh.
		*/
		vector<Edge*> getEdges ();
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \param _i : index of the edge we want to be returned.
		*
		*  \return (Edge*) returns the ith edge of the mesh;
		*/
		Edge* getIEdge ( int _i );
		
		/*!
		*  \brief Getter of the Mesh class.
		*
		*  Getter of the Mesh class.
		*
		*  \return (vector<Face*>) returns an array containing a pointer to each face componing the mesh.
		*/
		vector<Face*> getFaces ();
	
		/*!
		*  \brief Setter of the Mesh class.
		*
		*  Setter of the Mesh class.
		*
		*  \param _ID : ID to affect to the mesh.
		*
		*  \return (void)
		*/
		void setID ( int _ID );
		
		/*!
		*  \brief Setter of the Mesh class.
		*
		*  Setter of the Mesh class.
		*
		*  \param _nVerts : number of vertices in the mesh.
		*
		*  \return (void)
		*/
		void setNVerts ( int _nVerts );
		
		/*!
		*  \brief Setter of the Mesh class.
		*
		*  Setter of the Mesh class.
		*
		*  \param _nEdges : numer of edges in the mesh.
		*
		*  \return (void)
		*/
		void setNEdges ( int _nEdges );
		
		/*!
		*  \brief Setter of the Mesh class.
		*
		*  Setter of the Mesh class.
		*
		*  \param _nFaces : number of faces in the mesh.
		*
		*  \return (void)
		*/
		void setNFaces ( int _nFaces );
		
		/*!
		*  \brief Setter of the Mesh class.
		*
		*  Setter of the Mesh class.
		*
		*  \param _verts : array containing a pointer on each vertex of the mesh.
		*
		*  \return (void)
		*/
		void setVerts ( vector<Vertex*> _verts );
		
		/*!
		*  \brief Setter of the Mesh class.
		*
		*  Setter of the Mesh class.
		*
		*  \param _edges : array containing a pointer on each half edge of the mesh.
		*
		*  \return (void)
		*/
		void setEdges ( vector<Edge*> _edges );
		
		/*!
		*  \brief Setter of the Mesh class.
		*
		*  Setter of the Mesh class.
		*
		*  \param _faces : array containing a pointer on each face of the mesh.
		*
		*  \return (void)
		*/
		void setFaces ( vector<Face*> _faces );
		
		/*!
		*  \brief Clears the mesh informations.
		*
		*  All attributes will be set to 0 (int, float, double, ...), NULL (pointers) or cleared (lists, vectors, stacks, ...).
		*
		*  \return (void)
		*/
		void clear ();
		
		/*!
		*  \brief Search an edge in the edges vector of the mesh.
		*
		*  Search an edge defined by its two vertices in the edges vector of the mesh.
		*
		*  \param _iTail : index of the tail vertex of the half edge.
		*  \param _iHead : index of the head vertex of the half edge.
		*
		*  \return (int) Returns the index of the edge if the half edge with these two vertices as tail and head is found, -1 else.
		*/
		int containsEdge ( int _iTail, int _iHead );
		
		/*!
		*  \brief Adds a vertex to the mesh.
		*
		*  Adds a pointer on a vertex to the vertex vector of the mesh and updates the nVerts attribute;
		*
		*  \param _v : pointer on the vertex to add;
		*
		*  \return (void)
		*/
		void addVertex ( Vertex* _v );
		
		/*!
		*  \brief Adds an edge to the edge vector of a vertex.
		*
		*  Adds an edge to the edge vector of the vertex ith.
		*
		*  \param _i : index of the vertex we want to add the edge.
		*  \param _e : pointer on the edge we want to add.
		*
		*  \return (void)
		*/
		void addEdgeToIVertex ( int _i, Edge* _e );
		
		/*!
		*  \brief Adds an edge to the mesh.
		*
		*  Adds a pointer on a edge to the edge vector of the mesh and updates the nEdges attribute;
		*
		*  \param _e : pointer on the edge to add;
		*
		*  \return (void)
		*/
		void addEdge ( Edge* _e );
		
		/*!
		*  \brief Adds a face to the face vector of an edge.
		*
		*  Adds a face to the face vector of the ith edge.
		*
		*  \param _i : index of the face we want to add the edge.
		*  \param _f : pointer on the face we want to add.
		*
		*  \return (void)
		*/
		void addFaceToIEdge ( int _i, Face* _f );
		
		/*!
		*  \brief Adds a face to the mesh.
		*
		*  Adds a pointer on a face to the face vector of the mesh and updates the nFaces attribute;
		*
		*  \param _f : pointer on the face to add;
		*
		*  \return (void)
		*/
		void addFace ( Face* _f );
		
		/*!
		*  \brief Loads a wavefront ".obj" mesh.
		*
		*  Loads a wavefront ".obj" mesh from the _path file.
		*  This is a basic version of a loader : does not support the comment lines, the texture lines or the normal lines.
		*  This has to be report and fixed.
		*  For OBJ format spec., see http://en.wikipedia.org/wiki/Wavefront_.obj_file.
		*
		*  \todo The loader should be rewritten to support the comment lines and other types of format.
		*
		*  \param _path : location on the disk of the mesh to load.
		*
		*  \return (int) returns -1 if an issue occured during the operation, 1 else;
		*/
		int loadOBJ ( char* _path );
		
		/*!
		*  \brief Computes the normals of the mesh.
		*
		*  Computes the normals of every faces and every vertex of the mesh.
		*  The computed normals are all normalized.
		*
		*  \return (void)
		*/
		void computeNormals ();
		
		/*!
		*  \brief Resize the mesh to a unit-length box.
		*
		*  Resize the mesh to a unit-length box :
		*  The biggest direction of the mesh (Ox or Oy or Oz) will be set to 1 after scaling, 
		*  the other directions will be proportionally scaled.
		*
		*  \return (void)
		*/
		void normalize();
		
		/*!
		*  \brief Print some informations about the mesh in the terminal.
		*
		*  Print some informations about the mesh in the terminal :
		*  Number of vertices, number of edges, number of faces.
		*
		*  \return (void)
		*/
		void printInfos ();
		
		/*!
		*  \brief Color each vertex of the mesh according to its map value.
		*
		*  Color each vertex of the mesh according to its map value :
		*  Fills the color attribute of the vertex.
		*  Its value is transformed in a color interpolated from red (max value of the map) and magenta (min value of the map).
		*
		*  \return (int) Returns 1 if the operation was done succesfully, -1 else.
		*/
		int colorFromMap ( Map _m );
		
		/*!
		*  \brief OpenGL routine to display one of the vertices of a mesh.
		*
		*  OpenGL routine to display one of the vertices of a mesh.
		*
		*  \param _i : index of the vertex to display.
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayIVertex ( int _i, float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display one of the vertices of a mesh.
		*
		*  OpenGL routine to display one of the vertices of a mesh.
		*  The color displayed will be the vertex's color.
		*
		*  \param _i : index of the vertex to display.
		*
		*  \return (void)
		*/
		void displayIVertex ( int _i );
		
		/*!
		*  \brief OpenGL routine to display the vertices of a mesh.
		*
		*  OpenGL routine to display the vertices of a mesh.
		*
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayVertices ( float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display the vertices of a mesh.
		*
		*  OpenGL routine to display the vertices of a mesh.
		*  The color displayed will be the vertices attached colors.
		*
		*  \return (void)
		*/
		void displayVertices ();
		
		/*!
		*  \brief OpenGL routine to display an edge of a mesh.
		*
		*  OpenGL routine to display an edge of a mesh.
		*
		*  \param _i : index of the edge to display.
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayIEdge ( int _i, float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display an edge of a mesh.
		*
		*  OpenGL routine to display an edge of a mesh.
		*  The color displayed will be the vertices attached colors.
		*
		*  \return (void)
		*/
		void displayIEdge ( int _i );
		
		/*!
		*  \brief OpenGL routine to display the edges of a mesh.
		*
		*  OpenGL routine to display the edges of a mesh.
		*  !! writes two times every edge in the frame buffer !!
		*  ( One per half edge ).
		*
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayEdges ( float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display the edges of a mesh.
		*
		*  OpenGL routine to display the edges of a mesh.
		*  The color displayed will be the color of the vertices.
		*
		*  \return (void)
		*/
		void displayEdges ();
		
		/*!
		*  \brief OpenGL routine to display a face of a mesh.
		*
		*  OpenGL routine to display the ith face of a mesh.
		*  The normal is simply the normal to the face.
		*
		*  \param _i : index of the face to display.
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayIFace ( int _i, float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display a face of a mesh.
		*
		*  OpenGL routine to display the ith face of a mesh.
		*  The normal is simply the normal to the face.
		*  The color displayed will be the color of the vertices.
		*
		*  \return (void)
		*/
		void displayIFace ( int _i );
		
		/*!
		*  \brief OpenGL routine to display a face of a mesh.
		*
		*  OpenGL routine to display the ith face of a mesh.
		*  The normal is computed with the face vertices normals and is interpolated.
		*
		*  \param _i : index of the face to display.
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayIFaceSmooth ( int _i, float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display a face of a mesh.
		*
		*  OpenGL routine to display the ith face of a mesh.
		*  The normal is computed with the face vertices normals and is interpolated.
		*  The color displayed will be the color of the vertices.
		*
		*  \return (void)
		*/
		void displayIFaceSmooth ( int _i );
		
		/*!
		*  \brief OpenGL routine to display the faces of a mesh.
		*
		*  OpenGL routine to display the faces of a mesh.
		*  Normals are simply normals to the face.
		*
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayFaces ( float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display the faces of a mesh.
		*
		*  OpenGL routine to display the faces of a mesh.
		*  Normals are simply normals to the face.
		*  The color displayed will be the color of the vertices.
		*
		*  \return (void)
		*/
		void displayFaces ();
		
		/*!
		*  \brief OpenGL routine to display the faces of a mesh.
		*
		*  OpenGL routine to display the faces of a mesh.
		*  The normals are computed with the face vertices normals and are interpolated.
		*
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void displayFacesSmooth ( float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display the faces of a mesh.
		*
		*  OpenGL routine to display the faces of a mesh.
		*  The normals are computed with the face vertices normals and are interpolated.
		*  The color displayed will be the color of the vertices.
		*
		*  \return (void)
		*/
		void displayFacesSmooth ();
		
		/*!
		*  \brief OpenGL routine to display a mesh.
		*
		*  OpenGL routine to display a mesh in different ways.
		*
		*  \param _mode : mode we want to display the mesh. Can be VERTICES, EDGES, FACES or SMOOTH.
		*  \param _r : red component of the color to display.
		*  \param _g : green component of the color to display.
		*  \param _b : blue component of the color to display.
		*
		*  \return (void)
		*/
		void display ( int _mode, float _r, float _g, float _b );
		
		/*!
		*  \brief OpenGL routine to display a mesh.
		*
		*  OpenGL routine to display a mesh in different ways.
		*  The color displayed will be the color of the vertices.
		*
		*  \return (void)
		*/
		void display ( int _mode=FACES );
};

#endif
