#include "StorageReadStream.h"

using namespace simpson;

StorageReadStream::StorageReadStream(std::istream &inStream)
    : m_inStream(inStream)
{
}
IStorage &StorageReadStream::operator|(bool &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(short &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(unsigned short &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(int &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(unsigned int &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(long &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(unsigned long &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(float &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(double &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(long double &obj)
{
    return readFromStream(obj);
}
IStorage &StorageReadStream::operator|(std::string &obj)
{
    return readFromStream(obj);
}
