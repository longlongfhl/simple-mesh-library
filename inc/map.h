#ifndef MAP_H
#define MAP_H

/**
 * \file	map.h
 * \brief	Declaration de la classe Map representant une carte de feature (double) attachee a un maillage.
 */

#include <vector>

using namespace std;

class Map
{
	/*!
	 * \class Map
	 * \brief Classe représentant une carte de feature (double) attachee a un maillage.
	 * 
	 * Elle sera caracterisee par ses valeurs extreme et un tableau de donnees.
	 *
	 */
	
	private :
		double			min;					/*! <Value of the lowest feature of the map.*/
		double			max;					/*! <Value of the highest feature if the map.*/
		vector<double>	data;					/*! <Value of the feature for each vertex of the mesh t represents.*/
		
	public:
		/*!
		*  \brief Default constructor of the Map class.
		*
		*  Default constructor of the Map class : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*/
		Map();
		
		/*!
		*  \brief Copy constructor of the Map class.
		*
		*  Copy constructor of the Map class.
		*/
		Map( const Map& _m );
		
		/*!
		*  \brief Destructor of the Map class.
		*
		*  Destructor of the Map class.
		*/
		~Map();
		
		/*!
		*  \brief Affectation operator of the Map class.
		*
		*  Affectation operator of the Map class.
		*/
		Map& operator= ( const Map& _m );
		
		/*!
		*  \brief Getter of the Map class.
		*
		*  Getter of the Map class.
		*
		*  \return (double) returns the minimum value of the map.
		*/
		double getMin ();
		
		/*!
		*  \brief Getter of the Map class.
		*
		*  Getter of the Map class.
		*
		*  \return (double) returns the maximum value of the map.
		*/
		double getMax ();
		
		/*!
		*  \brief Getter of the Map class.
		*
		*  Getter of the Map class.
		*
		*  \return (vector<double>) returns an array of double containing every feature of the map.
		*/
		vector<double> getData ();
		
		/*!
		*  \brief Getter of the Map class.
		*
		*  Getter of the Map class.
		*
		*  \return (double) returns the value of the ith feature in the map.
		*/
		double getIData ( int _i );
		
		/*!
		*  \brief Getter of the Map class.
		*
		*  Getter of the Map class.
		*
		*  \return (int) returns the number of values in the data array.
		*/
		int getSize ();
		
		/*!
		*  \brief Setter of the Map class.
		*
		*  Setter of the Map class.
		*
		* \param _min : value to set as min of the map.
		*
		*  \return (void)
		*/
		void setMin ( double _min );
		
		/*!
		*  \brief Setter of the Map class.
		*
		*  Setter of the Map class.
		*
		* \param _max : value to set as max of the map.
		*
		*  \return (void)
		*/
		void setMax ( double _max );
		
		/*!
		*  \brief Setter of the Map class.
		*
		*  Setter of the Map class.
		*
		* \param _data : array of values to set as the data of the map.
		*
		*  \return (void)
		*/
		void setData ( vector<double> _data );
		
		/*!
		*  \brief Setter of the Map class.
		*
		*  Setter of the Map class.
		*
		* \param _i : index of the feature we want to set in the feature array of the map.
		* \param _iData : value to set to the ith feature of the map.
		*
		*  \return (void)
		*/
		void setIData ( int _i, double _iData );
		
		/*!
		*  \brief Clears a map.
		*
		*  Clears a map : Every attributes are initialized to 0 (int,float,double,...) NULL (pointers) or are cleared (lists, stacks, ...).
		*
		*  \return (void)
		*/
		void clear ();
		
		/*!
		*  \brief Dynamic expansion of the map to a new set of range.
		*
		*  Expands dynamically the map between two given values.
		*
		* \param _min : Lowest value we want for the new map. Set to -50 by default.
		* \param _max : Highest value we want for the new map. Set to 50 by default.
		*
		*  \return (void)
		*/
		void expand ( int _min, int _max );
		
		/*!
		*  \brief Loads a map from a file and expand it.
		*
		*  Loads a map from a file AND expand this map between -50 to 50.
		*  A map stored in a file is stored as follw :
		*  For each vertex of the mesh, one value is printed in the file.
		*  So, usually there is one value per line in the file but the end-line-caracter can be suppressed 
		*  and the values all printed in a single line.
		*  The map files should not content any comments.
		*
		* \param _path : path to the file where the map is stored.
		*
		*  \return (int) Returns 1 if the operation succeded, -1 else.
		*/
		int load ( char* _path );
		
		/*!
		*  \brief Saves a map into a file.
		*
		*  Saves a map into a given file.
		*
		* \param _path : path to the file where the map is going to be saved.
		*
		*  \return (int) Returns 1 if the operation succeded, -1 else.
		*/
		int save ( char* _path );
		
		/*!
		*  \brief Segments the map based on a value criteria.
		*
		*  Segments the map in n classes based on a value criteria :
		*  Each vertex value will be set to its class number.
		*  The class numbers are set according to the minimum and maximum value of the map 
		*  and also the number of class we want to create :
		*  If the map values range is [0, 100] and we want to create 10 classes,
		*  then the vertex which value is 34 will be set to 30
		*  and the vertex which value is 77 will be set to 70
		*
		* \param _n : number of classes we want to create in the map. Is set to 10 by default.
		*
		*  \return (void)
		*/
		void segment ( int _n );
		
		/*!
		*  \brief Prints some informations about the map in the terminal.
		*
		*  Prints some informations about the map in the terminal :
		*  The minimum and maximum value and also the number of elements in the map.
		*
		*  \return (void)
		*/
		void printInfos ();
		
		/*!
		*  \brief Prints the value of a particular element of the map.
		*
		*  Prints the value of the ith element of the map as follow :
		*  NumberOfElement : ValueOfElement
		*
		*  \param _i : index of the element we want to print out.
		*
		*  \return (void)
		*/
		void printIData ( int _i );
		
		/*!
		*  \brief Prints the value of each element of the map in the terminal.
		*
		*  Prints the value of each element of the map in the terminal as follow :
		*  NumberOfElement : ValueOfElement
		*
		*  \return (void)
		*/
		void printData ();	
};

#endif
