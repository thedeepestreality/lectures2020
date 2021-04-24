#include "String.h"
#include <cstring>

String::String(const char* str) :  _size(strlen(str) + 1),
                                        _data(new char[_size])
{
    memcpy(_data, str, _size);
}

String::String(size_t size) :   _size(size + 1),
                                _data(new char[_size])
{
    _data[0] = '\0';
}

String::String(String const& str) : String(str.str()) {}

String::String(String&& str) : _size(str._size),
                               _data(str._data)
{
    str._size = 0;
    str._data = nullptr;
}

String::~String()
{
    if (_data)
        delete[] _data;
}

size_t String::size() const
{
    return _size-1;
}

size_t String::length() const
{
    return strlen(_data);
}

const char* String::str() const
{
    return _data;
}

char* String::str()
{
    return _data;
}

char& String::operator[](size_t idx)
{
    return _data[idx];
}

char const& String::operator[](size_t idx) const
{
    return _data[idx];
}

String& String::operator=(String const& str)
{
    if (this != &str)
    {
        if (_data != nullptr)
            delete[] _data;
        _size = strlen(str.str()) + 1;
        _data = new char[_size];
        memcpy(_data, str.str(), _size);
    }
    return *this;
}

String& String::operator=(String&& str)
{
    if (this != &str)
    {
        if (_data != nullptr)
            delete[] _data;
        _size = str._size;
        _data = str._data;
        str._data = nullptr;
        str._size = 0;
    }
    return *this;
}

String& String::operator+=(String const& str)
{
    String tmp(length() + str.length());
    memcpy(tmp._data, _data, length());
    memcpy(tmp._data + length(), str.str(), str.length());
    tmp[length() + str.length()] = '\0';
    return *this = tmp;
}

String operator+(String const& left, String const& right)
{
    return String(left) += right;
}

void String::reserve(size_t size)
{
    if (size + 1 <= _size)
    {
        _size = size + 1;
        _data[size] = '\0';
        return;
    }

    _size = size + 1;
    char* tmp_data = new char[size + 1];
    for (size_t idx = 0; idx < strlen(_data); ++idx)
        tmp_data[idx] = _data[idx];
    tmp_data[strlen(_data)] = '\0';
}

bool operator==(String const& left, String const& right)
{
    return !((left < right) || (right < left));
}

bool operator!=(String const& left, String const& right)
{
    return !(left == right);
}
bool operator<=(String const& left, String const& right)
{
    return !(right > left);
}
bool operator>=(String const& left, String const& right)
{
    return !(right < left);
}

bool operator< (String const& left, String const& right)
{
    return strcmp(left.str(), right.str()) < 0;
}
bool operator> (String const& left, String const& right)
{
    return right < left;
}

std::ostream& operator<<(std::ostream& out, String const& str)
{
    return out << str.str();
}

std::istream& operator>>(std::istream& in, String& str)
{
    static const int buff_size = 128;
    str.reserve(buff_size);
    in.getline(str.str(), buff_size);
    //char buffer[buff_size];
    //in.getline(buffer, buff_size);
    //str = String(buffer);
    return in;
}