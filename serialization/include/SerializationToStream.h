/// \file
/// \brief This header contains functionality needed for serializing and deserealizing to/from a stream
#pragma once

#include "IStorage.h"

#include <iostream>

/// Contains all the functionality provided by the library.
namespace simpson
{

class ISerializable;

/// Serialize object to ostream
std::ostream& operator<<(std::ostream& outStream, ISerializable& obj);
/// Deserialize object from istream
std::istream& operator>>(std::istream& inStream, ISerializable* obj);

} // simpson
