#include "IStreamable.h"
#include <exception>

const std::exception notRegistered( "The class identificator is not registered in the map" );
const std::exception alreadyRegistered( "The class identificator is already registered in the map" );

typedef std::map<std::string, IStreamableFactory*> FactoryMap;
FactoryMap& factoryMap()//avoiding an initialization order fiasco
{
	static FactoryMap factories;
	return factories;
}

IStreamable::IStreamable()
{}

void IStreamable::registerType( const std::string& name, IStreamableFactory* factory )
{
	auto search = factoryMap().find( name );
	if ( search != factoryMap().end() )
		throw alreadyRegistered;
	factoryMap()[name] = factory;
}

void IStreamable::serialize( std::ostream& outStream, const IStreamable* obj )
{
	outStream << " " << obj->getClassName();
	obj->writeState( outStream );
}

IStreamable* IStreamable::unserialize( std::istream& inStream )
{
	std::string classId;
	inStream >> classId;
	auto search = factoryMap().find( classId );
	if ( search == factoryMap().end() )
		throw notRegistered;
	IStreamable* result = search->second->create();
	result->readState( inStream );
	return result;
}

std::ostream& operator<<( std::ostream& outStream, const IStreamable& obj )
{
	IStreamable::serialize( outStream, &obj );
	return outStream;
}

std::istream& operator>>( std::istream& inStream, const IStreamable& obj )
{
	IStreamable::unserialize( inStream );
	return inStream;
}
