#pragma once

#include "PolymorphicBaseClass.h"

#include <memory>
#include <string>

namespace simpson
{

/// Interface for storage used for reading/writing serialized data.
struct IStorage : PolymorphicBaseClass
{
    virtual IStorage& operator|(bool& obj) = 0;           ///< Process bool
    virtual IStorage& operator|(short& obj) = 0;          ///< Process short
    virtual IStorage& operator|(unsigned short& obj) = 0; ///< Process unsigned
    virtual IStorage& operator|(int& obj) = 0;            ///< Process int from
    virtual IStorage& operator|(unsigned int& obj) = 0;   ///< Process unsigned int
    virtual IStorage& operator|(long& obj) = 0;           ///< Process long
    virtual IStorage& operator|(unsigned long& obj) = 0;  ///< Process unsigned long
    virtual IStorage& operator|(float& obj) = 0;          ///< Process float
    virtual IStorage& operator|(double& obj) = 0;         ///< Process double
    virtual IStorage& operator|(long double& obj) = 0;    ///< Process long double
    virtual IStorage& operator|(std::string& obj) = 0;    ///< Process string
};
}
