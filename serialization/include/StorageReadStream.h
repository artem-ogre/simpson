#pragma once

#include "IStorageRead.h"

#include <iostream>

namespace simpson {

/// Implementation of storage that reads serialized data from istream.
struct StorageReadStream : IStorageRead
{
    /// \brief Constructor.
    /// \param inStream istream that the storage uses.
    explicit StorageReadStream(std::istream &inStream);
    // IStorageIn interface
    virtual IStorageRead &operator>>(bool &obj);           ///< Read bool from istream.
    virtual IStorageRead &operator>>(short &obj);          ///< Read short from istream.
    virtual IStorageRead &operator>>(unsigned short &obj); ///< Read unsigned short from istream.
    virtual IStorageRead &operator>>(int &obj);            ///< Read int from istream.
    virtual IStorageRead &operator>>(unsigned int &obj);   ///< Read unsigned int from istream.
    virtual IStorageRead &operator>>(long &obj);           ///< Read long from istream.
    virtual IStorageRead &operator>>(unsigned long &obj);  ///< Read unsigned long from istream.
    virtual IStorageRead &operator>>(float &obj);          ///< Read float from istream.
    virtual IStorageRead &operator>>(double &obj);         ///< Read double from istream.
    virtual IStorageRead &operator>>(long double &obj);    ///< Read long double from istream.
    virtual IStorageRead &operator>>(std::string &obj);    ///< Read string from istream.

private:
    std::istream &m_inStream;
};

} // simpson
