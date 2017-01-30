#include "StreamDeserializer.h"
#include "ISerializable.h"
#include "SerializableTypes.h"

StreamDeserializer::StreamDeserializer(std::istream& inStream)
    : m_inStream(inStream)
{}

ISerializable* StreamDeserializer::deserialize()
{
    std::string typeName;
    m_inStream >> typeName;
    ISerializable* result = SerializableTypes::create(typeName);
    result->loadFrom(m_inStream);
    return result;
}

std::istream& operator>>(std::istream& inStream, ISerializable* obj)
{
    obj = StreamDeserializer(inStream).deserialize();
    return inStream;
}
