#include "StorageWriteStream.h"

using namespace simpson;

StorageWriteStream::StorageWriteStream(std::ostream &outStream)
    : m_outStream(outStream)
{
}
IStorage &StorageWriteStream::operator|(bool &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(short &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(unsigned short &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(int &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(unsigned int &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(long &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(unsigned long &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(float &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(double &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(long double &obj)
{
    return writeToStream(obj);
}
IStorage &StorageWriteStream::operator|(std::string &obj)
{
    return writeToStream(obj);
}
