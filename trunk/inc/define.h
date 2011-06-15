#ifndef DEFINE_H
#define DEFINE_H

/**
 * \file	define.h
 * \brief	Declaration des classes Vertex, Edge et Face
 */

/* ______________________________ My includes ____ */
#include "vector3d.h"

/* ____________________________ STD Librairies ___ */
#include <iostream>
#include <vector>

using namespace std;

/* Prototypes of all the class that will be declared in this file :
   While classes needs one another to be declared, several inclusions issues would occur if we dicided
   to create a single class per header file. That is also why we had to write the class prototypes here.
   */
class	Vertex;
class	Edge;
class	Face;

class Vertex
{
	/*!
	 * \class Vertex
	 * \brief Classe représentant un Vertex, soit, un point supportant un maillage.
	 * 
	 * Un vertex est represente par ses elements les plus courant, a savoir : sa position dans l'espace, un numero d'identification, un vecteur normal, et une couleur.
	 * Les informations de voisinnage s'obtiennent a l'aide d'une liste d'arretes (demi-aretes) qui partent de ce vertex.
	 *
	 */
		
	private :
		int				id;				/*! <ID of the vertex.*/
		Vector3D		pos;			/*! <Location in space of the vertex.*/
		Vector3D		color;			/*! <Color of the vertex.*/
		Vector3D		normal;			/*! <Normal vector  at the vertex.*/
		vector<Edge*>	edges;			/*! <List of the edges starting from this vertex.*/
		
	public :
		/*!
		*  \brief Default constructor of the Vertex class.
		*
		*  Default constructor of the Vertex class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Vertex();
	
		/*!
		*  \brief Copy constructor of the Vertex class.
		*
		*  Copy constructor of the Vertex class.
		*/
		Vertex ( const Vertex &  _v );
		
		/*!
		*  \brief Ovrloaded constructor of the Vertex class.
		*
		*  Overloaded constructor of the Vertex class : fill the id of the vertex and its location in space.
		*/
		Vertex( int _ID, Vector3D _pos );
	
		/*!
		*  \brief Destructor of the Vertex class.
		*
		*  Destructor of the Vertex class.
		*/
		~Vertex();
		
		/*!
		*  \brief Affectation operator of the Vertex class.
		*
		*  Affectation operator of the Vertex class.
		*/
		Vertex& operator= ( const Vertex& _v );
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (int) returns the ID of the vertex.
		*/
		int			getID ();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (Vector3D) returns the location of the vertex in space.
		*/
		Vector3D	getPos ();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (double*) returns the location of the vertex in space as an array of three frames.
		*/
		double*		getPosArray ();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (Vector3D) returns the color of the vertex in space.
		*/
		Vector3D	getColor ();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (double*) returns the color of the vertex in space as an array of three frames.
		*/
		double*		getColorArray ();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (Vector3D) returns the normal of the vertex in space.
		*/
		Vector3D	getNormal ();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (double*) returns the normal of the vertex in spaceas an array of three frames.
		*/
		double*		getNormalArray ();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (vector<Edge*>) returns a vector containing all the edges which tail is the vertex.
		*/
		vector<Edge*>	getEdges();
		
		/*!
		*  \brief Getter of the Vertex class.
		*
		*  Getter of the Vertex class.
		*
		*  \return (Edge*) returns a pointer on the ith edge of the edge vector.
		*/
		Edge* getIEdge ( int _i );
		
		/*!
		*  \brief Prints the ID of the vertex in the terminal.
		*
		*  Prints the ID of the vertex in the terminal as follow : "position [ x, y, z ]\n".
		*
		*  \return (void)
		*/
		void printID ();
		
		/*!
		*  \brief Prints the position of the vertex in the terminal.
		*
		*  Prints the Position of the vertex in the terminal as follow : "position [ x, y, z ]\n".
		*
		*  \return (void)
		*/
		void printPos ();
		
		/*!
		*  \brief Prints the normal of the vertex in the terminal.
		*
		*  Prints the normal of the vertex in the terminal as follow : "Normal [ x, y, z ]\n".
		*
		*  \return (void)
		*/
		void printNormal ();
		
		/*!
		*  \brief Prints the Color of the vertex in the terminal.
		*
		*  Prints the color of the vertex in the terminal as follow : "Color [ x, y, z ]\n".
		*
		*  \return (void)
		*/
		void printColor ();
		
		/*!
		*  \brief Prints informations about the vertex in the terminal.
		*
		*  Prints informations about the vertex in the terminal : id, position, normal, color;
		*
		*  \return (void)
		*/
		void print ();
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class.
		*
		*  \param _ID : value to affect to the id attribute of the vertex.
		*
		*  \return (void)
		*/
		void setID ( int _ID );
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class.
		*
		*  \param _pos : position to affect to the vertex.
		*
		*  \return (void)
		*/
		void setPos ( Vector3D _pos );
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class, this one is written to have a double array in parameter and not a Vector3D.
		*
		*  \param _pos : position to affect to the vertex.
		*
		*  \return (void)
		*/
		void setPos ( double* _pos );
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class.
		*
		*  \param _normal : normal to affect to the vertex.
		*
		*  \return (void)
		*/
		void setNormal ( Vector3D _normal );
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class, this one is written to have a double array in parameter and not a Vector3D.
		*
		*  \param _normal : normal to affect to the vertex.
		*
		*  \return (void)
		*/
		void setNormal ( double* _normal );
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class.
		*
		*  \param _color : color to affect to the vertex.
		*
		*  \return (void)
		*/
		void setColor ( Vector3D _color );
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class, this one is written to have a double array in parameter and not a Vector3D.
		*
		*  \param _color : color to affect to the vertex.
		*
		*  \return (void)
		*/
		void setColor ( double* _color );
		
		/*!
		*  \brief Setter of the Vertex class.
		*
		*  Setter of the Vertex class.
		*
		*  \param _edges : vector of edges to affect to the vertex.
		*
		*  \return (void)
		*/
		void setEdges ( vector<Edge*> _edges );
		
		/*!
		*  \brief Check for the existing of an edge in the edge vector of a vertex.
		*
		*  Check for the existing of an edge in the edge vector of a vertex given the two vertices representing the edge.
		*
		*  \param _iTail : index of the tail vertex of the edge.
		*  \param _iHead : index of the head vertex of the edge.
		*
		*  \return (int) Returns the index of the edge if the vertex contains the edge given by the two vertices of index _iTail (for the tail vertex) and _iHead (for the head vertex). Returns -1 else.
		*/
		int containsEdge ( int _iTail, int _iHead );
		
		/*!
		*  \brief Adds an edge to the edge vector of the vertex.
		*
		*  Adds an edge to the edge vector of the vertex.
		*
		*  \param _e : pointer on the edge we want to add.
		*
		*  \return (void)
		*/
		void addEdge ( Edge* _e );
};

class Edge
{
	/*!
	 * \class Edge
	 * \brief Classe représentant une arete (demi-arete), soit, deux sommets relies entre eux dans un ordre precis.
	 *
	 * Une arete (demi-arete) est representee par ses elements les plus courant, a savoir : deux sommets, l'un en tete et l'autre en queue - ce qui permet de connaitre le sens de l'arete -
	 * un identifiant qui devrait etre unique pour chaque arete (demi-arete) d'un meme maillage et un pointeur vers sa (demi-arete) jumelle. Sa jumelle etant l'arete dont la tete correspond
	 * a la queue de celle-ci et vice versa.
	 * Les informations de voisinnage s'obtiennent par le biais d'un tableau de faces contenant toutes les faces qui contiennent cette arete.
	 *
	 */
	
	private :
		int				id;				/*! <ID of the egde. */
		Vertex*			tail;			/*! <Pointer to the tail vertex of the edge. */
		Vertex*			head;			/*! <Pointer to the head vertex of tyhe edge. */ 
		Edge*			twin;			/*! <Pointer to the twin edge (the "opposote" edge). */
		vector<Face*>	faces;			/*! <List of the faces which are bordered by this edge. */
		
	public :
		/*!
		*  \brief Default constructor of the Edge class.
		*
		*  Default constructor of the Edge class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Edge();
	
		/*!
		*  \brief Default constructor of the Edge class.
		*
		*  Default constructor of the Edge class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Edge ( int _ID, Vertex* _tail, Vertex* _head );
	
		/*!
		*  \brief Copy constructor of the Edge class.
		*
		*  Copy constructor of the Edge class.
		*/
		Edge ( const Edge& _e );
		
		/*!
		*  \brief Destructor of the Edge class.
		*
		*  Destructor of the Edge class.
		*/
		~Edge ();
		
		Edge& operator= ( const Edge& _e );
	
		/*!
		*  \brief Getter of the Edge class.
		*
		*  Getter of the Edge class.
		*
		*  \return (int) returns the ID of the edge.
		*/
		int	getID ();
		
		/*!
		*  \brief Getter of the Edge class.
		*
		*  Getter of the Edge class.
		*
		*  \return (Vertex*) returns a pointer to the vertex which is the tail of the edge.
		*/
		Vertex*	getTail ();
		
		/*!
		*  \brief Getter of the Edge class.
		*
		*  Getter of the Edge class.
		*
		*  \return (Vertex*) returns a pointer to the vertex which is the head of the edge.
		*/
		Vertex*	getHead ();
		
		/*!
		*  \brief Getter of the Edge class.
		*
		*  Getter of the Edge class.
		*
		*  \return (Edge) returns a pointer to the twin edge of the edge.
		*/
		Edge*	getTwin ();
		
		/*!
		*  \brief Getter of the Edge class.
		*
		*  Getter of the Edge class.
		*
		*  \return (vector<Face*>) returns a vector containing the faces that contain the edge.
		*/
		vector<Face*>	getFaces ();
		
		/*!
		*  \brief Getter of the Edge class.
		*
		*  Getter of the Edge class.
		*
		*  \param _i : index of the face to return;
		*
		*  \return (Face*) returns a pointer to the ith face in the face array of the edge;
		*/
		Face*	getIFace ( int _i );
		
		/*!
		*  \brief Convert an edge to a 3 dimension vector.
		*
		*  Convert an edge to the 3 dimension vector defined as (head - tail).
		*
		*  \return (Vector3D) returns a vector computed as (head - tail).
		*/
		Vector3D toVector ();
		
		/*!
		*  \brief Setter of the Edge class.
		*
		*  Setter of the Edge class.
		*
		*  \param _ID : ID to affect to the edge.
		*
		*  \return (void)
		*/
		void setID ( int _ID );
		
		/*!
		*  \brief Setter of the Edge class.
		*
		*  Setter of the Edge class.
		*
		*  \param _tail : pointer to the vertex to affect to the tail of the edge.
		*
		*  \return (void)
		*/
		void setTail ( Vertex* _tail );
		
		/*!
		*  \brief Setter of the Edge class.
		*
		*  Setter of the Edge class.
		*
		*  \param _head : pointer to the vertex to affect to the head of the edge.
		*
		*  \return (void)
		*/
		void setHead ( Vertex* _head );
		
		/*!
		*  \brief Setter of the Edge class.
		*
		*  Setter of the Edge class.
		*
		*  \param _twin : pointer to the edge affect to the twin of the edge.
		*
		*  \return (void)
		*/
		void setTwin ( Edge* _twin );
		
		/*!
		*  \brief Setter of the Edge class.
		*
		*  Setter of the Edge class.
		*
		*  \param _faces : vector containing faces to affect to the faces attribut of the edge.
		*
		*  \return (void)
		*/
		void setFaces ( vector<Face*> _faces );
		
		/*!
		*  \brief Adds a face to the edge.
		*
		*  Adds a given face to the edge.
		*
		*  \param _f : face to add to the edge.
		*
		*  \return (void)
		*/
		void addFace ( Face* _f );
};

class Face
{
	/*!
	 * \class Face
	 * \brief Classe représentant une face, soit, un polygone appartenant au mesh.
	 * Une face est representee par ses elements les plus courant, a savoir : un idfentifiant unique pour chaque face d'un meme maillage, un vecteur mormal a cette face.
	 * 
	 * Le polygone d'une face s'obtient en parcourant dans l'ordre le tableau d'aretes de la face : une face dont le polygone est forme des points {0, 1, 2} aura le tableau d'aretes suivant :
	 * {[0,1] [1,2] [2,0]} avec [0,1] representant l'arete qui part du point 0 pour aller vers le point 1.
	 * Les informations de voisinnage s'obtiennent aussi en parcourant ce tableau (et eventuellement les tableaux de ces aretes).
	 *
	 */
	
	private :
		int				id;				/*! <ID of the face. */
		Vector3D		normal;			/*! <Normal vector to the face. */
		vector<Edge*>	edges;			/*! <List of edges that makes the face : they describe a line loop. */
		
	public :
		/*!
		*  \brief Default constructor of the Face class.
		*
		*  Default constructor of the Face class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Face();
	
		/*!
		*  \brief Copy constructor of the Face class.
		*
		*  Copy constructor of the Face class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Face( const Face& _face );
		
		/*!
		*  \brief Overloaded constructor of the Face class.
		*
		*  Overloaded constructor of the Face class : fill the id and of the edge. The rest is initialized to 0, NULL or cleared.
		*/
		Face( int _ID );
		
		/*!
		*  \brief Overloaded constructor of the Face class.
		*
		*  Overloaded constructor of the Face class : fill the id and the edges vector of the face. The normal will be set to 0;
		*/
		Face( int _ID, vector<Edge*> _edges );
		
		/*!
		*  \brief Destructor of the Face class.
		*
		*  Destructor of the Face class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		~Face();
		
		/*!
		*  \brief Affectation operator of the Face class.
		*
		*  Affectation operator of the Face class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Face& operator= ( const Face& _face );
		
		/*!
		*  \brief Getter of the Face class.
		*
		*  Getter of the Face class.
		*
		*  \return (int) returns the ID of the face.
		*/
		int getID ();
		
		/*!
		*  \brief Getter of the Face class.
		*
		*  Getter of the Face class.
		*
		*  \return (Vector3D) returns the normal to the face.
		*/
		Vector3D getNormal ();
		
		/*!
		*  \brief Getter of the Face class.
		*
		*  Getter of the Face class, returns a doule array instead of a Vector3D.
		*
		*  \return (double*) returns the norma to the face.
		*/
		double* getNormalArray ();
		
		/*!
		*  \brief Getter of the Face class.
		*
		*  Getter of the Face class.
		*
		*  \return (vector<Edge*>) returns a vector of the edges composing the face.
		*/
		vector<Edge*> getEdges ();
		
		/*!
		*  \brief Setter of the Face class.
		*
		*  Setter of the Face class.
		*
		*  \param _ID : ID we want to affect to the face.
		*
		*  \return (void)
		*/
		void setID ( int _ID );
		
		/*!
		*  \brief Setter of the Face class.
		*
		*  Setter of the Face class.
		*
		*  \param _normal : the normal we want to affect to the face.
		*
		*  \return (void)
		*/
		void setNormal ( Vector3D _normal );
		
		/*!
		*  \brief Setter of the Face class.
		*
		*  Setter of the Face class.
		*
		*  \param _edges : vector of the edges we want to affect to the edges attribute of the face.
		*
		*  \return (void)
		*/
		void setEdges ( vector<Edge*> _edges );
		
		/*!
		*  \brief Adds an edge to the face.
		*
		*  Adds a given edge to the face.
		*
		*  \param _e : the edge to add to the face.
		*
		*  \return (void)
		*/
		void addEdge ( Edge* _e );
};

#endif
