#pragma once

#include "PolymorphicBaseClass.h"

namespace simpson {

struct ISerializable;

//! \brief Interface for serializable object serializer
struct ISerializer : PolymorphicBaseClass
{
    virtual void serialize(ISerializable* obj) = 0;
};

}
