#pragma once

#include "VirtualBase.h"

#include <string>

struct IStorageOut : VirtualBase
{
    // Extractors
    virtual IStorageOut& operator<<(bool& obj) = 0;
    virtual IStorageOut& operator<<(short& obj) = 0;
    virtual IStorageOut& operator<<(unsigned short& obj) = 0;
    virtual IStorageOut& operator<<(int& obj) = 0;
    virtual IStorageOut& operator<<(unsigned int& obj) = 0;
    virtual IStorageOut& operator<<(long& obj) = 0;
    virtual IStorageOut& operator<<(unsigned long& obj) = 0;
    virtual IStorageOut& operator<<(float& obj) = 0;
    virtual IStorageOut& operator<<(double& obj) = 0;
    virtual IStorageOut& operator<<(const double& obj) = 0;
    virtual IStorageOut& operator<<(long double& obj) = 0;
    virtual IStorageOut& operator<<(std::string& obj) = 0;
    virtual IStorageOut& operator<<(const std::string& obj) = 0;
    virtual IStorageOut& operator<<(char const * obj) = 0;
};
