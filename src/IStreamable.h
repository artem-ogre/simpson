#pragma once

#include "RegisterTypeMacro.h"
#include "IStreamableFactory.h"

#include <iostream>
#include <string>
#include <map>

class IStreamable
{
public:
	IStreamable();
	static void serialize( std::ostream& outStream, const IStreamable* obj );
	static IStreamable* unserialize( std::istream& inStream ); //TODO: use a smart pointer
	static void registerType( const std::string& name, IStreamableFactory* factory );
	friend std::ostream& operator<<( std::ostream& outStream, const IStreamable& obj );
	friend std::istream& operator>>( std::istream& inStream, const IStreamable& obj );
protected:
	virtual void writeState( std::ostream& outStream ) const = 0;
	virtual void readState( std::istream& inStream ) = 0;
	virtual std::string getClassName() const = 0;
};