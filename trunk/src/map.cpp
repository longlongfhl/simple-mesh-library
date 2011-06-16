#include "../inc/map.h"
#include <iostream>
#include <limits>
#include <fstream>

Map::Map()
{
	min = 0;
	max = 0;
	data.clear();
}

Map::Map(const Map &_m)
{
	min = _m.min;
	max = _m.max;
	data.clear();
	data = _m.data;
}

Map::~Map()
{
	data.clear();
}

Map& Map::operator = ( const Map& _m )
{
	min = _m.min;
	max = _m.max;
	data.clear();
	data = _m.data;
	
	return *this;
}

double Map::getMin()
{
	return min;
}

double Map::getMax()
{
	return max;
}

vector<double> Map::getData()
{
	return data;
}

double Map::getIData(int _i)
{
	return data[_i];
}

int Map::getSize()
{
	return (int)data.size() - 1;
}

void Map::setMin(double _min)
{
	min = _min;
}

void Map::setMax(double _max)
{
	max = _max;
}

void Map::setData(vector<double> _data)
{
	data = _data;
}

void Map::setIData(int _i, double _iData)
{
	data[_i] = _iData;
}

void Map::clear()
{
	min = 0;
	max = 0;
	data.clear();
}

void Map::expand(int _min, int _max)
{
	if ( _max < _min )
	{
		cout<<"Error while calling the Map::expand method : max value > min"<<endl;
		cout<<"expansion aborted"<<endl;
		return;
	}
	
	double a = 0, b = 0;
	
	a = ( _max - _min ) / ( max - min );
	b = _min - ( a * min );
	
	for ( int i = 0 ; i < (int)data.size() ; i++ )
	{
		data[i] = data[i] * a + b;
	}
	
	min = _min;
	max = _max;
}

int Map::load(char *_path)
{
	ifstream		file ( _path, ifstream::in );
	
	/* Testing if the file has been succesfully opened. */
	if ( ! file.is_open() )
	{
		cout<<"Error while opening the file \""<<_path<<"\""<<endl;
		cout<<"Method Map::load is returning -1, check it if you didn't"<<endl;
		return -1;
	}
	
	/* The map is cleared and min & max are initialized to find the real min & max. */
	this->clear();
	min = INT_MAX;
	max = INT_MIN;
	
	/* We read one feature after another until the end of the file. And change the min and max value if necessary. */
	while ( file.good() )
	{
		double		value = 0;
		
		file >> value;
		data.push_back( value );
		
		if ( value > max )
			max = value;
		
		if ( value < min )
			min = value;
	}
	
	/* Closing file. */
	file.close();
	
	/* Expanding the map between -50 and 50. */
	this->expand();
	
	return 1;
}

int Map::save(char *_path)
{
	ofstream		file ( _path );
	
	/* Testing if the file has been succesfully opened/created. */
	if ( ! file.is_open() )
	{
		cout<<"Error while opening the file \""<<_path<<"\""<<endl;
		cout<<"Method Map::save is returning -1, check it if you didn't"<<endl;
		return -1;
	}
	
	for ( int i = 0 ; i < (int)data.size() ; i++ )
		file<<data[i]<<endl;
	
	file.close();
	
	return 1;
}

void Map::segment(int _n)
{	
	/* Formula to get the class of the vertex. */
	for ( int i = 0 ; i < (int)data.size() ; i++ )
		data[i] = (int)( (data[i]-min) * ( (double)_n / (max - min)  ));

	/* The min and max have changed. */
	min = 0;
	max = _n;
	
	/* The map is expanded to set the values between -50 and 50 again. */
	expand();
}

void Map::printInfos()
{
	cout<<"Map Informations"<<endl;
	cout<<"________________"<<endl;
	cout<<"Minimum value : "<<min<<endl;
	cout<<"Maximum value : "<<max<<endl;
	cout<<"Number of elements : "<<data.size()<<endl;
}

void Map::printIData(int _i)
{
	cout<<_i<<"th element of the map : "<<data[_i]<<endl;
}

void Map::printData()
{
	cout<<"Entire Map :"<<endl;
	cout<<"____________"<<endl;
	
	for ( int i = 0 ; i < (int)data.size() ; i++ )
		this->printIData( i );
}
