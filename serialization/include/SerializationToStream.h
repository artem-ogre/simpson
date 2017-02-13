//! This header contains functionality needed for serializing and deserealizing to/from a stream
#pragma once

#include "Serializer.h"
#include "Deserializer.h"
#include "StorageReadStream.h"
#include "StorageWriteStream.h"

namespace simpson
{

using StreamSerializer = Serializer<StorageWriteStream>;
using StreamDeserializer = Deserializer<StorageReadStream>;

}

std::ostream& operator<<(std::ostream& outStream, simpson::ISerializable& obj);
std::istream& operator>>(std::istream& inStream, simpson::ISerializable* obj);
