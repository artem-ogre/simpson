/// \file
/// \brief This header contains functionality needed for serializing and deserealizing to/from a stream
#pragma once

#include "ISerializable.h"
#include "IStorage.h"

#include <iostream>

/// Contains all the functionality provided by the library.
namespace simpson
{

/// Serialize object to ostream
std::ostream& operator<<(std::ostream& outStream, simpson::ISerializable& obj);
/// Deserialize object from istream
std::istream& operator>>(std::istream& inStream, simpson::ISerializable* obj);

} // simpson
