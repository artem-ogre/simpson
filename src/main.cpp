#include<iostream>
#include "Shape.h"
#include "Circle.h"
#include "RegularPolygon.h"
#include "EquilateralTriangle.h"
#include "Square.h"

int main( int argc, char *argv[] )
{
	try
	{
		//Shape s;
		Circle c;
		//RegularPolygon rp( Coord2D( 0.0, 0.0 ), 1.0, 0 ); //testing zero sides
		RegularPolygon rp( Coord2D( 0.0, 0.0 ), 1.0, 1 ); 
		//rp.setNSides( 0 ); //testing zero sides
		EquilateralTriangle t( Coord2D( 0.0, 0.0 ), 1.0 );
		Square sq( Coord2D( 0.0, 0.0 ), 1.0 );
	}
	catch ( std::exception &e ) 
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}
	std::cout << "Hello World!" << std::endl;
	return 0;
}