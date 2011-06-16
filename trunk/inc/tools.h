#ifndef TOOLS_H
#define TOOLS_H

/**
 * \file	tools.h
 * \brief	Definition d'otils geonetriques.
 *  
 *  Ce fichier ne contient que des fonctions non membres qu'il me semblait plus logique de construire comme tel 
 *  qu'en tant que methode d'une classe specifique.
 *  
 */

#include "vector3d.h"

using namespace std;

/*! \def GRADIANS
  mode : mode for computing a color from a value.
 */
#define RADIANS 0

/*! \def DEGREES
  mode : mode for computing a color from a value.
 */
#define DEGREES 1

/*!
*  \brief NON MEMBER FUNCTION : Computes the cross product of two 3D vectors.
*
*  Computes the cross product of two 3D vectors.
*  
*  \param _u : vector we want to compute the cross product with _v.
*  \param _v : vector we want to compute the cross product with _u.
*
*  \return (Vector3D) Returns the result of the cross product of the two vectors given in parameter.
*/
Vector3D tools_crossProduct ( Vector3D _u, Vector3D _v );

/*!
*  \brief NON MEMBER FUNCTION : Part of a pipeline of functions to convert a TLS color to a RGB one.
*
*  Part of a pipeline of functions to convert a TLS color to a RGB one.
*  The other parts of the process are the tools_couleursaturee and the tools_couleurfinale.
*  The whole process is given by the tools_TLStoRGB or the tools_colorFromValue functions.
*  
*  This function modify the rslt color by taking in account the T value of the TLS coded color..
*  
*  \param _tls : a color coded in a TLS format and stored in a Vector3D. This is the color to convert into RGB format.
*  \param _rgb : this will contain the result of the operation.
*  
*  \return (void)
*/
void	tools_couleurpure				( Vector3D tls, Vector3D& rgb );

/*!
*  \brief NON MEMBER FUNCTION : Part of a pipeline of functions to convert a TLS color to a RGB one.
*
*  Part of a pipeline of functions to convert a TLS color to a RGB one.
*  The other parts of the process are the tools_couleursaturee and the tools_couleurfinale.
*  The whole process is given by the tools_TLStoRGB or the tools_colorFromValue functions.
*  
*  This function modify the rslt color by taking in account the L value of the TLS coded color.
*  
*  \param _tls : a color coded in a TLS format and stored in a Vector3D. This is the color to convert into RGB format.
*  \param _rgb : this will contain the result of the operation.
*  
*  \return (void)
*/
void	tools_couleursaturee			( Vector3D tls, Vector3D& rgb );

/*!
*  \brief NON MEMBER FUNCTION : Part of a pipeline of functions to convert a TLS color to a RGB one.
*
*  Part of a pipeline of functions to convert a TLS color to a RGB one.
*  The other parts of the process are the tools_couleursaturee and the tools_couleurfinale.
*  The whole process is given by the tools_TLStoRGB or the tools_colorFromValue functions.
*  
*  This function modify the rslt color by taking in account the S value of the TLS coded color.
*  
*  \param _tls : a color coded in a TLS format and stored in a Vector3D. This is the color to convert into RGB format.
*  \param _rgb : this will contain the result of the operation.
*  
*  \return (void)
*/
void	tools_couleurfinale				( Vector3D tls, Vector3D& rgb );

/*!
*  \brief NON MEMBER FUNCTION : Convert a TLS color to a RGB one.
*
*  Convert a TLS color to a RGB one.
*  
*  \param _color : color coded in a Vector3D in a TLS format we want to convert into RGB format.
*  
*  \return (Vector3D) Returns the converted in RGB color.
*/
Vector3D tools_TLStoRGB					( Vector3D _color );

/*!
*  \brief NON MEMBER FUNCTION : Creates a color from a value.
*
*  Creates a color from a value :
*  The value is the angle given by the future color on the TLS circle.
*  (it represents the T value, while the L value is set to 0.5 and the S value is set to 1).
*  
*  \param _mode : mode of coding the value. Should be RADIANS or DEGREES
*  \param _value : angle to convert in a color.
*  
*  \return (Vector3D) Returns the color fathered by the value.
*/
Vector3D tools_colorFromValue			( int _mode, double _value );

#endif
