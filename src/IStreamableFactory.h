#pragma once

#include <memory>

class Streamable; 
class IStreamableFactory
{
public:
	virtual std::unique_ptr<Streamable> create() const = 0;
};

