#include "ChString.h"

ChString::ChString()
{
}

ChString::ChString(const std::string &value) : data_(value)
{
}

ChString::ChString(const ChString &other) : data_(other.data_)
{
}

ChString::ChString(ChString &&other) noexcept : data_(std::move(other.data_))
{
}

ChString::~ChString()
{
}

ChString &ChString::operator=(const ChString &other)
{
    data_ = other.data_;
    return *this;
}

ChString &ChString::operator=(ChString &&other) noexcept
{
    data_ = std::move(other.data_);
    return *this;
}

ChString::operator std::string &()
{
    return data_;
}

ChString::operator const std::string &() const
{
    return data_;
}
