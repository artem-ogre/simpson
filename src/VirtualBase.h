#pragma once

//! \brief Defaults the rule-of-five so that derived classes can follow rule-of-zero
struct VirtualBase
{
    virtual ~VirtualBase() = default;
    VirtualBase() = default;
    VirtualBase(const VirtualBase&) = default;
    VirtualBase(VirtualBase&&) = default;
    VirtualBase& operator=(const VirtualBase&) = default;
    VirtualBase& operator=(VirtualBase&&) = default;
};
