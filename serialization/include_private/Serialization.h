#pragma once

namespace simpson
{

struct ISerializable;
struct IStorage;

/// \brief Serializes a provided serializable object.
/// \param obj an object to be serialized
void serialize(ISerializable* obj, IStorage& storage);
/// Polymorphically deserialize a serializable object
/// \return  A raw pointer to the newly created deserialized object
ISerializable* deserialize(IStorage& storage);
}
