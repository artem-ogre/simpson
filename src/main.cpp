#include <iostream>
#include <sstream>
#include <type_traits>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h> 

#include "Shape.h"
#include "Circle.h"
#include "RegularPolygon.h"
#include "EquilateralTriangle.h"
#include "Square.h"
#include "Rectangle.h"

static_assert(std::is_arithmetic<shape_t>::value, "shape_t  is not arithmetic");
static_assert(std::is_floating_point<shape_t>::value, "shape_t  is not floating point");

int main( int argc, char *argv[] )
{
	if( argc == 2 )
	{
		std::vector<IStreamable*> shapes;
		srand( (unsigned int)time( NULL ) );
		for(int i = 0; i < 100; i++)
		{
			switch( rand() % 5 )
			{
			case 0:
			{
				Circle* c = new Circle( ShapePos2D( rand(), rand() ), rand() );
				shapes.push_back( c );
				break;
			}
			case 1:
			{
				RegularPolygon* rp = new RegularPolygon( ShapePos2D( rand(), rand() ), rand(), rand() );
				shapes.push_back( rp );
				break;
			}
			case 2:
			{
				EquilateralTriangle* t = new EquilateralTriangle( ShapePos2D( rand(), rand() ), rand() );
				shapes.push_back( t );
				break;
			}
			case 3:
			{
				Square* c = new Square( ShapePos2D( rand(), rand() ), rand() );
				shapes.push_back( c );
				break;
			}
			}
		}
		
		std::ofstream outFile( argv[1] );
		for ( size_t i = 0; i < shapes.size(); ++i )
		{
			if ( i > 0 )
				outFile << "\n";
			outFile << *shapes[i];
			delete shapes[i];
		}
		outFile.close();
	}
	else if( argc == 3 )
	{
		// loading shapes
		std::vector<IStreamable*> shapes;
		std::ifstream inFile( argv[1] );
		if( !inFile.is_open() )
		{
			std::cout << "can't open the input file\n";
			return 1;
		}
		while( !inFile.eof() )
			shapes.push_back( IStreamable::unserialize( inFile ) );
		inFile.close();

		// saving shapes
		std::ofstream outFile( argv[2] );
		if ( !outFile.is_open() )
		{
			std::cout << "can't open the output file\n";
			return 1;
		}
		for ( size_t i = 0; i < shapes.size(); ++i )
		{
			if ( i > 0 )
				outFile << "\n";
			outFile << *shapes[i];
			delete shapes[i];
		}
		outFile.close();
	}

	return 0;
}