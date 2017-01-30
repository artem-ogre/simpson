#include "StreamStorageIn.h"

StreamStorageIn::StreamStorageIn(std::istream &inStream)
    : m_inStream(inStream)
{}

IStorageIn &StreamStorageIn::operator>>(bool &obj)              { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(short &obj)             { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(unsigned short &obj)    { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(int &obj)               { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(unsigned int &obj)      { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(long &obj)              { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(unsigned long &obj)     { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(float &obj)             { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(double &obj)            { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator>>(long double &obj)       { return redirectToStream(obj); }
IStorageIn &StreamStorageIn::operator >>(std::string &obj)      { return redirectToStream(obj); }
