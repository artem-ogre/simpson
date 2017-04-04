#include "StreamWriteStorage.h"

using namespace simpson;

StreamWriteStorage::StreamWriteStorage(std::ostream &outStream)
    : m_outStream(outStream)
{
}
IStorage &StreamWriteStorage::operator|(bool &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(short &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(unsigned short &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(int &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(unsigned int &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(long &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(unsigned long &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(float &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(double &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(long double &obj)
{
    return writeToStream(obj);
}
IStorage &StreamWriteStorage::operator|(std::string &obj)
{
    return writeToStream(obj);
}
