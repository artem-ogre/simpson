#include "Serializers.h"
#include "SerializableTypes.h"

StreamSerializer::StreamSerializer(std::ostream& outStream)
    : m_outStream(outStream)
{}

void StreamSerializer::serialize(const ISerializable* obj) const
{
    m_outStream << " " << obj->getClassName();
    obj->write(m_outStream);
}

StreamDeserializer::StreamDeserializer(std::istream& inStream)
    : m_inStream(inStream)
{}

ISerializablePtr StreamDeserializer::deserialize() const
{
    std::string typeName;
    m_inStream >> typeName;
    ISerializablePtr result(SerializableTypes::create(typeName));
    result->read(m_inStream);
    return result;
}

std::ostream& operator<<(std::ostream& outStream, const ISerializable& obj)
{
    StreamSerializer(outStream).serialize(&obj);
    return outStream;
}

std::istream& operator>>(std::istream& inStream, ISerializablePtr& obj)
{
    obj = StreamDeserializer(inStream).deserialize();
    return inStream;
}
