#include <iostream>
#include "../inc/define.h"

using namespace std;

Vertex::Vertex()
{
	id = 0;
	
	pos.set( 0, 0, 0 );
	color.set( 0, 0, 0 );
	normal.set( 0, 0, 0 );
	
	edges.clear();
}

Vertex::Vertex(const Vertex & _v)
{
	id = _v.id;
	
	pos = _v.pos;
	color = _v.color;
	normal = _v.normal;
	
	edges.clear();
	edges.assign( _v.edges.begin(), _v.edges.end() );
}

Vertex::Vertex(int _ID, Vector3D _pos)
{
	id = _ID;
	
	pos = _pos;
	color.set( 0, 0, 0 );
	normal.set( 0, 0, 0 );
	
	edges.clear();
}

Vertex::~Vertex()
{
	pos.~Vector3D();
	color.~Vector3D();
	normal.~Vector3D();
	edges.clear();
}

Vertex& Vertex::operator = ( const Vertex& _v )
{
	id = _v.id;
	
	pos = _v.pos;
	color = _v.color;
	normal = _v.normal;
	
	edges.clear();
	edges.assign( _v.edges.begin(), _v.edges.end() );
	
	return *this;
}

int Vertex::getID()
{
	return id;
}

Vector3D Vertex::getPos()
{
	return pos;
}

double* Vertex::getPosArray()
{
	return pos.getArray();
}

Vector3D Vertex::getColor()
{
	return color;
}

double* Vertex::getColorArray()
{
	return color.getArray();
}

Vector3D Vertex::getNormal()
{
	return normal;
}

double* Vertex::getNormalArray()
{
	return normal.getArray();
}

vector<Edge*> Vertex::getEdges()
{
	return edges;
}

Edge* Vertex::getIEdge(int _i)
{
	return edges[_i];
}

void Vertex::printID()
{
	cout<<"ID "<<id<<endl;
}

void Vertex::printPos()
{
	cout<<"Position ";
	pos.print();
}

void Vertex::printNormal()
{
	cout<<"Normal ";
	normal.print();
}

void Vertex::printColor()
{
	cout<<"Color ";
	color.print();
}

void Vertex::print()
{
	this->printID();
	this->printPos();
	this->printNormal();
	this->printColor();
}

void Vertex::setID(int _ID)
{
	id = _ID;
}

void Vertex::setPos(Vector3D _pos)
{
	pos = _pos;
}

void Vertex::setPos(double *_pos)
{
	pos.set( _pos[0], _pos[1], _pos[2] );
}

void Vertex::setNormal(Vector3D _normal)
{
	normal = _normal;
}

void Vertex::setNormal(double *_normal)
{
	normal.set( _normal[0], _normal[1], _normal[2] );
}

void Vertex::setColor(Vector3D _color)
{
	color = _color;
}

void Vertex::setColor(double *_color)
{
	color.set( _color[0], _color[1], _color[2] );
}

void Vertex::setEdges(vector<Edge*> _edges)
{
	edges.clear();
	edges.assign( _edges.begin(), _edges.end() );
}

int Vertex::containsEdge(int _iTail, int _iHead)
{	
	for ( int i = 0 ; i < (int)edges.size() ; i++ )
	{
		if ( this->getIEdge(i)->getTail()->getID() == _iTail && this->getIEdge(i)->getHead()->getID() == _iHead )
		{
			return this->getIEdge(i)->getID();
		}
	}
	
	return -1;
}

void Vertex::addEdge(Edge *_e)
{
	edges.push_back( _e );
}
























































Edge::Edge()
{
	id = 0;
	tail = NULL;
	head = NULL;
	twin = NULL;
	faces.clear();
}

Edge::Edge(int _ID, Vertex *_tail, Vertex *_head)
{
	id = _ID;
	tail = _tail;
	head = _head;
	twin = NULL;
	
	faces.clear();
}

Edge::Edge(const Edge &_e)
{
	id = _e.id;
	tail = _e.tail;
	head = _e.head;
	twin = _e.twin;
	
	faces.clear();
	faces.assign( _e.faces.begin(), _e.faces.end() );
}

Edge::~Edge()
{
	/*
	free ( &tail );
	free ( &head );
	free ( &twin );
	I am not sure that these instructions won't erase what is pointed by tail, head and twin so i comment it and let someone else judge the situation.
	*/
	faces.clear();
}

Edge& Edge::operator = ( const Edge& _e )
{
	id = _e.id;
	tail = _e.tail;
	head = _e.head;
	twin = _e.twin;
	
	faces.clear();
	faces.assign( _e.faces.begin(), _e.faces.end() );
	
	return *this;
}

int Edge::getID()
{
	return id;
}

Vertex* Edge::getTail()
{
	return tail;
}

Vertex* Edge::getHead()
{
	return head;
}

Edge* Edge::getTwin()
{
	return twin;
}

vector<Face*> Edge::getFaces()
{
	return faces;
}

Face* Edge::getIFace( int _i )
{
	return faces[_i];
}

Vector3D Edge::toVector()
{
	Vector3D rslt;
	
	rslt = head->getPos() - tail->getPos();
	
	return rslt;
}

void Edge::setID(int _ID)
{
	id = _ID;
}

void Edge::setHead(Vertex *_head)
{
	head = _head;
}

void Edge::setTail(Vertex *_tail)
{
	tail = _tail;
}

void Edge::setTwin(Edge *_twin)
{
	twin = _twin;
}

void Edge::setFaces(vector<Face *> _faces)
{
	faces.clear();
	faces.assign( _faces.begin(), _faces.end() );
}

void Edge::addFace(Face *_f)
{
	faces.push_back( _f );
}




































Face::Face()
{
	id = 0;
	
	/*normal.set( 0, 0, 0 );*/
	normal.setX( 0 );
	
	edges.clear();
}

Face::Face(const Face &_face)
{
	id = _face.id;
	normal = _face.normal;
	
	edges.clear();
	edges.assign( _face.edges.begin(), _face.edges.end() );
}

Face::Face(int _ID)
{
	id = _ID;
	
	edges.clear();
	normal.set( 0, 0, 0 );
}

Face::Face(int _ID, vector<Edge *> _edges)
{
	id = _ID;
	edges = _edges;
	
	normal.set ( 0, 0, 0 );
}

Face::~Face()
{
	normal.~Vector3D();
	edges.clear();
}

Face& Face::operator = ( const Face& _f )
{
	id = _f.id;
	normal = _f.normal;
	edges.clear();
	edges.assign( _f.edges.begin(), _f.edges.end() );
	
	return *this;
}

int Face::getID()
{
	return id;
}

Vector3D Face::getNormal()
{
	return normal;
}

double* Face::getNormalArray()
{
	return normal.getArray();
}

vector<Edge*> Face::getEdges()
{
	return edges;
}

void Face::setID(int _ID)
{
	id = _ID;
}

void Face::setNormal(Vector3D _normal)
{
	normal = _normal;
}

void Face::setEdges(vector<Edge *> _edges)
{
	edges.clear();
	edges.assign( _edges.begin(), _edges.end() );
}

void Face::addEdge(Edge *_e)
{
	edges.push_back( _e );
}

void Face::display(float _r, float _g, float _b )
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_POLYGON );
	
	for ( int i = 0 ; i < (int)edges.size() ; i++ )
	{
		glNormal3dv ( edges[i]->getHead()->getNormalArray() );
		glVertex3dv ( edges[i]->getHead()->getPosArray() );
	}
	
	glEnd();
}

void Face::display()
{
	glBegin ( GL_POLYGON );
	
	for ( int i = 0 ; i < (int)edges.size() ; i++ )
	{
		glColor3dv ( edges[i]->getHead()->getColorArray() );
		glNormal3dv ( edges[i]->getHead()->getNormalArray() );
		glVertex3dv ( edges[i]->getHead()->getPosArray() );
	}
	
	glEnd();
}
