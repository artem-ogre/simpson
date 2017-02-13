#include "StorageWriteStream.h"

using namespace simpson;

namespace
{

template <class T>
void writeToStream(std::ostream &outStream, T &&x)
{
    outStream << std::endl << std::forward<T>(x);
}

} // namespace

StorageWriteStream::StorageWriteStream(std::ostream &outStream)
    : m_outStream(outStream)
{}

IStorageWrite &StorageWriteStream::operator<<(const double &obj)                { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(bool &obj)                        { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(short &obj)                       { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(unsigned short &obj)              { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(int &obj)                         { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(unsigned int &obj)                { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(long &obj)                        { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(unsigned long &obj)               { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(float &obj)                       { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(double &obj)                      { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(long double &obj)                 { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(std::string &obj)                 { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(const std::__cxx11::string &obj)  { writeToStream(m_outStream, obj); return *this; }
IStorageWrite &StorageWriteStream::operator<<(char const * obj)                 { writeToStream(m_outStream, obj); return *this; }
