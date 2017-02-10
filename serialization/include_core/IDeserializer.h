#pragma once

#include "PolymorphicBaseClass.h"

struct ISerializable;

//! \brief Interface for serializable object deserializer
struct IDeserializer : PolymorphicBaseClass
{
    virtual ISerializable* deserialize() = 0;
};
