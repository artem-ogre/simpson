#include "Serializers.h"
#include "SerializableTypes.h"

StreamSerializer::StreamSerializer(std::ostream& outStream)
    : m_outStream(outStream)
{}

void StreamSerializer::serialize(const ISerializable* obj) const
{
    m_outStream << " " << obj->getClassName();
    obj->saveTo(m_outStream);
}

StreamDeserializer::StreamDeserializer(std::istream& inStream)
    : m_inStream(inStream)
{}

ISerializableUniquePtr StreamDeserializer::deserialize() const
{
    std::string typeName;
    m_inStream >> typeName;
    ISerializableUniquePtr result(SerializableTypes::create(typeName));
    result->loadFrom(m_inStream);
    return result;
}

std::ostream& operator<<(std::ostream& outStream, const ISerializable& obj)
{
    StreamSerializer(outStream).serialize(&obj);
    return outStream;
}

std::istream& operator>>(std::istream& inStream, ISerializableUniquePtr& obj)
{
    obj = StreamDeserializer(inStream).deserialize();
    return inStream;
}
