#include<iostream>
#include<sstream>
#include <type_traits>

#include "Shape.h"
#include "Circle.h"
#include "RegularPolygon.h"
#include "EquilateralTriangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "IStreamable.h"

static_assert(std::is_arithmetic<shape_t>::value, "shape_t  is not arithmetic");
static_assert(std::is_floating_point<shape_t>::value, "shape_t  is not floating point");

int main( int argc, char *argv[] )
{
	try
	{
		//Shape s;
		Circle c( ShapePos2D( 1.2, 2.3 ), 123.0 );
		//RegularPolygon rp( Coord2D( 0.0, 0.0 ), 1.0, 0 ); //testing zero sides
		RegularPolygon rp( ShapePos2D( 0.0, 0.0 ), 1.0, 3 );
		//rp.setNSides( 0 ); //testing zero sides
		EquilateralTriangle t( ShapePos2D( 0.0, 0.0 ), 1.0 );
		Square sq( ShapePos2D( 0.0, 0.0 ), 1.0 );
		//Rectangle rec( ShapePos2D( 0.0, 0.0 ), -1, 1 );
		Rectangle rec( ShapePos2D( 0.0, 0.0 ), 1, 1 );

		Shape * shapes[2];
		shapes[0] = &c;
		shapes[1] = &rec;
		std::stringstream buffer;
		for ( size_t i = 0; i < 2; ++i )
		{
			shapes[i]->serialize( buffer );
			shapes[i]->serialize( std::cout );
		}
		for ( size_t i = 0; i < 2; ++i )
			shapes[i]->unserialize( buffer );
	}
	catch ( std::exception &e ) 
	{
		std::cout << "Caught exception: " << e.what() << "\n";
		return 1;
	}
	return 0;
}