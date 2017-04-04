#pragma once

#include "PolymorphicBaseClass.h"

#include <string>
#include <memory>

namespace simpson
{

/// Interface for storage used for reading/writing serialized data.
struct IStorage : PolymorphicBaseClass
{
    virtual IStorage& operator|(bool& obj) = 0;            ///< Read bool from storage.
    virtual IStorage& operator|(short& obj) = 0;           ///< Read short from storage.
    virtual IStorage& operator|(unsigned short& obj) = 0;  ///< Read unsigned short from storage.
    virtual IStorage& operator|(int& obj) = 0;             ///< Read int from storage.
    virtual IStorage& operator|(unsigned int& obj) = 0;    ///< Read unsigned int from storage.
    virtual IStorage& operator|(long& obj) = 0;            ///< Read long from storage.
    virtual IStorage& operator|(unsigned long& obj) = 0;   ///< Read unsigned long from storage.
    virtual IStorage& operator|(float& obj) = 0;           ///< Read float from storage.
    virtual IStorage& operator|(double& obj) = 0;          ///< Read double from storage.
    virtual IStorage& operator|(long double& obj) = 0;     ///< Read long double from storage.
    virtual IStorage& operator|(std::string& obj) = 0;     ///< Read string from storage.
};

}
