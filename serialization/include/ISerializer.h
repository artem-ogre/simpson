#pragma once

#include "VirtualBase.h"

struct ISerializable;

//! \brief Interface for serializable object serializer
struct ISerializer : VirtualBase
{
    virtual void serialize(const ISerializable* obj) const = 0;
};
