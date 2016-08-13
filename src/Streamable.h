#pragma once

#include "RegisterTypeMacro.h"
#include "IStreamableFactory.h"

#include <iostream>
#include <string>
#include <map>
#include <memory>

//!  Interface for the serializable type. 
/*!
Supports polymorphic serialization and unserialization to the stream and overloads streaming operators.
Serialization is using an abstract factory with named constructor idiom.
Classes implementing the interface need to override writeState and readState methods.
!Caller of IStreamable::unserialize is responsible for deleting it.
!In order for the class to be serializable put SERIALIZABLE_TYPE macro in the declaration
and REGISTER_TYPE macro in the implementation.
*/

class IStreamable
{
protected:
	virtual void writeState( std::ostream& outStream ) const = 0;	//overridden by implementers
	virtual void readState( std::istream& inStream ) = 0;			// overridden by implementers
	virtual std::string getClassName() const = 0;					//no need to override this method, use REGISTER_TYPE macro
};

class Streamable : public IStreamable
{
public:
	virtual ~Streamable() = default;
	Streamable() = default;
	Streamable( const Streamable & ) = default;
	Streamable& operator=(const Streamable &) = default;
// 	Streamable( Streamable && ) = default;				//not supported in VS2013
// 	Streamable& operator=(Streamable &&) = default;		//not supported in VS2013

	static void serialize( std::ostream& outStream, const Streamable* obj );
	static std::unique_ptr<Streamable> unserialize( std::istream& inStream );
	static void registerType( const std::string& name, IStreamableFactory* factory );
	friend std::ostream& operator<<( std::ostream& outStream, const Streamable& obj );
	friend std::istream& operator>>( std::istream& inStream, const Streamable& obj );
};