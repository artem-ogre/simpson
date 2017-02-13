#include "StorageReadStream.h"

#include <utility>

using namespace simpson;

namespace
{

template <class T>
void readFromStream(std::istream &inStream, T &&x)
{
    inStream >> std::forward<T>(x);
}

} // namespace

StorageReadStream::StorageReadStream(std::istream &inStream)
    : m_inStream(inStream)
{}

IStorageRead &StorageReadStream::operator>>(bool &obj)              { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(short &obj)             { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(unsigned short &obj)    { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(int &obj)               { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(unsigned int &obj)      { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(long &obj)              { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(unsigned long &obj)     { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(float &obj)             { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(double &obj)            { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator>>(long double &obj)       { readFromStream(m_inStream, obj); return *this; }
IStorageRead &StorageReadStream::operator >>(std::string &obj)      { readFromStream(m_inStream, obj); return *this; }
