#include "IStreamable.h"
#include <exception>

const std::exception notRegistered( "The class identificator is not registered in the map" );
const std::exception callingPureVirtual( "Calling a pure virtual method of an abstract class ISerializable" );

static std::map<std::string, IStreamable*> classIdToClass;

IStreamable::IStreamable()
{}

void IStreamable::registerClass()
{
	m_classId = getClassName();
	auto search = classIdToClass.find( m_classId );
	if ( search == classIdToClass.end() )
	{
		classIdToClass[m_classId] = nullptr; //TODO
		classIdToClass[m_classId] = this->createDummy();
	}
}

void IStreamable::serialize( std::ostream& outStream ) const
{
	outStream << " " << m_classId;
}

IStreamable* IStreamable::unserialize( std::istream& inStream ) const
{
	std::string classId;
	inStream >> classId;
	auto search = classIdToClass.find( classId );
	if ( search == classIdToClass.end() )
		throw notRegistered;
	IStreamable* result = search->second->createDummy();
	result->readState( inStream );
	return result;
}

IStreamable* IStreamable::createDummy() const
{
	throw callingPureVirtual;
}

std::string IStreamable::getClassName() const
{
	throw callingPureVirtual;
}
