#include <iostream>
#include <sstream>
#include <type_traits>
#include <vector>

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
		EquilateralTriangle t( ShapePos2D( 0.4, 0.5 ), 2.6 );
		Square sq( ShapePos2D( 0.1, 0.2 ), 1.3 );
		//Rectangle rec( ShapePos2D( 0.0, 0.0 ), -1, 1 );
		Rectangle rec( ShapePos2D( 0.0, 0.0 ), 1, 1 );
		std::vector<IStreamable*> shapes;
		shapes.push_back(&c);
		shapes.push_back(&rec);
		shapes.push_back( &t );
		shapes.push_back( &sq );
		
		std::cout << "Before:\n";
		for ( auto s : shapes )
			std::cout << *s;
		
		std::stringstream buffer;
		for ( auto s : shapes )
			buffer << *s;
		for ( auto s : shapes )
			buffer >> *s;

		std::cout << "\nAfter:\n";
		for ( auto s : shapes )
			std::cout << *s;
	}
	catch ( std::exception &e ) 
	{
		std::cout << "Caught exception: " << e.what() << "\n";
		return 1;
	}
	return 0;
}