#include "Square.h"

REGISTER_TYPE( Square )

Square::Square( const ShapePos2D& centroid, const shape_t& radius ) 
	: RegularPolygon( centroid, radius, 4 ) 
{}

Square::Square()
	: Square( ShapePos2D( 0, 0 ), 1 )
{}

void Square::serialize( std::ostream& outStream ) const
{
	RegularPolygon::serialize( outStream );
}

void Square::readState( std::istream& inStream )
{
	RegularPolygon::readState( inStream );
}