#pragma once

#include "PolymorphicBaseClass.h"

struct ISerializable;

//! \brief Interface for serializable object serializer
struct ISerializer : PolymorphicBaseClass
{
    virtual void serialize(ISerializable* obj) = 0;
};
