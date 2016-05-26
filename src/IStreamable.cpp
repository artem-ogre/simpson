#include "IStreamable.h"
#include <exception>

const std::exception alreadyRegistered( "The class identificator is already registered in the map" );
const std::exception notRegistered( "The class identificator is not registered in the map" );
const std::exception callingPureVirtual( "Calling a pure virtual method of an abstract class ISerializable" );

std::map<std::string, IStreamable*> IStreamable::m_classIdToClass;

IStreamable::IStreamable()
{}

void IStreamable::registerClass( const std::string& name, IStreamableFactory* factory )
{
	auto search = m_classIdToClass.find( name );
	if ( search != m_classIdToClass.end() )
		throw alreadyRegistered;
	m_classIdToClass[name] = factory->create();
}

void IStreamable::serialize( std::ostream& outStream ) const
{
	outStream << " " << getClassName();
}

IStreamable* IStreamable::unserialize( std::istream& inStream ) const
{
	std::string classId;
	inStream >> classId;
	auto search = m_classIdToClass.find( classId );
	if ( search == m_classIdToClass.end() )
		throw notRegistered;
	IStreamable* result = search->second->create();
	result->readState( inStream );
	return result;
}

IStreamable* IStreamable::create() const
{
	throw callingPureVirtual;
}

std::string IStreamable::getClassName() const
{
	throw callingPureVirtual;
}
