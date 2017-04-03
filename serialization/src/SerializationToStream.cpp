#include "SerializationToStream.h"

using namespace simpson;

std::ostream& operator<<(std::ostream& outStream, ISerializable& obj)
{
    StreamSerializer(outStream).serialize(&obj);
    return outStream;
}

std::istream& operator>>(std::istream& inStream, ISerializable* obj)
{
    StreamDeserializer serializer(inStream);
    obj = serializer.deserialize();
    return inStream;
}
