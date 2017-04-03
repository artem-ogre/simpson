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

//IStorageWrite &StorageWriteStream::operator<<(const double &obj)                { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(bool &obj)                        { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(short &obj)                       { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(unsigned short &obj)              { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(int &obj)                         { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(unsigned int &obj)                { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(long &obj)                        { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(unsigned long &obj)               { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(float &obj)                       { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(double &obj)                      { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(long double &obj)                 { writeToStream(m_outStream, obj); return *this; }
IStorage &StorageWriteStream::operator|(std::string &obj)                 { writeToStream(m_outStream, obj); return *this; }
