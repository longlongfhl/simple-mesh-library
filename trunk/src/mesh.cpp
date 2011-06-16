#include "../inc/mesh.h"
#include <math.h>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>

Mesh::Mesh()
{
	id = 0;
	
	nVerts = 0;
	nEdges = 0;
	nFaces = 0;
	
	verts.clear();
	edges.clear();
	faces.clear();
}

Mesh::Mesh(const Mesh &_m)
{
	id = _m.id;
	nVerts = _m.nVerts;
	nEdges = _m.nEdges;
	nFaces = _m.nFaces;
	
	verts.clear();
	edges.clear();
	faces.clear();
	
	verts.assign( _m.verts.begin(), _m.verts.end() );
	edges.assign( _m.edges.begin(), _m.edges.end() );
	faces.assign( _m.faces.begin(), _m.faces.end() );
}

Mesh::~Mesh()
{
	verts.clear();
	edges.clear();
	faces.clear();
}

Mesh& Mesh::operator = ( const Mesh& _m )
{
	id = _m.id;
	nVerts = _m.nVerts;
	nEdges = _m.nEdges;
	nFaces = _m.nFaces;
	
	verts.clear();
	edges.clear();
	faces.clear();
	
	verts.assign( _m.verts.begin(), _m.verts.end() );
	edges.assign( _m.edges.begin(), _m.edges.end() );
	faces.assign( _m.faces.begin(), _m.faces.end() );
	
	return *this;
}


int Mesh::getID()
{
	return id;
}

int Mesh::getNVerts()
{
	return nVerts;
}

int Mesh::getNEdges()
{
	return nEdges;
}

int Mesh::getNFaces()
{
	return nFaces;
}

vector<Vertex*> Mesh::getVerts()
{
	return verts;
}

Vertex* Mesh::getIVert(int _i)
{
	return verts[_i];
}

vector<Edge*> Mesh::getEdges()
{
	return edges;
}

Edge* Mesh::getIEdge(int _i)
{
	return edges[_i];
}

vector<Face*> Mesh::getFaces()
{
	return faces;
}

void Mesh::setID(int _ID)
{
	id = _ID;
}

void Mesh::setNVerts(int _nVerts)
{
	nVerts = _nVerts;
}

void Mesh::setNEdges(int _nEdges)
{
	nEdges = _nEdges;
}

void Mesh::setNFaces(int _nFaces)
{
	nFaces = _nFaces;
}

void Mesh::setVerts(vector<Vertex *> _verts)
{
	verts = _verts;
}

void Mesh::setEdges(vector<Edge *> _edges)
{
	edges = _edges;
}

void Mesh::setFaces(vector<Face *> _faces)
{
	faces = _faces;
}

void Mesh::clear()
{
	id = 0;
	
	nVerts = 0;
	nEdges = 0;
	nFaces = 0;
	
	verts.clear();
	edges.clear();
	faces.clear();
}

int Mesh::containsEdge(int _iTail, int _iHead)
{
	for ( int i = 0 ; i < nEdges ; i++ )
	{
		if ( this->getIEdge( i )->getTail()->getID() == _iTail && this->getIEdge( i )->getHead()->getID() == _iHead )
		{
			return i;
		}
	}
	
	return -1;
}

void Mesh::addVertex(Vertex *_v)
{
	verts.push_back( _v );
	nVerts++;
}

void Mesh::addEdgeToIVertex(int _i, Edge *_e)
{
	verts[_i]->addEdge ( _e );
}

void Mesh::addEdge(Edge *_e)
{
	edges.push_back( _e );
	nEdges++;
}

void Mesh::addFaceToIEdge(int _i, Face *_f)
{
	edges[_i]->addFace( _f );
}

void Mesh::addFace(Face *_f)
{
	faces.push_back( _f );
	nFaces++;
}

int Mesh::loadOBJ(char *_path)
{
	/* For .obj format spec., see http://en.wikipedia.org/wiki/Wavefront_.obj_file */
	char			type;
	bool			vert = true;
	ifstream		file ( _path, ifstream::in );
	
	/* Clearing the mesh. */
	this->clear();
	
	/* If the file is not opened and attached to the file stream.
	   Print an error message and return -1.
	*/
	if ( ! file.is_open() )
	{
		cout<<"Error while opening the file \""<<_path<<"\""<<endl;
		cout<<"Method Mesh::loadOBJ is returning -1, check it if you didn't"<<endl;
		return -1;
	}
	
	/* Reading the first character of the file. */
	file >> type;
	/* If the character read is a 'v' then we have to red a vertex list. */
	vert = ( type == 'v' );
	
	/* A 'v' character has been read, we are going to read the vertex list. */
	while ( file.good() && vert == true )
	{
		/* Allocate three variable to get the space coordinates of the vertex. */
		float x, y, z;
		
		/* Processing the vertex line : we read the 3 components of the vertex location and then add the mesh a pointer to the vertex created from these coordinates. */
		file >> x;
		file >> y;
		file >> z;
		this->addVertex( new Vertex( this->getNVerts(), Vector3D( x, y, z ) ) );
		
		/* Read another character and check for its value ('v' or not ) in order to stop (or not) the loop. */
		file >> type;
		vert = ( type == 'v' );
	}
		
	/* Once the vertices list has been read, we have to read the face list. */
	while ( file.good() )
	{
		/* Declaring a new face. */
		Face*			f = new Face( this->getNFaces() );
		char			faceList[255];
		int				index = -5;
		
		/* Reading the entire line to get the index of the vertices componing the face. */
		file.getline( faceList, 255 );
		
		/* Allocate variables to store the first indexe of the face row and two to read the index of the tail and head vertex of each edge of the face. */
		int first;
		int iTail, iHead;
		
		/* The last line is not to read, it only contains "\n" so that faceList only contains a empty string. */
		if ( strcmp( "", faceList ) != 0 )
		{
			/* Declaring an istrinstream to read the line word per word. */
			istringstream	iss ( faceList, istringstream::in );
			/* Ignore the first word of the line which should be 'f'. */
			iss.ignore(255,' ');
						
			/* Reading the first edge of the face. */
			iss >> first;
			iss >> iHead;
			iTail = first;
			
			/* We read the line word per word. */
			while ( iss.good() )
			{
				iTail -= 1;
				iHead -= 1;
				/* So that the index goes from 0. */
				
				index = this->getIVert( iTail )->containsEdge( iTail, iHead );
				if ( index == -1 )
				{
					/* If the iTail vertex does not have the edge [iTail, iHead] yet, we have to create the edge and its twin */
					Edge* e = new Edge ( this->getNEdges(), this->getIVert( iTail ), this->getIVert( iHead) );
					Edge* eTwin = new Edge ( this->getNEdges()+1, this->getIVert( iHead ), this->getIVert( iTail ) );
					
					e->setTwin( eTwin );
					eTwin->setTwin( e );
					
					e->addFace( f );
					f->addEdge( e );
					
					this->addEdge( e );
					this->addEdge( eTwin );
					
					this->addEdgeToIVertex( iTail, e );
					this->addEdgeToIVertex( iHead, eTwin );
				}
				
				else
				{
					/* The edge already exists, we just have to add it to the face and to add the face to the edge */
					f->addEdge( this->getIEdge( index ) );
					this->addFaceToIEdge( index, f );
				}
				
				iTail = iHead;
				iss >> iHead;
			}
			
			/* Now checking the [iTail, iHead] edge which is not taken in acount by the while loop. */
			iHead -= 1;
			
			index = this->getIVert( iTail )->containsEdge( iTail, iHead );
			if ( index == -1 )
			{
				Edge* e = new Edge ( this->getNEdges(), this->getIVert( iTail ), this->getIVert( iHead) );
				Edge* eTwin = new Edge ( this->getNEdges()+1, this->getIVert( iHead ), this->getIVert( iTail ) );
				
				e->setTwin( eTwin );
				eTwin->setTwin( e );
				
				e->addFace( f );
				f->addEdge( e );
				
				this->addEdge( e );
				this->addEdge( eTwin );
				
				this->addEdgeToIVertex( iTail, e );
				this->addEdgeToIVertex( iHead, eTwin );
			}
			
			else
			{
				f->addEdge( this->getIEdge( index ) );
				this->addFaceToIEdge( index, f );
			}
			
			/* Now checking the [last, first] edge of the face. */
			iTail = iHead;
			iHead = first-1;
						
			index = this->getIVert( iTail )->containsEdge( iTail, iHead );
			if ( index == -1 )
			{
				Edge* e = new Edge ( this->getNEdges(), this->getIVert( iTail ), this->getIVert( iHead) );
				Edge* eTwin = new Edge ( this->getNEdges()+1, this->getIVert( iHead ), this->getIVert( iTail ) );
				
				e->setTwin( eTwin );
				eTwin->setTwin( e );
				
				e->addFace( f );
				f->addEdge( e );
				
				this->addEdge( e );
				this->addEdge( eTwin );
				
				this->addEdgeToIVertex( iTail, e );
				this->addEdgeToIVertex( iHead, eTwin );
			}
			
			else
			{
				f->addEdge( this->getIEdge( index ) );
				this->addFaceToIEdge( index, f );
			}
			
			/* We finally add the face created to the mesh */
			this->addFace( f );
		}
	}
	
	file.close();
	
	return 1;
}

void Mesh::computeNormals()
{
	for ( int i = 0 ; i < nFaces ; i++ )
	{
		/* For each face of the mesh, the normal will be the orthogonal vector to the face.
		   i.e. the cross product of two different edges of the face.
		   We then normalize the normal of the face.
		   
		   The implementation could be done in another way, maybe faster, but this way, the code is simple and there is no encapsulation violation.
		*/
		Vector3D normal = tools_crossProduct( faces[i]->getEdges()[0]->toVector(), faces[i]->getEdges()[1]->toVector() );
		normal.normalize();
		faces[i]->setNormal ( normal );
	}
	
	for ( int i = 0 ; i < nVerts ; i++ )
	{
		/* For each vertex of the mesh, its normal will be the mean of the normal of the faces the vertex belongs.
		   We then normalize the normal.
		*/
		Vector3D normal ( 0, 0, 0 );
		int nbFaces = 0;
		
		/* We cover all the edges that goes from this vertex. */ 
		for ( int j = 0 ; j < (int)verts[i]->getEdges().size() ; j++ )
		{
			/* In order to cover all the faces which contain this vertex. */
			for ( int k = 0 ; k < (int)verts[i]->getEdges()[j]->getFaces().size() ; k++ )
			{
				normal += verts[i]->getEdges()[j]->getFaces()[k]->getNormal();
				nbFaces++;
			}
		}
		
		normal /= nbFaces;
		normal.normalize();
		verts[i]->setNormal ( normal );
	}
}

void Mesh::normalize()
{
	/* Top and bot will be set to the top and bottom of the mesh bounding box. */
	Vector3D top( INT_MIN, INT_MIN, INT_MIN );
	Vector3D bot( INT_MAX, INT_MAX, INT_MAX );
	float	scaleCoeff = 0;
	
	for ( int i = 0 ; i < nVerts ; i++ )
	{
		if ( verts[i]->getPos().getX() < bot.getX() )
			bot.setX( verts[i]->getPos().getX() );
		
		if ( verts[i]->getPos().getY() < bot.getY() )
			bot.setY( verts[i]->getPos().getY() );
		
		if ( verts[i]->getPos().getZ() < bot.getZ() )
			bot.setZ( verts[i]->getPos().getZ() );
		
		if ( verts[i]->getPos().getX() > top.getX() )
			top.setX( verts[i]->getPos().getX() );
		
		if ( verts[i]->getPos().getY() > top.getY() )
			top.setY( verts[i]->getPos().getY() );
		
		if ( verts[i]->getPos().getZ() > top.getZ() )
			top.setZ( verts[i]->getPos().getZ() );
	}
	
	Vector3D diff = top - bot;
	
	if ( diff.getX() > diff.getY() && diff.getX() > diff.getZ() )
	{
		/* The Ox axe is the biggest direction of the mesh. */
		scaleCoeff = diff.getX();
	}
	
	else if ( diff.getY() > diff.getX() && diff.getY() > diff.getZ() )
	{
		/* The Oy axe is the biggest direction of the mesh. */
		scaleCoeff = diff.getY();
	}
	
	else if ( diff.getZ() > diff.getY() && diff.getZ() > diff.getX() )
	{
		/* The Oz axe is the biggest direction of the mesh. */
		scaleCoeff = diff.getZ();
	}
	
	/* Now we apply the scale to every vertex of the mesh. */
	for ( int i = 0 ; i < nVerts ; i++ )
	{
		verts[i]->setPos( verts[i]->getPos() /= scaleCoeff );
	}
}

int Mesh::colorFromMap(Map _m)
{
	if ( _m.getSize() != nVerts )
	{
		cout<<"Mesh and map don't have te same number of elements : Nelts in map = "<<_m.getSize()<<" and Nelts in mesh "<<nVerts<<endl;
		cout<<"Matching aborted. Method Mesh::colorFromMap returning -1."<<endl;
		return -1;
	}
	
	/* The map has values between min and max, we want to attribute each value another one between -(7*pi/4) and 0.
	   a & b will contain the coefficient of the linear interpolation from [min, max] to [-(7*pi/4), 0].
	 */
	double a = -( (7*M_PI_4) / ( _m.getMax() - _m.getMin() ));
	double b = -( a * _m.getMax() );
	
	/* Setting the color for each vertex of the mesh according to the map. */
	for ( int i = 0 ; i < nVerts ; i++ )
	{
		verts[i]->setColor( tools_colorFromValue( RADIANS, _m.getIData(i) * a + b ) );
	}
	
	return 1;
}

void Mesh::printInfos()
{
	cout<<"Mesh Informations :"<<endl;
	cout<<"___________________"<<endl;
	cout<<"Nb vertices = "<<nVerts<<endl;
	cout<<"Nb edges    = "<<nEdges<<endl;
	cout<<"Nb faces    = "<<nFaces<<endl;
}

void Mesh::displayIVertex( int _i, float _r, float _g, float _b)
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_POINTS );
		glNormal3dv ( verts[_i]->getNormalArray() );
		glVertex3dv ( verts[_i]->getPosArray() );
	glEnd();
}

void Mesh::displayIVertex( int _i )
{
	glColor3dv( verts[_i]->getColorArray() );
	glBegin ( GL_POINTS );
		glNormal3dv ( verts[_i]->getNormalArray() );
		glVertex3dv ( verts[_i]->getPosArray() );
	glEnd();
}

void Mesh::displayVertices(float _r, float _g, float _b)
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_POINTS );
	for ( int i = 0 ; i < nVerts ; i++ )
	{
		glNormal3dv ( verts[i]->getNormalArray() );
		glVertex3dv ( verts[i]->getPosArray() );
	}
	glEnd();
}

void Mesh::displayVertices()
{
	glBegin ( GL_POINTS );
	for ( int i = 0 ; i < nVerts ; i++ )
	{
		glColor3dv ( verts[i]->getColorArray() );
		glNormal3dv ( verts[i]->getNormalArray() );
		glVertex3dv ( verts[i]->getPosArray() );
	}
	glEnd();
}

void Mesh::displayIEdge(int _i, float _r, float _g, float _b)
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_LINES );
		glNormal3dv ( edges[_i]->getTail()->getNormalArray() );
		glVertex3dv ( edges[_i]->getTail()->getPosArray() );
		
		glNormal3dv ( edges[_i]->getHead()->getNormalArray() );
		glVertex3dv ( edges[_i]->getHead()->getPosArray() );
	glEnd();
}

void Mesh::displayIEdge(int _i )
{
	glBegin ( GL_LINES );
		glColor3dv ( edges[_i]->getTail()->getColorArray() );
		glNormal3dv ( edges[_i]->getTail()->getNormalArray() );
		glVertex3dv ( edges[_i]->getTail()->getPosArray() );
		
		glColor3dv ( edges[_i]->getHead()->getColorArray() );
		glNormal3dv ( edges[_i]->getHead()->getNormalArray() );
		glVertex3dv ( edges[_i]->getHead()->getPosArray() );
	glEnd();
}

void Mesh::displayEdges(float _r, float _g, float _b)
{
	glColor3f( _r, _g, _b );
	glBegin ( GL_LINES );
	for ( int i = 0 ; i < nEdges ; i++ )
	{
		glNormal3dv ( edges[i]->getTail()->getNormalArray() );
		glVertex3dv ( edges[i]->getTail()->getPosArray() );
		
		glNormal3dv ( edges[i]->getHead()->getNormalArray() );
		glVertex3dv ( edges[i]->getHead()->getPosArray() );
	}
	glEnd();
}

void Mesh::displayEdges()
{
	glBegin ( GL_LINES );
	for ( int i = 0 ; i < nEdges ; i++ )
	{
		glColor3dv ( edges[i]->getTail()->getColorArray() );
		glNormal3dv ( edges[i]->getTail()->getNormalArray() );
		glVertex3dv ( edges[i]->getTail()->getPosArray() );
		
		glColor3dv ( edges[i]->getHead()->getColorArray() );
		glNormal3dv ( edges[i]->getHead()->getNormalArray() );
		glVertex3dv ( edges[i]->getHead()->getPosArray() );
	}
	glEnd();
}

void Mesh::displayIFace(int _i, float _r, float _g, float _b)
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_POLYGON );
	for ( int i = 0 ; i < (int)faces[_i]->getEdges().size() ; i++ )
	{	
		glNormal3dv ( faces[_i]->getNormalArray() );
		glVertex3dv ( faces[_i]->getEdges()[i]->getHead()->getPosArray() );
	}
	glEnd();
}

void Mesh::displayIFace(int _i )
{
	glBegin ( GL_POLYGON );
	for ( int i = 0 ; i < (int)faces[_i]->getEdges().size() ; i++ )
	{	
		glColor3dv ( faces[_i]->getEdges()[i]->getHead()->getColorArray() );
		glNormal3dv ( faces[_i]->getNormalArray() );
		glVertex3dv ( faces[_i]->getEdges()[i]->getHead()->getPosArray() );
	}
	glEnd();
}

void Mesh::displayIFaceSmooth(int _i, float _r, float _g, float _b)
{
	glColor3f ( _r, _g, _b );
	glBegin ( GL_POLYGON );
	for ( int i = 0 ; i < (int)faces[_i]->getEdges().size() ; i++ )
	{	
		glNormal3dv ( faces[_i]->getEdges()[i]->getHead()->getNormalArray() );
		glVertex3dv ( faces[_i]->getEdges()[i]->getHead()->getPosArray() );
	}
	glEnd();
}

void Mesh::displayIFaceSmooth(int _i)
{
	glBegin ( GL_POLYGON );
	for ( int i = 0 ; i < (int)faces[_i]->getEdges().size() ; i++ )
	{	
		glColor3dv ( faces[_i]->getEdges()[i]->getHead()->getColorArray() );
		glNormal3dv ( faces[_i]->getEdges()[i]->getHead()->getNormalArray() );
		glVertex3dv ( faces[_i]->getEdges()[i]->getHead()->getPosArray() );
	}
	glEnd();
}

void Mesh::displayFaces(float _r, float _g, float _b)
{
	for ( int i = 0 ; i < nFaces ; i++ )
	{
		this->displayIFace( i, _r, _g, _b );
	}
}

void Mesh::displayFaces()
{
	for ( int i = 0 ; i < nFaces ; i++ )
	{
		this->displayIFace( i );
	}
}

void Mesh::displayFacesSmooth(float _r, float _g, float _b)
{
	for ( int i = 0 ; i < nFaces ; i++ )
	{
		this->displayIFaceSmooth( i, _r, _g, _b );
	}
}

void Mesh::displayFacesSmooth()
{
	for ( int i = 0 ; i < nFaces ; i++ )
	{
		this->displayIFaceSmooth( i );
	}
}

void Mesh::display(int _mode, float _r, float _g, float _b)
{
	switch ( _mode )
	{
		case VERTICES :
			this->displayVertices( _r, _g, _b );
			break;
			
		case EDGES :
			this->displayEdges( _r, _g, _b );
			break;
	
		case FACES :
			this->displayFaces( _r, _g, _b );
			break;
		
		case SMOOTH :
			this->displayFacesSmooth( _r, _g, _b );
			break;
			
		default :
			break;
	}
}

void Mesh::display(int _mode )
{
	switch ( _mode )
	{
		case VERTICES :
			this->displayVertices();
			break;
			
		case EDGES :
			this->displayEdges();
			break;
	
		case FACES :
			this->displayFaces();
			break;
		
		case SMOOTH :
			this->displayFacesSmooth();
			break;
			
		default :
			break;
	}
}
