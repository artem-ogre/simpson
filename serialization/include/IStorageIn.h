#pragma once

#include "VirtualBase.h"

#include <string>

struct IStorageIn : VirtualBase
{
    // Extractors
    virtual IStorageIn& operator>>(bool& obj) = 0;
    virtual IStorageIn& operator>>(short& obj) = 0;
    virtual IStorageIn& operator>>(unsigned short& obj) = 0;
    virtual IStorageIn& operator>>(int& obj) = 0;
    virtual IStorageIn& operator>>(unsigned int& obj) = 0;
    virtual IStorageIn& operator>>(long& obj) = 0;
    virtual IStorageIn& operator>>(unsigned long& obj) = 0;
    virtual IStorageIn& operator>>(float& obj) = 0;
    virtual IStorageIn& operator>>(double& obj) = 0;
    virtual IStorageIn& operator>>(long double& obj) = 0;
    virtual IStorageIn& operator>>(std::string& obj) = 0;
};
