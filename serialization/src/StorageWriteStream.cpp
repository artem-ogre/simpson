#include "StorageWriteStream.h"

StorageWriteStream::StorageWriteStream(std::ostream &outStream)
    : m_outStream(outStream)
{}

IStorageWrite &StorageWriteStream::operator<<(const double &obj)                { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(bool &obj)                        { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(short &obj)                       { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(unsigned short &obj)              { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(int &obj)                         { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(unsigned int &obj)                { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(long &obj)                        { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(unsigned long &obj)               { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(float &obj)                       { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(double &obj)                      { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(long double &obj)                 { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(std::string &obj)                 { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(const std::__cxx11::string &obj)  { m_outStream << obj; return *this; }
IStorageWrite &StorageWriteStream::operator<<(char const * obj)                 { m_outStream << obj; return *this; }
