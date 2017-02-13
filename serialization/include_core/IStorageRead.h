#pragma once

#include "PolymorphicBaseClass.h"

#include <string>

namespace simpson {

/// Interface for storage used for reading serialized data.
struct IStorageRead : PolymorphicBaseClass
{
    // Extractors
    virtual IStorageRead& operator>>(bool& obj) = 0;            ///< Read bool from storage.
    virtual IStorageRead& operator>>(short& obj) = 0;           ///< Read short from storage.
    virtual IStorageRead& operator>>(unsigned short& obj) = 0;  ///< Read unsigned short from storage.
    virtual IStorageRead& operator>>(int& obj) = 0;             ///< Read int from storage.
    virtual IStorageRead& operator>>(unsigned int& obj) = 0;    ///< Read unsigned int from storage.
    virtual IStorageRead& operator>>(long& obj) = 0;            ///< Read long from storage.
    virtual IStorageRead& operator>>(unsigned long& obj) = 0;   ///< Read unsigned long from storage.
    virtual IStorageRead& operator>>(float& obj) = 0;           ///< Read float from storage.
    virtual IStorageRead& operator>>(double& obj) = 0;          ///< Read double from storage.
    virtual IStorageRead& operator>>(long double& obj) = 0;     ///< Read long double from storage.
    virtual IStorageRead& operator>>(std::string& obj) = 0;     ///< Read string from storage.
};

} // simpson
