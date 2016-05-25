#pragma once

#include <iostream>
#include <string>
#include <map>

class IStreamable
{
public:
	IStreamable();
	virtual void serialize( std::ostream& outStream ) const = 0;
	virtual IStreamable* unserialize( std::istream& inStream ) const; //TODO: use a smart pointer

protected:
	void registerClass();
	virtual IStreamable* createDummy() const = 0;//Virtual constructor idiom //TODO: use a smart pointer
	virtual void readState( std::istream& inStream ) = 0;
	virtual std::string getClassName() const = 0;

protected:
	std::string m_classId;
};