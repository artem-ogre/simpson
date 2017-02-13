#pragma once

#include "PolymorphicBaseClass.h"

#include <string>

namespace simpson {

struct IStorageWrite : PolymorphicBaseClass
{
    // Extractors
    virtual IStorageWrite& operator<<(bool& obj) = 0;
    virtual IStorageWrite& operator<<(short& obj) = 0;
    virtual IStorageWrite& operator<<(unsigned short& obj) = 0;
    virtual IStorageWrite& operator<<(int& obj) = 0;
    virtual IStorageWrite& operator<<(unsigned int& obj) = 0;
    virtual IStorageWrite& operator<<(long& obj) = 0;
    virtual IStorageWrite& operator<<(unsigned long& obj) = 0;
    virtual IStorageWrite& operator<<(float& obj) = 0;
    virtual IStorageWrite& operator<<(double& obj) = 0;
    virtual IStorageWrite& operator<<(const double& obj) = 0;
    virtual IStorageWrite& operator<<(long double& obj) = 0;
    virtual IStorageWrite& operator<<(std::string& obj) = 0;
    virtual IStorageWrite& operator<<(const std::string& obj) = 0;
    virtual IStorageWrite& operator<<(char const * obj) = 0;
};

}
