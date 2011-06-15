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

#endif
