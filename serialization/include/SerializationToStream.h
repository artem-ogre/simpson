/// \file
/// \brief This header contains functionality needed for serializing and deserealizing to/from a stream
#pragma once

#include "Serializer.h"
#include "Deserializer.h"
#include "StorageReadStream.h"
#include "StorageWriteStream.h"

/// Contains all the functionality provided by the library.
namespace simpson {

/// Serializer able to serialize to ostream
using StreamSerializer = Serializer<StorageWriteStream>;
/// Deserializer able to deserialize from istream
using StreamDeserializer = Deserializer<StorageReadStream>;

} // simpson

std::ostream& operator<<(std::ostream& outStream, simpson::ISerializable& obj);
std::istream& operator>>(std::istream& inStream, simpson::ISerializable* obj);
