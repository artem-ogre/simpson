#include "Streamable.h"
#include <exception>

const std::exception notRegistered( "The class identificator is not registered in the map" );
const std::exception alreadyRegistered( "The class identificator is already registered in the map" );

using FactoryMap = std::map<std::string, IStreamableFactory*>;
FactoryMap& factoryMap() //avoiding an initialization order fiasco using 'Construct On First Use' idiom
{
	static FactoryMap factories;
	return factories;
}

void Streamable::registerType( const std::string& name, IStreamableFactory* factory )
{
	auto search = factoryMap().find( name );
	if ( search != factoryMap().end() )
		throw alreadyRegistered;
	factoryMap()[name] = factory;
}

void Streamable::serialize( std::ostream& outStream, const Streamable* obj )
{
	outStream << " " << obj->getClassName();
	obj->writeState( outStream );
}

std::unique_ptr<Streamable> Streamable::unserialize( std::istream& inStream )
{
	std::string classId;
	inStream >> classId;
	auto search = factoryMap().find( classId );
	if ( search == factoryMap().end() )
		throw notRegistered;
	auto result = search->second->create();
	result->readState( inStream );
	return result;
}

std::ostream& operator<<( std::ostream& outStream, const Streamable& obj )
{
	Streamable::serialize( outStream, &obj );
	return outStream;
}

std::istream& operator>>( std::istream& inStream, const Streamable& obj )
{
	Streamable::unserialize( inStream );
	return inStream;
}
