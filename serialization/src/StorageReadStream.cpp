#include "StorageReadStream.h"

StorageReadStream::StorageReadStream(std::istream &inStream)
    : m_inStream(inStream)
{}

IStorageRead &StorageReadStream::operator>>(bool &obj)              { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(short &obj)             { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(unsigned short &obj)    { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(int &obj)               { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(unsigned int &obj)      { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(long &obj)              { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(unsigned long &obj)     { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(float &obj)             { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(double &obj)            { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator>>(long double &obj)       { m_inStream >> obj; return *this; }
IStorageRead &StorageReadStream::operator >>(std::string &obj)      { m_inStream >> obj; return *this; }
