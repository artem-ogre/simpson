#pragma once

#include "VirtualBase.h"

struct ISerializable;

//! \brief Interface for serializable object deserializer
struct IDeserializer : VirtualBase
{
    virtual ISerializable* deserialize() = 0;
};
