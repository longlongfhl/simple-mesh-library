#ifndef SEGMENT_H
#define SEGMENT_H

/**
 * \file	segment.h
 * \brief	Declaration de la classe Segment representant un ensemble connexe de vertex dans un maillage appartenants a la meme classe de segmentation (voir la classe \class Map, methode segment).
 */

/* ______________________________ My includes ____ */
#include "mesh.h"

/* ____________________________ STD Librairies ___ */
#include <list>

/*! \def EQUAL
  criteria of creation of a Segment : all neighbours with the same map value will constitute the segment.
 */
#define EQUAL 0

/*! \def GREATER_EQUAL
  criteria of creation of a Segment : all neighbours with a value equal or greater than the seed vertex value will constitute the segment.
 */
#define GREATER_EQUAL 1

/*! \def LESSER_EQUAL
  criteria of creation of a Segment : all neighbours with a value equal or lesser than the seed vertex value will constitute the segment.
 */
#define LESSER_EQUAL 2

using namespace std;

class Segment
{
	/*!
	 * \class Segment
	 * \brief Classe représentant une zone connexe d'un maillage dont tous les vertex partagent une propriete vis-a-vis de leur valeur dans une map.
	 * 
	 * Classe représentant une zone connexe d'un maillage dont tous les vertex partagent une propriete vis-a-vis de leur valeur dans une map :
	 * Exemples :
	 * - tous les vertex de la zone ont une valeur inferieure a un seuil.
	 * - tous les vertex de la zone ont la meme valeur.
	 * - ...
	 *
	 * The creation of a segment is usually defined by a criteria AND a specific vertex on a given mesh we will call the "seed".
	 * 
	 * Des methodes peuvent etre ajoutees pour creer des segments selon d'autres proprietes que celles presntes.
	 * D'autres critere de reation de zone peuvent aussi etre ajoutes par la suite selon les besoins des utilisateurs.
	 * Exemples :
	 * - Un vertex appartient au segment si la distance euclidienne entre lui et le segment est plus petite qu'un seuil.
	 *   Ce qui engendrerait une zone a l'interieur de laquelle tous les vertex seraient proches les uns des autres (selon le seuil).
	 * - Idem selon des criteres d'aires, de couleur, de deplacements...
	 * - ...
	 *
	 */
	
private :
	int				id;			/*! <Every segment is given an ID which should be unique.*/
	double			depth;		/*! <Every segment is given a depth according to a map.*/
	Vector3D		color;		/*! <Every segment is given a color to facilitate the future display methods.*/
	list<Vertex*>	verts;		/*! <A list containing a pointer to every vertex contained in the segment.*/
	
public:
	/*!
	*  \brief Default constructor of the Segment class.
	*
	*  Default constructor of the Segment class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
	*/
    Segment();
	
	/*!
	*  \brief Copy constructor of the Segment class.
	*
	*  Copy constructor of the Segment class.
	*/
	Segment ( const Segment& _s );
	
	/*!
	*  \brief Destructor of the Segment class.
	*
	*  Destructor of the Segment class.
	*/
	~Segment();
	
	/*!
	*  \brief Affectation operator of the Segment class.
	*
	*  Affectation operator of the Segment class.
	*/
	Segment& operator= ( const Segment& _s );
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \return (int) returns the ID of the Segment.
	*/
	int getID ();
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \return (int) returns the depth of the Segment.
	*/
	double getDepth ();
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \return (int) returns the color of the Segment.
	*/
	Vector3D getColor ();
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \return (int) returns the color of the Segment in a double[3] array.
	*/
	double* getColorArray ();
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \return (int) returns a list containing each vertex that is a part of the Segment.
	*/
	list<Vertex*> getVerts ();
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \param _ID : ID to attribute to the segment.
	*
	*  \return (void)
	*/
	void setID ( int _ID );
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \param _depth : Depth to attribute to the segment.
	*
	*  \return (void)
	*/
	void setDepth ( double _depth );
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \param _color : Color to attribute to the segment.
	*
	*  \return (void)
	*/
	void setColor ( Vector3D _color );
	
	/*!
	*  \brief Getter of the Segment class.
	*
	*  Getter of the Segment class.
	*
	*  \param _v : list of vertex containing each vertex of the segment.
	*
	*  \return (void)
	*/
	void setVerts ( list<Vertex*> _v );
	
	/*!
	*  \brief Adds a vertex to the Segment.
	*
	*  Adds a vertex to the Segment.
	*
	*  \param _v : Vertex to add to the segment.
	*
	*  \return (void)
	*/
	void addVert ( Vertex* _v );
	
	/*!
	*  \brief Creates a segment within the "equal value" criteria.
	*
	*  Creates a segment within the "equal value" criteria :
	*  Every vertex with the same value than the seed value and which is a part of the segment neighbour will be added to the Segment.
	*
	*  \param _seed : "seed" vertex : the segment to create will grown from this vertex.
	*  \param _mesh : The mesh containing the seed vertex. Essential to get the neighbourhood informations.
	*  \param _map : map describing the vertices values.
	*
	* \warning This function does not initialize neither the color of the segment, nor its id;
	*
	*  \return (void)
	*
	*  \todo il faudra penser pourquoi pas a ajouter un attribut feature a chaque vertex. Cela evitera de passer une map en parametre de cette methode.
	*/
	void createFromSeed_Eq ( Vertex* _seed, Mesh _mesh, Map _map );
	
	/*!
	*  \brief Creates a segment within the "Greater or equal value" criteria.
	*
	*  Creates a segment within the "Greater or equal than value" criteria :
	*  Every vertex with the same value or a greater value than the seed value and which is a part of the segment neighbour will be added to the Segment.
	*
	* \warning This function does not initialize neither the color of the segment, nor its id;
	*
	*  \param _seed : "seed" vertex : the segment to create will grown from this vertex.
	*  \param _mesh : The mesh containing the seed vertex. Essential to get the neighbourhood informations.
	*  \param _map : map describing the vertices values.
	*
	*  \return (void)
	*/
	void createFromSeed_GrEq ( Vertex* _seed, Mesh _mesh, Map _map );
	
	/*!
	*  \brief Creates a segment within the "Lesser or equal value" criteria.
	*
	*  Creates a segment within the "Lesser or equal value" criteria :
	*  Every vertex with the same value or a lesser value than the seed value and which is a part of the segment neighbour will be added to the Segment.
	*
	* \warning This function does not initialize neither the color of the segment, nor its id;
	*
	*  \param _seed : "seed" vertex : the segment to create will grown from this vertex.
	*  \param _mesh : The mesh containing the seed vertex. Essential to get the neighbourhood informations.
	*  \param _map : map describing the vertices values.
	*
	*  \return (void)
	*/
	void createFromSeed_LeEq ( Vertex* _seed, Mesh _mesh, Map _map );
	
	/*!
	*  \brief Creates a segment within a specific criteria.
	*
	*  Creates a segment within a specific criteria.
	*
	* \warning This function does not initialize neither the color of the segment, nor its id;
	*
	*  \param _criteria : criteria of segment creation. Can be set as EQUAL, GREATER_EQUAL or LESSER_EQUAL.
	*  \param _seed : "seed" vertex : the segment to create will grown from this vertex.
	*  \param _mesh : The mesh containing the seed vertex. Essential to get the neighbourhood informations.
	*  \param _map : map describing the vertices values.
	*
	*  \return (void)
	*/
	void createFromSeed ( int _criteria, Vertex* _seed, Mesh _mesh, Map _map );
	
	/*!
	*  \brief Notice whether or not a vertex is contained in the segment.
	*
	*  Notice whether or not a given vertex is contained in the segment.
	*
	*  \param _v : Vertex we want to know if it is contained in the Segment.
	*
	*  \return (bool) Return true if the segment contains _v, false else.
	*/
	bool contains ( Vertex* _v );
	
	/*!
	*  \brief Displays the vertices contained in a Segment.
	*
	*  Displays the vertices contained in a Segment.
	*
	*  \param _r : Red component of the color to display.
	*  \param _g : Green component of the color to display.
	*  \param _b : Blue component of the color to display.
	*
	*  \return (void)
	*/
	void displayVertices ( float _r, float _g, float _b );
	
	/*!
	*  \brief Displays the vertices contained in a Segment.
	*
	*  Displays the vertices contained in a Segment.
	*
	*  \return (void)
	*/
	void displayVertices ();
	
	/*!
	*  \brief Displays the edges contained in a Segment.
	*
	*  Displays the edges contained in a Segment.
	*  To make this methode faster, we can suppres the test of owning of boths vertices of the edge to the segment.
	*  This will be faster but some edges with an extremity which is not a part of the segment would be drawed;
	*
	*  \param _r : Red component of the color to display.
	*  \param _g : Green component of the color to display.
	*  \param _b : Blue component of the color to display.
	*
	*  \return (void)
	*/
	void displayEdges ( float _r, float _g, float _b );
	
	/*!
	*  \brief Displays the edges contained in a Segment.
	*
	*  Displays the edges contained in a Segment.
	*  To make this methode faster, we can suppres the test of owning of boths vertices of the edge to the segment.
	*  This will be faster but some edges with an extremity which is not a part of the segment would be drawed;
	*
	*  \return (void)
	*/
	void displayEdges ();
	
	/*!
	*  \brief Displays the faces contained in a Segment.
	*
	*  Displays the faces contained in a Segment :
	*  Every face containing at least one vertex of the segment is diaplyed.
	*
	*  \param _r : Red component of the color to display.
	*  \param _g : Green component of the color to display.
	*  \param _b : Blue component of the color to display.
	*
	*  \return (void)
	*/
	void displayFaces ( float _r, float _g, float _b );
	
	/*!
	*  \brief Displays the faces contained in a Segment.
	*
	*  Displays the faces contained in a Segment.
	*  Every face containing at least one vertex of the segment is diaplyed.
	*
	*  \return (void)
	*/
	void displayFaces ();
	
	/*!
	*  \brief Displays the Segment in a selected mode.
	*
	*  Displays the Segment in a selected mode.
	*
	*  \param _mode : mode to display the Segment. Can be set to VERTICES, EDGES or FACES.
	*  \param _r : Red component of the color to display.
	*  \param _g : Green component of the color to display.
	*  \param _b : Blue component of the color to display.
	*
	*  \return (void)
	*/
	void display ( int _mode, float _r, float _g, float _b );
	
	/*!
	*  \brief Displays the Segment in a selected mode.
	*
	*  Displays the Segment in a selected mode.
	*
	*  \param _mode : mode to display the Segment. Can be set to VERTICES, EDGES or FACES.
	*
	*  \return (void)
	*/
	void display ( int _mode=FACES );
};

#endif
