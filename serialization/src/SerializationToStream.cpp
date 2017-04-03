#include "SerializationToStream.h"

#include <memory>

using namespace simpson;

namespace
{
/// Serializer able to serialize to ostream
using StreamSerializer = Serializer<StorageWriteStream>;
/// Deserializer able to deserialize from istream
using StreamDeserializer = Serializer<StorageReadStream>;
}

std::ostream& simpson::operator<<(std::ostream& outStream, ISerializable& obj)
{
    std::unique_ptr<ISerializer> serializer = std::make_unique<StreamSerializer>(outStream);
    serializer->serialize(&obj);
    return outStream;
}

std::istream& simpson::operator>>(std::istream& inStream, ISerializable* obj)
{
    std::unique_ptr<ISerializer> serializer = std::make_unique<StreamDeserializer>(inStream);
    obj = serializer->deserialize();
    return inStream;
}
