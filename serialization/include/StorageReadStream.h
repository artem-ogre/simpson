#pragma once

#include "IStorageRead.h"

#include <iostream>

struct StorageReadStream : IStorageRead
{
    explicit StorageReadStream(std::istream &inStream);
    // IStorageIn interface
    virtual IStorageRead &operator>>(bool &obj);
    virtual IStorageRead &operator>>(short &obj);
    virtual IStorageRead &operator>>(unsigned short &obj);
    virtual IStorageRead &operator>>(int &obj);
    virtual IStorageRead &operator>>(unsigned int &obj);
    virtual IStorageRead &operator>>(long &obj);
    virtual IStorageRead &operator>>(unsigned long &obj);
    virtual IStorageRead &operator>>(float &obj);
    virtual IStorageRead &operator>>(double &obj);
    virtual IStorageRead &operator>>(long double &obj);
    virtual IStorageRead &operator>>(std::string &obj);

private:
    std::istream &m_inStream;
};
