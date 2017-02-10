#pragma once

#include "PolymorphicBaseClass.h"

#include <string>

struct IStorageRead : PolymorphicBaseClass
{
    // Extractors
    virtual IStorageRead& operator>>(bool& obj) = 0;
    virtual IStorageRead& operator>>(short& obj) = 0;
    virtual IStorageRead& operator>>(unsigned short& obj) = 0;
    virtual IStorageRead& operator>>(int& obj) = 0;
    virtual IStorageRead& operator>>(unsigned int& obj) = 0;
    virtual IStorageRead& operator>>(long& obj) = 0;
    virtual IStorageRead& operator>>(unsigned long& obj) = 0;
    virtual IStorageRead& operator>>(float& obj) = 0;
    virtual IStorageRead& operator>>(double& obj) = 0;
    virtual IStorageRead& operator>>(long double& obj) = 0;
    virtual IStorageRead& operator>>(std::string& obj) = 0;
};
