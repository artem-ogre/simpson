#pragma once

#include "IStorageOut.h"

#include <iostream>

struct StreamStorageOut : IStorageOut
{
    StreamStorageOut(std::ostream &outStream);
    // IStorageIn interface
    virtual IStorageOut &operator<<(bool &obj) override;
    virtual IStorageOut &operator<<(short &obj) override;
    virtual IStorageOut &operator<<(unsigned short &obj) override;
    virtual IStorageOut &operator<<(int &obj) override;
    virtual IStorageOut &operator<<(unsigned int &obj) override;
    virtual IStorageOut &operator<<(long &obj) override;
    virtual IStorageOut &operator<<(unsigned long &obj) override;
    virtual IStorageOut &operator<<(float &obj) override;
    virtual IStorageOut &operator<<(double &obj) override;
    virtual IStorageOut &operator<<(long double &obj) override;
    virtual IStorageOut &operator<<(std::string &obj) override;
    virtual IStorageOut &operator<<(const std::string &obj) override;
    virtual IStorageOut &operator<<(const double &obj) override;
    virtual IStorageOut &operator<<(char const *obj) override;

private:
    template <typename T>
    IStorageOut &redirectToStream(T &obj)
    {
        m_outStream << obj;
        return *this;
    }

private:
    std::ostream &m_outStream;
};
