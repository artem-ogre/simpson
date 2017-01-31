#include "StreamSerializer.h"
#include "ISerializable.h"

StreamSerializer::StreamSerializer(std::ostream& outStream)
    : m_storage(outStream)
{}

void StreamSerializer::serialize(ISerializable* obj)
{
    m_storage << " " << obj->getClassName();
    obj->saveTo(m_storage);
}

std::ostream& operator<<(std::ostream& outStream, ISerializable& obj)
{
    StreamSerializer(outStream).serialize(&obj);
    return outStream;
}
