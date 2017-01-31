#pragma once

#include "VirtualBase.h"

struct ISerializable;

//! \brief Interface for serializable object serializer
struct ISerializer : VirtualBase
{
    virtual void serialize(ISerializable* obj) = 0;
};
