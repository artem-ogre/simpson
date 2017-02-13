#pragma once

#include "PolymorphicBaseClass.h"

namespace simpson {
struct ISerializable;

//! \brief Interface for serializable object deserializer
struct IDeserializer : PolymorphicBaseClass
{
    virtual ISerializable* deserialize() = 0;
};
}
