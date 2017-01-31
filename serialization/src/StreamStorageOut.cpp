#include "StreamStorageOut.h"

StreamStorageOut::StreamStorageOut(std::ostream &outStream)
    : m_outStream(outStream)
{}

IStorageOut &StreamStorageOut::operator<<(const double &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(bool &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(short &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(unsigned short &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(int &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(unsigned int &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(long &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(unsigned long &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(float &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(double &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(long double &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(std::string &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(const std::__cxx11::string &obj) { return redirectToStream(obj); }
IStorageOut &StreamStorageOut::operator<<(char const * obj) { return redirectToStream(obj); }
