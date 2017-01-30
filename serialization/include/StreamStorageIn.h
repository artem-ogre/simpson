#pragma once

#include "IStorageIn.h"

#include <iostream>

struct StreamStorageIn : IStorageIn
{
    StreamStorageIn(std::istream &inStream);
    // IStorageIn interface
    virtual IStorageIn &operator>>(bool &obj);
    virtual IStorageIn &operator>>(short &obj);
    virtual IStorageIn &operator>>(unsigned short &obj);
    virtual IStorageIn &operator>>(int &obj);
    virtual IStorageIn &operator>>(unsigned int &obj);
    virtual IStorageIn &operator>>(long &obj);
    virtual IStorageIn &operator>>(unsigned long &obj);
    virtual IStorageIn &operator>>(float &obj);
    virtual IStorageIn &operator>>(double &obj);
    virtual IStorageIn &operator>>(long double &obj);
    virtual IStorageIn &operator >>(std::string &obj);
private:
    template <typename T>
    IStorageIn &redirectToStream(T &obj)
    {
        m_inStream >> obj;
        return *this;
    }
private:
    std::istream &m_inStream;
};
