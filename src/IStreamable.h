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
	virtual void serialize( std::ostream& outStream ) const = 0;
	virtual IStreamable* unserialize( std::istream& inStream ) const; //TODO: use a smart pointer
	static void registerClass( const std::string& name, IStreamableFactory* factory );
protected:
	virtual void readState( std::istream& inStream ) = 0;
	virtual std::string getClassName() const = 0;
};

