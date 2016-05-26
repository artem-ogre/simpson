#include "EquilateralTriangle.h"

REGISTER_TYPE( EquilateralTriangle )

EquilateralTriangle::EquilateralTriangle( const ShapePos2D& centroid, const shape_t& radius ) 
	: RegularPolygon( centroid, radius, 3 ) 
{}
EquilateralTriangle::EquilateralTriangle() 
	: EquilateralTriangle( ShapePos2D( 0, 0 ), 1 )
{}

void EquilateralTriangle::serialize( std::ostream& outStream ) const
{
	RegularPolygon::serialize( outStream );
}

void EquilateralTriangle::readState( std::istream& inStream )
{
	RegularPolygon::readState( inStream );
}