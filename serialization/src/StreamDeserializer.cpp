#include "StreamDeserializer.h"
#include "ISerializable.h"
#include "SerializableTypes.h"

StreamDeserializer::StreamDeserializer(std::istream& inStream)
    : m_storage(inStream)
{}

ISerializable* StreamDeserializer::deserialize()
{
    std::string typeName;
    m_storage >> typeName;
    ISerializable* result = SerializableTypes::create(typeName);
    result->loadFrom(m_storage);
    return result;
}

std::istream& operator>>(std::istream& inStream, ISerializable* obj)
{
    obj = StreamDeserializer(inStream).deserialize();
    return inStream;
}
