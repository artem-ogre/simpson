#pragma once

#include "PolymorphicBaseClass.h"

#include <string>

namespace simpson {

/// Interface for storage used for writing serialized data.
struct IStorageWrite : PolymorphicBaseClass
{
    // Extractors
    virtual IStorageWrite& operator<<(bool& obj) = 0;               ///< Write bool to storage.
    virtual IStorageWrite& operator<<(short& obj) = 0;              ///< Write short to storage.
    virtual IStorageWrite& operator<<(unsigned short& obj) = 0;     ///< Write unsigned short to storage.
    virtual IStorageWrite& operator<<(int& obj) = 0;                ///< Write int to storage.
    virtual IStorageWrite& operator<<(unsigned int& obj) = 0;       ///< Write unsigned int to storage.
    virtual IStorageWrite& operator<<(long& obj) = 0;               ///< Write long to storage.
    virtual IStorageWrite& operator<<(unsigned long& obj) = 0;      ///< Write unsigned long to storage.
    virtual IStorageWrite& operator<<(float& obj) = 0;              ///< Write float to storage.
    virtual IStorageWrite& operator<<(double& obj) = 0;             ///< Write double to storage.
    virtual IStorageWrite& operator<<(const double& obj) = 0;       ///< Write const double to storage.
    virtual IStorageWrite& operator<<(long double& obj) = 0;        ///< Write long double to storage.
    virtual IStorageWrite& operator<<(std::string& obj) = 0;        ///< Write string to storage.
    virtual IStorageWrite& operator<<(const std::string& obj) = 0;  ///< Write const std::string& to storage.
    virtual IStorageWrite& operator<<(char const * obj) = 0;        ///< Write c-string to storage.
};

} // simpson
