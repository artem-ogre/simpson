#pragma once

#include "VirtualBase.h"

struct ISerializable;

//! \brief Interface for serializable objects factory
struct ISerializableFactory : VirtualBase
{
    /*!
     * \brief creates serializable object
     * \return pointer to polymorphic base of the serializable object
     */
    virtual ISerializable* create() const = 0;
};
