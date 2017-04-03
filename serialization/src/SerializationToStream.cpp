#include "SerializationToStream.h"

#include <memory>

using namespace simpson;

std::ostream& operator<<(std::ostream& outStream, ISerializable& obj)
{
    std::unique_ptr<ISerializer> serializer = std::make_unique<StreamSerializer>(outStream);
    serializer->serialize(&obj);
    return outStream;
}

std::istream& operator>>(std::istream& inStream, ISerializable* obj)
{
    std::unique_ptr<ISerializer> serializer = std::make_unique<StreamDeserializer>(inStream);
    obj = serializer->deserialize();
    return inStream;
}
