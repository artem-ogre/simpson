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
	void registerClass(const std::string& classId);
	virtual IStreamable* create( std::istream& inStream ) const = 0; //Virtual constructor idiom //TODO: use a smart pointer
	virtual IStreamable* createDummy() const = 0;

protected:
	std::string m_classId;
};