#pragma once

#include "IStorageWrite.h"

#include <iostream>

namespace simpson {

/// Implementation of storage that writes serialized data to ostream.
struct StorageWriteStream : IStorageWrite
{
    /// \brief Constructor.
    /// \param outStream ostream that the storage uses.
    explicit StorageWriteStream(std::ostream &outStream);
    // IStorageIn interface
    virtual IStorageWrite &operator<<(bool &obj) override; ///< Write bool to storage.

    virtual IStorageWrite &operator<<(short &obj) override;             ///< Write short to ostream.
    virtual IStorageWrite &operator<<(unsigned short &obj) override;    ///< Write unsigned short to ostream.
    virtual IStorageWrite &operator<<(int &obj) override;               ///< Write int to ostream.
    virtual IStorageWrite &operator<<(unsigned int &obj) override;      ///< Write unsigned int to ostream.
    virtual IStorageWrite &operator<<(long &obj) override;              ///< Write long to ostream.
    virtual IStorageWrite &operator<<(unsigned long &obj) override;     ///< Write unsigned long to ostream.
    virtual IStorageWrite &operator<<(float &obj) override;             ///< Write float to ostream.
    virtual IStorageWrite &operator<<(double &obj) override;            ///< Write double to ostream.
    virtual IStorageWrite &operator<<(long double &obj) override;       ///< Write const double to ostream.
    virtual IStorageWrite &operator<<(std::string &obj) override;       ///< Write long double to ostream.
    virtual IStorageWrite &operator<<(const std::string &obj) override; ///< Write string to ostream.
    virtual IStorageWrite &operator<<(const double &obj) override;      ///< Write const std::string& to ostream.
    virtual IStorageWrite &operator<<(char const *obj) override;        ///< Write c-string to ostream.

private:
    std::ostream &m_outStream;
};

} // simpson
