#pragma once

#include "IStorageWrite.h"

#include <iostream>

struct StorageWriteStream : IStorageWrite
{
    StorageWriteStream(std::ostream &outStream);
    // IStorageIn interface
    virtual IStorageWrite &operator<<(bool &obj) override;
    virtual IStorageWrite &operator<<(short &obj) override;
    virtual IStorageWrite &operator<<(unsigned short &obj) override;
    virtual IStorageWrite &operator<<(int &obj) override;
    virtual IStorageWrite &operator<<(unsigned int &obj) override;
    virtual IStorageWrite &operator<<(long &obj) override;
    virtual IStorageWrite &operator<<(unsigned long &obj) override;
    virtual IStorageWrite &operator<<(float &obj) override;
    virtual IStorageWrite &operator<<(double &obj) override;
    virtual IStorageWrite &operator<<(long double &obj) override;
    virtual IStorageWrite &operator<<(std::string &obj) override;
    virtual IStorageWrite &operator<<(const std::string &obj) override;
    virtual IStorageWrite &operator<<(const double &obj) override;
    virtual IStorageWrite &operator<<(char const *obj) override;

private:
    std::ostream &m_outStream;
};
