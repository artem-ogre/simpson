#include "SerializationToStream.h"

std::ostream& operator<<(std::ostream& outStream, ISerializable& obj)
{
    StreamSerializer(outStream).serialize(&obj);
    return outStream;
}

std::istream& operator>>(std::istream& inStream, ISerializable* obj)
{
    obj = StreamDeserializer(inStream).deserialize();
    return inStream;
}
