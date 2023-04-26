#include "ChString.h"

#include <sstream>
#include <cctype>
#include <regex>

ChString::ChString() : data_("")
{
}

ChString::ChString(const std::string &value) : data_(value)
{
}

ChString::ChString(const ChString &other) : data_(other.data_)
{
}

ChString::ChString(const char *str) : data_(str)
{
}

ChString::ChString(size_t size, char ch)
{
    // Resize the internal string to the specified size
    data_.resize(size);

    // Fill the internal string with the specified character
    std::fill(data_.begin(), data_.end(), ch);
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

std::ostream& operator<<(std::ostream& os, const ChString& str) {
    os << str.data_;
    return os;
}

ChString::operator std::string &()
{
    return data_;
}

ChString::operator const std::string &() const
{
    return data_;
}

void ChString::fromNumber(int num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

void ChString::fromNumber(float num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

void ChString::fromNumber(double num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

void ChString::fromNumber(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

void ChString::fromNumber(long num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

void ChString::fromNumber(unsigned long num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

void ChString::fromNumber(long long num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

void ChString::fromNumber(unsigned long long num)
{
    std::stringstream ss;
    ss << num;
    data_ = ss.str();
}

double ChString::toDouble(bool &valid) const
{
    std::string str = data_;

    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    try
    {
        size_t pos = 0;
        double result = std::stod(str, &pos);
        valid = (pos == str.length());
        return result;
    }
    catch (...)
    {
        valid = false;
        return 0.0;
    }
}

int ChString::toInteger(bool &valid) const
{
    std::string str = data_;

    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    try
    {
        size_t pos = 0;
        int result = std::stoi(str, &pos);
        valid = (pos == str.length());
        return result;
    }
    catch (...)
    {
        valid = false;
        return 0;
    }
}

float ChString::toFloat(bool &valid) const
{
    std::string str = data_;

    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    try
    {
        size_t pos = 0;
        float result = std::stof(str, &pos);
        valid = (pos == str.length());
        return result;
    }
    catch (...)
    {
        valid = false;
        return 0.0f;
    }
}

long long ChString::toLongLong(bool &valid) const
{
    std::string str = data_;

    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    try
    {
        size_t pos = 0;
        long long result = std::stoll(str, &pos);
        valid = (pos == str.length());
        return result;
    }
    catch (...)
    {
        valid = false;
        return 0;
    }
}

unsigned int ChString::toUnsignedInteger(bool &valid) const
{
    std::string str = data_;

    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    try
    {
        size_t pos;
        unsigned int result = std::stoul(str, &pos);
        valid = pos == str.length();
        return result;
    }
    catch (...)
    {
        valid = false;
        return 0;
    }
}

unsigned long ChString::toUnsignedLong(bool &valid) const
{
    std::string str = data_;

    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    try
    {
        size_t pos;
        unsigned long result = std::stoul(str, &pos);
        valid = pos == str.length();
        return result;
    }
    catch (...)
    {
        valid = false;
        return 0;
    }
}

unsigned long long ChString::toUnsignedLongLong(bool &valid) const
{
    std::string str = data_;

    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    try
    {
        size_t pos;
        unsigned long long result = std::stoull(str, &pos);
        valid = pos == str.length();
        return result;
    }
    catch (...)
    {
        valid = false;
        return 0;
    }
}

ChString ChString::concat(const ChString &str) const
{
    return ChString(data_ + str.getData());
}

ChString ChString::concat(const std::string &str) const
{
    return ChString(data_ + str);
}

ChString ChString::substring(int start, int size) const
{
    size_t size_ = static_cast<size_t>(size);
    size_t start_ = static_cast<size_t>(start);

    if (size_ == 0)
    {
        size_ = data_.length() - start_;
    }

    return ChString(data_.substr(start_, size_));
}

ChString ChString::removeExtraSpaces()
{
    return ChString(std::regex_replace(data_, std::regex("^ +| +$|( ) +"), "$1"));
}

ChString ChString::removeLeadingSpaces()
{
    return ChString(std::regex_replace(data_, std::regex("^ +"), ""));
}

ChString ChString::removeTrailingSpaces()
{
    return ChString(std::regex_replace(data_, std::regex(" +$"), ""));
}

ChString ChString::removeTrailingAndLeadingSpaces()
{
    std::string lsr = std::regex_replace(data_, std::regex("^ +"), "");

    return ChString(std::regex_replace(lsr, std::regex(" +$"), ""));
}

ChString ChString::removeAll(char delim)
{
    std::string value = data_;

    value.erase(std::remove(value.begin(), value.end(), delim), value.end());

    return ChString(value);
}

ChString ChString::removeFirst(ChString str) const
{
    size_t pos = data_.find(str.data_);
    if (pos == std::string::npos)
    {
        return *this;
    }
    ChString result(data_);
    result.data_.erase(pos, str.size());
    return result;
}

ChString ChString::removeFirst(std::string str) const
{
    ChString chStr(str);
    return removeFirst(chStr);
}

ChString ChString::removeLast(ChString str) const
{
    size_t pos = data_.rfind(str.data_);
    if (pos == std::string::npos)
    {
        return *this;
    }
    ChString result(data_);
    result.data_.erase(pos, str.size());
    return result;
}

ChString ChString::removeLast(std::string str) const
{
    ChString chStr(str);
    return removeLast(chStr);
}

char ChString::first() const
{
    return data_.empty() ? '\0' : data_.front();
}

char ChString::last() const
{
    return data_.empty() ? '\0' : data_.back();
}

char ChString::popFirst()
{
    if (data_.empty())
    {
        return '\0';
    }
    char c = data_.front();
    data_.erase(data_.begin());
    return c;
}

char ChString::popLast()
{
    if (data_.empty())
    {
        return '\0';
    }
    char c = data_.back();
    data_.pop_back();
    return c;
}

bool ChString::contains(const ChString &value, bool isCaseSensitive) const
{
    std::string str = data_;
    std::string subStr = value.getData();
    if (!isCaseSensitive)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
    }
    return str.find(subStr) != std::string::npos;
}

bool ChString::contains(const std::string &value, bool isCaseSensitive) const
{
    std::string str = data_;
    std::string subStr = value;
    if (!isCaseSensitive)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
    }
    return str.find(subStr) != std::string::npos;
}

int ChString::count(const ChString &value, bool isCaseSensitive) const
{
    std::string str = data_;
    std::string subStr = value.getData();
    int count = 0;
    size_t pos = 0;
    if (!isCaseSensitive)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
    }
    while ((pos = str.find(subStr, pos)) != std::string::npos)
    {
        ++count;
        pos += subStr.length();
    }
    return count;
}

int ChString::count(const std::string &value, bool isCaseSensitive) const
{
    std::string str = data_;
    std::string subStr = value;
    int count = 0;
    size_t pos = 0;
    if (!isCaseSensitive)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
    }
    while ((pos = str.find(subStr, pos)) != std::string::npos)
    {
        ++count;
        pos += subStr.length();
    }
    return count;
}

ChString ChString::toLower() const
{
    std::string result = data_;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    return result;
}

ChString ChString::toUpper() const
{
    std::string result = data_;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c)
                   { return std::toupper(c); });
    return result;
}

ChString ChString::capitalize() const
{
    std::string result = data_;
    bool newWord = true;
    for (auto &c : result)
    {
        if (std::isalpha(c))
        {
            if (newWord)
            {
                c = std::toupper(c);
                newWord = false;
            }
        }
        else
        {
            newWord = true;
        }
    }
    return result;
}

bool ChString::beginsWith(const ChString &str) const
{
    return data_.find(str.data_) == 0;
}

bool ChString::beginsWith(const std::string &str) const
{
    return data_.find(str) == 0;
}

bool ChString::beginsWith(char ch) const
{
    if (data_.empty())
    {
        return false;
    }
    return data_.at(0) == ch;
}

bool ChString::endsWith(const ChString &str) const
{
    if (data_.length() < str.data_.length())
    {
        return false;
    }
    return data_.compare(data_.length() - str.data_.length(), str.data_.length(), str.data_) == 0;
}

bool ChString::endsWith(const std::string &str) const
{
    if (data_.length() < str.length())
    {
        return false;
    }
    return data_.compare(data_.length() - str.length(), str.length(), str) == 0;
}

bool ChString::endsWith(char ch) const
{
    if (data_.empty())
    {
        return false;
    }
    return data_.at(data_.length() - 1) == ch;
}

ChString ChString::erase(int first, int last) const
{
    if (static_cast<size_t>(first) >= data_.length() || first > last)
    {
        return ChString("");
    }
    return ChString(data_.substr(0, first) + data_.substr(last + 1));
}

ChString ChString::leftJustified(size_t width, char fill, bool truncate) const
{
    if (data_.size() >= width)
    {
        if (truncate)
        {
            return ChString(data_.substr(0, width));
        }
        else
        {
            return ChString(data_);
        }
    }
    else
    {
        return ChString(data_ + std::string(width - data_.size(), fill));
    }
}

ChString ChString::rightJustified(size_t width, char fill, bool truncate) const
{
    if (data_.size() >= width)
    {
        if (truncate)
        {
            return ChString(data_.substr(data_.size() - width, width));
        }
        else
        {
            return ChString(data_);
        }
    }
    else
    {
        return ChString(std::string(width - data_.size(), fill) + data_);
    }
}

std::list<ChString> ChString::split(const ChString &separator, bool keepEmptyParts, bool caseSensitive) const
{
    std::list<ChString> result;
    size_t pos = 0;
    size_t separatorLength = separator.data_.length();
    std::string data = data_;
    std::string sep = separator.data_;
    while (pos <= data.length() - separatorLength)
    {
        if ((caseSensitive && data.substr(pos, separatorLength) == sep) || (!caseSensitive && ChString(data.substr(pos, separatorLength)).toLower().data_ == separator.toLower().data_))
        {
            result.push_back(data.substr(0, pos));
            data = data.erase(0, pos + separatorLength - 1);
            pos = 0;
        }
        else
        {
            ++pos;
        }
    }
    if (keepEmptyParts || !data.empty())
    {
        result.push_back(*this);
    }
    return result;
}

std::list<ChString> ChString::split(const std::string &separator, bool keepEmptyParts, bool caseSensitive) const
{
    return split(ChString(separator), keepEmptyParts, caseSensitive);
}

std::list<ChString> ChString::split(char separator, bool keepEmptyParts, bool caseSensitive) const
{
    return split(ChString(1, separator), keepEmptyParts, caseSensitive);
}

size_t ChString::size() const
{
    return data_.size();
}

const std::string &ChString::getData() const
{
    return data_;
}
