#pragma once

//! \brief Defaults the rule-of-five so that derived classes can follow rule-of-zero
struct PolymorphicBaseClass
{
    virtual ~PolymorphicBaseClass() = default;
    PolymorphicBaseClass() = default;
    PolymorphicBaseClass(const PolymorphicBaseClass&) = default;
    PolymorphicBaseClass(PolymorphicBaseClass&&) = default;
    PolymorphicBaseClass& operator=(const PolymorphicBaseClass&) = default;
    PolymorphicBaseClass& operator=(PolymorphicBaseClass&&) = default;
};
