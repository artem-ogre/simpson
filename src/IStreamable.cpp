#include "IStreamable.h"
#include <exception>

const std::exception notRegistered( "The class identificator is not registered in the map" );
const std::exception callingPureVirtual( "Calling a pure virtual method of an abstract class ISerializable" );

typedef std::map<std::string, IStreamableFactory*> FactoryMap;
FactoryMap& factoryMap() //avoiding initialization order fiasco
{
	static FactoryMap factories;
	return factories;
}

IStreamable::IStreamable()
{}

void IStreamable::registerClass( const std::string& name, IStreamableFactory* factory )
{
	factoryMap()[name] = factory;
}

void IStreamable::serialize( std::ostream& outStream ) const
{
	outStream << " " << getClassName();
}

IStreamable* IStreamable::unserialize( std::istream& inStream ) const
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

std::string IStreamable::getClassName() const
{
	throw callingPureVirtual;
}
