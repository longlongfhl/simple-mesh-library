#include "../inc/segment.h"

Segment::Segment()
{
	id = 0;
	depth = 0;
	color.clear();
	verts.clear();
}

Segment::Segment(const Segment &_s)
{
	id = _s.id;
	depth = _s.depth;
	color = _s.color;
	verts.clear();
	verts = _s.verts;
}

Segment::~Segment()
{
	verts.clear();
}

Segment& Segment::operator = ( const Segment& _s )
{
	id = _s.id;
	depth = _s.depth;
	color = _s.color;
	verts.clear();
	verts = _s.verts;
	
	return *this;
}

int Segment::getID()
{
	return id;
}

double Segment::getDepth()
{
	return depth;
}

Vector3D Segment::getColor()
{
	return color;
}

double* Segment::getColorArray()
{
	return color.getArray();
}

list<Vertex*> Segment::getVerts()
{
	return verts;
}

void Segment::setID(int _ID)
{
	id = _ID;
}

void Segment::setDepth(double _depth)
{
	depth = _depth;
}

void Segment::setColor(Vector3D _color)
{
	color = _color;
}

void Segment::setVerts(list<Vertex *> _v)
{
	verts = _v;
}

void Segment::addVert(Vertex *_v)
{
	verts.push_back( _v );
}

void Segment::createFromSeed_Eq(Vertex *_seed, Mesh _mesh, Map _map)
{
	/* Launches a kind of breadth-first search algorithm from the seed vertex on the given mesh.
	   If one of the vertex in the Segment neighbourhood verify the criteria, it is added to the segment.
	   Else it is simlpy marked and non of its neighbours are added for searching.
	   See http://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur or http://en.wikipedia.org/wiki/Breadth-first_search for more
	   informations about the breadth-first searching algorithm. It should help understamnding the code of this methode.
	*/
	double			seedValue = _map.getIData( _seed->getID() );
	int				neighbourID = 0;
	int*			mark = (int*) calloc ( _mesh.getNVerts(), sizeof(int));		/* A marking array. */
	list<Vertex*>	list;
	
	/* Add the seed to the Segment */
	verts.clear();
	addVert( _seed );
	
	/* Add the seed to the list. */
	list.push_back( _seed );
	
	while ( !list.empty() )
	{
		/* While list is not empty. */
		Vertex* v = list.front();
		list.pop_front();
		
		/* We then search for every neighbour of v. */
		for ( int i = 0 ; i < (int)v->getEdges().size() ; i++ )
		{
			neighbourID = v->getIEdge(i)->getHead()->getID();
			/* If it is not marked, then we mark it and if it has the same value than the seed value, we add it to the list list. */
			if ( mark[ neighbourID ] == 0 )
			{
				mark[ neighbourID ] = 1;
				
				if ( _map.getIData( neighbourID ) == seedValue )
				{
					/* Adding the neighbour to the list list AND to the result segment. */
					list.push_back( v->getIEdge(i)->getHead() );
					addVert( v->getIEdge(i)->getHead() );
				}
			}
		}
	}
	
	free (mark);
}

void Segment::createFromSeed_GrEq(Vertex *_seed, Mesh _mesh, Map _map)
{
	/* Launches a kind of breadth-first search algorithm from the seed vertex on the given mesh.
	   If one of the vertex in the Segment neighbourhood verify the criteria, it is added to the segment.
	   Else it is simlpy marked and non of its neighbours are added for searching.
	   See http://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur or http://en.wikipedia.org/wiki/Breadth-first_search for more
	   informations about the breadth-first searching algorithm. It should help understamnding the code of this methode.
	*/
	double			seedValue = _map.getIData( _seed->getID() );
	int				neighbourID = 0;
	int*			mark = (int*) calloc ( _mesh.getNVerts(), sizeof(int));		/* A marking array. */
	list<Vertex*>	list;
	
	/* Add the seed to the Segment */
	verts.clear();
	addVert( _seed );
	
	/* Add the seed to the list. */
	list.push_back( _seed );
	
	while ( !list.empty() )
	{
		/* While list is not empty. */
		Vertex* v = list.front();
		list.pop_front();
		
		/* We then search for every neighbour of v. */
		for ( int i = 0 ; i < (int)v->getEdges().size() ; i++ )
		{
			neighbourID = v->getIEdge(i)->getHead()->getID();
			/* If it is not marked, then we mark it and if it has the same value than the seed value, we add it to the list list. */
			if ( mark[ neighbourID ] == 0 )
			{
				mark[ neighbourID ] = 1;
				
				if ( _map.getIData( neighbourID ) >= seedValue )
				{
					/* Adding the neighbour to the list list AND to the result segment. */
					list.push_back( v->getIEdge(i)->getHead() );
					addVert( v->getIEdge(i)->getHead() );
				}
			}
		}
	}
	
	free (mark);
}

void Segment::createFromSeed_LeEq(Vertex *_seed, Mesh _mesh, Map _map)
{
	/* Launches a kind of breadth-first search algorithm from the seed vertex on the given mesh.
	   If one of the vertex in the Segment neighbourhood verify the criteria, it is added to the segment.
	   Else it is simlpy marked and non of its neighbours are added for searching.
	   See http://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur or http://en.wikipedia.org/wiki/Breadth-first_search for more
	   informations about the breadth-first searching algorithm. It should help understamnding the code of this methode.
	*/
	double			seedValue = _map.getIData( _seed->getID() );
	int				neighbourID = 0;
	int*			mark = (int*) calloc ( _mesh.getNVerts(), sizeof(int));		/* A marking array. */
	list<Vertex*>	list;
	
	/* Add the seed to the Segment */
	verts.clear();
	addVert( _seed );
	
	/* Add the seed to the list. */
	list.push_back( _seed );
	
	while ( !list.empty() )
	{
		/* While list is not empty. */
		Vertex* v = list.front();
		list.pop_front();
		
		/* We then search for every neighbour of v. */
		for ( int i = 0 ; i < (int)v->getEdges().size() ; i++ )
		{
			neighbourID = v->getIEdge(i)->getHead()->getID();
			
			/* If it is not marked, then we mark it and if it has the same value than the seed value, we add it to the list list. */
			if ( mark[ neighbourID ] == 0 )
			{
				mark[ neighbourID ] = 1;
				
				if ( _map.getIData( neighbourID ) <= seedValue )
				{
					/* Adding the neighbour to the list list AND to the result segment. */
					list.push_back( v->getIEdge(i)->getHead() );
					addVert( v->getIEdge(i)->getHead() );
				}
			}
		}
	}
	
	free (mark);
}

void Segment::createFromSeed(int _criteria, Vertex *_seed, Mesh _mesh, Map _map)
{
	switch ( _criteria )
	{
		case EQUAL :
			createFromSeed_Eq( _seed, _mesh, _map );
			break;
		
		case GREATER_EQUAL :
			createFromSeed_GrEq( _seed, _mesh, _map );
			break;
		
		case LESSER_EQUAL :
			createFromSeed_LeEq( _seed, _mesh, _map );
			break;
		
		default :
			cout<<"Unknown criteria in the Segment::createFromSeed method"<<endl;
			cout<<"Segment creation aborted"<<endl;
			break;
	}
}

bool Segment::contains(Vertex *_v)
{
	for ( list<Vertex*>::iterator it = verts.begin() ; it != verts.end() ; it++ )
	{
		if ( (*it) == _v )
			return true;
	}
	
	return false;
}

void Segment::displayVertices(float _r, float _g, float _b)
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_POINTS );
	for ( list<Vertex*>::iterator it = verts.begin() ; it != verts.end() ; it++ )
	{
		glNormal3dv( (*it)->getNormalArray() );
		glVertex3dv( (*it)->getPosArray() );
	}
	glEnd();
}

void Segment::displayVertices()
{
	glBegin ( GL_POINTS );
	for ( list<Vertex*>::iterator it = verts.begin() ; it != verts.end() ; it++ )
	{
		glColor3dv( (*it)->getColorArray() );
		glNormal3dv( (*it)->getNormalArray() );
		glVertex3dv( (*it)->getPosArray() );
	}
	glEnd();
}

void Segment::displayEdges(float _r, float _g, float _b)
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_LINES );
	for ( list<Vertex*>::iterator it = verts.begin() ; it != verts.end() ; it++ )
	{
		for ( int i = 0 ; i < (int)(*it)->getEdges().size() ; i++ )
		{
			/* We take a lookt at every neighbours of (*it). If it is in the Segment, we draw it, otherwise we don't. */
			Vertex* head = (*it)->getIEdge(i)->getHead();
			
			if ( contains( head ) )
			{
				/* The (*it) vertex is the tail of the edge. */
				glNormal3dv( (*it)->getNormalArray() );
				glVertex3dv( (*it)->getPosArray() );
				
				/* Now displayin the head. */
				glNormal3dv( head->getNormalArray() );
				glVertex3dv( head->getPosArray() );
			}
		}
	}
	glEnd();
}

void Segment::displayEdges()
{
	glBegin ( GL_LINES );
	for ( list<Vertex*>::iterator it = verts.begin() ; it != verts.end() ; it++ )
	{
		for ( int i = 0 ; i < (int)(*it)->getEdges().size() ; i++ )
		{
			/* We take a lookt at every neighbours of (*it). If it is in the Segment, we draw it, otherwise we don't. */
			Vertex* head = (*it)->getIEdge(i)->getHead();
			
			if ( contains( head ) )
			{
				/* The (*it) vertex is the tail of the edge. */
				glColor3dv( (*it)->getColorArray() );
				glNormal3dv( (*it)->getNormalArray() );
				glVertex3dv( (*it)->getPosArray() );
				
				/* Now displayin the head. */
				glColor3dv( head->getColorArray() );
				glNormal3dv( head->getNormalArray() );
				glVertex3dv( head->getPosArray() );
			}
		}
	}
	glEnd();
}

void Segment::displayFaces(float _r, float _g, float _b)
{
	for ( list<Vertex*>::iterator it = verts.begin() ; it != verts.end() ; it++ )
	{
		for ( int i = 0 ; i < (int)(*it)->getEdges().size() ; i++ )
		{
			/* We take a lookt at every neighbours of (*it). If it is in the Segment, we draw it, otherwise we don't. */
			Edge* e = (*it)->getIEdge(i);
			
			for ( int j = 0 ; j < (int)e->getFaces().size() ; j++ )
			{
				e->getIFace(j)->display( _r, _g, _b );
			}
		}
	}
}

void Segment::displayFaces()
{
	for ( list<Vertex*>::iterator it = verts.begin() ; it != verts.end() ; it++ )
	{
		for ( int i = 0 ; i < (int)(*it)->getEdges().size() ; i++ )
		{
			/* We take a lookt at every neighbours of (*it). If it is in the Segment, we draw it, otherwise we don't. */
			Edge* e = (*it)->getIEdge(i);
			
			for ( int j = 0 ; j < (int)e->getFaces().size() ; j++ )
			{
				e->getIFace(j)->display();
			}
		}
	}
}

void Segment::display(int _mode)
{
	switch ( _mode )
	{
		case VERTICES :
			displayVertices();
			break;
			
		case EDGES :
			displayEdges();
			break;
			
		case FACES :
			displayFaces();
			break;
		
		default :
			cout<<"Unknown mode selected in the Segment::display method"<<endl;
			cout<<"Segment not displayed"<<endl;
			break;
	}
}

void Segment::display(int _mode, float _r, float _g, float _b)
{
	switch ( _mode )
	{
		case VERTICES :
			displayVertices( _r, _g, _b );
			break;
			
		case EDGES :
			displayEdges( _r, _g, _b  );
			break;
			
		case FACES :
			displayFaces( _r, _g, _b  );
			break;
		
		default :
			cout<<"Unknown mode selected in the Segment::display method"<<endl;
			cout<<"Segment not displayed"<<endl;
			break;
	}
}
