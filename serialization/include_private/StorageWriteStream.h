#pragma once

#include "IStorage.h"

#include <iostream>

namespace simpson
{

/// Implementation of storage that writes serialized data to ostream.
struct StorageWriteStream final : IStorage
{
    /// \brief Constructor.
    /// \param outStream ostream that the storage uses.
    explicit StorageWriteStream(std::ostream &outStream);

private:
    // IStorageIn interface
    virtual IStorage &operator|(bool &obj) override;           ///< Write bool to storage.
    virtual IStorage &operator|(short &obj) override;          ///< Write short to ostream.
    virtual IStorage &operator|(unsigned short &obj) override; ///< Write unsigned short to ostream.
    virtual IStorage &operator|(int &obj) override;            ///< Write int to ostream.
    virtual IStorage &operator|(unsigned int &obj) override;   ///< Write unsigned int to ostream.
    virtual IStorage &operator|(long &obj) override;           ///< Write long to ostream.
    virtual IStorage &operator|(unsigned long &obj) override;  ///< Write unsigned long to ostream.
    virtual IStorage &operator|(float &obj) override;          ///< Write float to ostream.
    virtual IStorage &operator|(double &obj) override;         ///< Write double to ostream.
    virtual IStorage &operator|(long double &obj) override;    ///< Write const double to ostream.
    virtual IStorage &operator|(std::string &obj) override;    ///< Write long double to ostream.

private:
    std::ostream &m_outStream;
};

} // simpson
