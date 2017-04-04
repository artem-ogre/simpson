/// \file
/// \brief This header contains functionality needed for serializing and deserealizing to/from a stream
#pragma once

#include <iostream>

namespace simpson
{
class ISerializable;
}

namespace simpson
{
/// Serialize object to ostream
std::ostream& operator<<(std::ostream& outStream, ISerializable& obj);
/// Deserialize object from istream
std::istream& operator>>(std::istream& inStream, ISerializable* obj);
}
