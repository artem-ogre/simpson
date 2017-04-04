#include "StreamReadStorage.h"

using namespace simpson;

StreamReadStorage::StreamReadStorage(std::istream &inStream)
    : m_inStream(inStream)
{
}
IStorage &StreamReadStorage::operator|(bool &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(short &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(unsigned short &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(int &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(unsigned int &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(long &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(unsigned long &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(float &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(double &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(long double &obj)
{
    return readFromStream(obj);
}
IStorage &StreamReadStorage::operator|(std::string &obj)
{
    return readFromStream(obj);
}
