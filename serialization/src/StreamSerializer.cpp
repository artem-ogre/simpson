#include "StreamSerializer.h"
#include "ISerializable.h"

StreamSerializer::StreamSerializer(std::ostream& outStream)
    : m_outStream(outStream)
{}

void StreamSerializer::serialize(const ISerializable* obj) const
{
    m_outStream << " " << obj->getClassName();
    obj->saveTo(m_outStream);
}

std::ostream& operator<<(std::ostream& outStream, const ISerializable& obj)
{
    StreamSerializer(outStream).serialize(&obj);
    return outStream;
}
