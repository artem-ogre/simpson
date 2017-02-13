#pragma once

#include "PolymorphicBaseClass.h"

namespace simpson {

struct ISerializable;

//! \brief Interface for serializable objects factory
struct ISerializableFactory : PolymorphicBaseClass
{
    /*!
     * \brief creates serializable object
     * \return pointer to polymorphic base of the serializable object
     */
    virtual ISerializable* create() const = 0;
};

}
