#pragma once

class IStreamable; 
class IStreamableFactory
{
public:
	virtual IStreamable* create() const = 0;
};

