#ifndef VECTOR3D_H
#define VECTOR3D_H

/**
 * \file	vector3d.h
 * \brief	Declaration de la classe Vector3D. Cette classe representera des points dans l'espace aussi bien que des vecteurs (deplacements, normales, ...).
 */

class Vector3D
{
	/*!
	 * \class Vector3D
	 * \brief Classe représentant un Vecteur en 3 dimensions.
	 * 
	 * Un vecteur en trois dimension est represente par un triplet de double.
	 * Une telle classe peut representer un point de l'espace, un vecteur mathematique de 3 dimensions, une couleur sous forme rgb ou tls...
	 *
	 */
	
private :
	double x;			/*! <X component of the vector.*/
	double y;			/*! <Y component of the vector.*/
	double z;			/*! <Z component of the vector.*/

public:
	/*!
	*  \brief Default constructor of the Vector3D class.
	*
	*  Default constructor of the Vector3D class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
	*/
    Vector3D();
	
	/*!
	*  \brief Overload constructor of the Vector3D class.
	*
	*  Overload constructor of the Vector3D class.
	*/
    Vector3D( double _x, double _y, double _z );
	
	/*!
	*  \brief Copy constructor of the Vector3D class.
	*
	*  Copy constructor of the Vector3D class.
	*/
    Vector3D( const Vector3D& _v );
	
	/*!
	*  \brief Destructor of the Vector3D class.
	*
	*  Destructor of the Vector3D class.
	*/
	~Vector3D();
	
	/*!
	*  \brief Affectation operator of the Vector3D class.
	*
	*  Affectation operator of the Vector3D class.
	*/
	Vector3D& operator= ( const Vector3D& _v );
	
	/*!
	*  \brief Addition operator of the Vector3D class.
	*
	*  Addition operator of the Vector3D class.
	*/
	Vector3D operator+ ( const double& _a );
	
	/*!
	*  \brief Addition operator of the Vector3D class.
	*
	*  Addition operator of the Vector3D class.
	*/
	Vector3D operator+ ( const Vector3D& _v );
	
	/*!
	*  \brief Self addition operator of the Vector3D class.
	*
	*  Self addition operator of the Vector3D class.
	*/
	Vector3D operator+= ( const double& _a );
	
	/*!
	*  \brief Self addition operator of the Vector3D class.
	*
	*  Self addition operator of the Vector3D class.
	*/
	Vector3D operator+= ( const Vector3D& _v );
	
	/*!
	*  \brief Substraction operator of the Vector3D class.
	*
	*  Substraction operator of the Vector3D class.
	*/
	Vector3D operator- ( const double& _a );
	
	/*!
	*  \brief Substraction operator of the Vector3D class.
	*
	*  Substraction operator of the Vector3D class.
	*/
	Vector3D operator- ( const Vector3D& _v );
	
	/*!
	*  \brief Self substraction operator of the Vector3D class.
	*
	*  Self substraction operator of the Vector3D class.
	*/
	Vector3D operator-= ( const double& _a );
	
	/*!
	*  \brief Self substraction operator of the Vector3D class.
	*
	*  Self substraction operator of the Vector3D class.
	*/
	Vector3D operator-= ( const Vector3D& _v );
	
	/*!
	*  \brief Multiplication operator of the Vector3D class.
	*
	*  Multiplication operator of the Vector3D class.
	*/
	Vector3D operator* ( const Vector3D& _v );
	
	/*!
	*  \brief Multiplication operator of the Vector3D class.
	*
	*  Multiplication operator of the Vector3D class.
	*/
	Vector3D operator* ( const double& _a );
	
	/*!
	*  \brief Self multiplication operator of the Vector3D class.
	*
	*  Self multiplication operator of the Vector3D class.
	*/
	Vector3D operator*= ( const Vector3D& _v );
	
	/*!
	*  \brief Self multiplication operator of the Vector3D class.
	*
	*  Self multiplication operator of the Vector3D class.
	*/
	Vector3D operator*= ( const double& _a );
	
	/*!
	*  \brief Self division operator of the Vector3D class.
	*
	*  Self division operator of the Vector3D class.
	*/
	Vector3D operator/= ( const double& _a );
	
	/*!
	*  \brief Self division operator of the Vector3D class.
	*
	*  Self division operator of the Vector3D class.
	*/
	Vector3D operator/= ( const Vector3D& _v );
	
	/*!
	*  \brief Division operator of the Vector3D class.
	*
	*  Division operator of the Vector3D class.
	*/
	Vector3D operator/ ( const double& _a );
	
	/*!
	*  \brief Division operator of the Vector3D class.
	*
	*  Division operator of the Vector3D class.
	*/
	Vector3D operator/ ( const Vector3D& _v );
	
	/*!
	*  \brief Getter of the Vector3D class.
	*
	*  Getter of the Vector3D class.
	*
	*  \return (double) returns the X component of the vector.
	*/
	double getX();
	
	/*!
	*  \brief Getter of the Vector3D class.
	*
	*  Getter of the Vector3D class.
	*
	*  \return (double) returns the Y component of the vector.
	*/
	double getY();
	
	/*!
	*  \brief Getter of the Vector3D class.
	*
	*  Getter of the Vector3D class.
	*
	*  \return (double) returns the Z component of the vector.
	*/
	double getZ();
	
	/*!
	*  \brief Getter of the Vector3D class.
	*
	*  Getter of the Vector3D class.
	*  This one is a little special while it is implemented to get all the vector data into one array.
	*  This might be usefull for some further usages ( as with the glColor3dv func for example ).
	*
	*  \return (double*) returns an array of double containing the Vector3D informations.
	*/
	double* getArray ();
	
	/*!
	*  \brief Setter of the Vector3D class.
	*
	*  Setter of the Vector3D class.
	*
	*  \param _x : value to affect to the x attribute of the vector.
	*
	*  \return (void)
	*/
	void setX	( double _x );
	
	/*!
	*  \brief Setter of the Vector3D class.
	*
	*  Setter of the Vector3D class.
	*
	*  \param _y : value to affect to the y attribute of the vector.
	*
	*  \return (void)
	*/
	void setY	( double _y );
	
	/*!
	*  \brief Setter of the Vector3D class.
	*
	*  Setter of the Vector3D class.
	*
	*  \param _z : value to affect to the z attribute of the vector.
	*
	*  \return (void)
	*/
	void setZ	( double _z );
	
	/*!
	*  \brief Setter of the Vector3D class.
	*
	*  Setter of the Vector3D class : sets all attributes of the vector.
	*
	*  \param _x : value to affect to the x attribute of the vector.
	*  \param _y : value to affect to the y attribute of the vector.
	*  \param _z : value to affect to the z attribute of the vector.
	*
	*  \return (void)
	*/
	void set	( double _x, double _y, double _z );
	
	/*!
	*  \brief Normalize a 3D vector.
	*
	*  Normalize a 3D vector.
	*
	*  \return (void)
	*/
	void normalize ();
	
	/*!
	*  \brief Prints the Vector3D in the terminal output.
	*
	*  Printf the Vector3D as follow : "[ x, y, z ]\n".
	*
	*  \return (void)
	*/
	void print ();
};

#endif
