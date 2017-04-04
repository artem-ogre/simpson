#pragma once

#include "IStorage.h"

#include <iostream>

namespace simpson
{

/// Implementation of storage that reads serialized data from istream.
struct StorageReadStream final : IStorage
{
    /// \brief Constructor.
    /// \param inStream istream that the storage uses.
    explicit StorageReadStream(std::istream &inStream);

private:
    // IStorageIn interface
    virtual IStorage &operator|(bool &obj) override;           ///< Read bool from istream.
    virtual IStorage &operator|(short &obj) override;          ///< Read short from istream.
    virtual IStorage &operator|(unsigned short &obj) override; ///< Read unsigned short from istream.
    virtual IStorage &operator|(int &obj) override;            ///< Read int from istream.
    virtual IStorage &operator|(unsigned int &obj) override;   ///< Read unsigned int from istream.
    virtual IStorage &operator|(long &obj) override;           ///< Read long from istream.
    virtual IStorage &operator|(unsigned long &obj) override;  ///< Read unsigned long from istream.
    virtual IStorage &operator|(float &obj) override;          ///< Read float from istream.
    virtual IStorage &operator|(double &obj) override;         ///< Read double from istream.
    virtual IStorage &operator|(long double &obj) override;    ///< Read long double from istream.
    virtual IStorage &operator|(std::string &obj) override;    ///< Read string from istream.

private:
    template <class T>
    IStorage &readFromStream(T &&x)
    {
        m_inStream >> std::forward<T>(x);
        return *this;
    }

private:
    std::istream &m_inStream;
};
}
